#include "Player.h"
#include <DxLib.h>
#include <assert.h>
#include"Field.h"
#include"Slime.h"
#include"Light.h"
#include"Camera.h"
#include"Engine/SceneManager.h"
namespace
{
	const float MOVE_SPEED = 10.0f;
	const float GROUND = 400.0f;
	const float JUMP_HEIGHT = 48.0f * 4.0f;//ジャンプの高さ
	const float GRAVITY = 50.8f / 60.0f;//重力加速度
	/*Memo const float JUMP = -12.0f;
	const float GRAVITY = 0.5f;
	XMFLOAT3 JumpSpeed{ 0,0,0 };*/
}
Player::Player(GameObject* parent) : GameObject(sceneTop)
{
	hImage = LoadGraph("Assets/aoi.png");
	assert(hImage > 0);
	transform_.position_.x = 10.0f;
	transform_.position_.y = GROUND;
	jumpSpeed = 0.0f;
	onGround = true;
	prevSpaceKey = false;
	prevLightSkey = false;
}

Player::~Player()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void Player::Update()
{
	Field* pField = GetParent()->FindGameObject<Field>();
	Camera* cam = GetParent()->FindGameObject<Camera>();
	cam->DrawDarkOverlay();
	//移動
	if (CheckHitKey(KEY_INPUT_D))
	{
		transform_.position_.x += MOVE_SPEED;
		int hitX = transform_.position_.x + 50;
		int hitY = transform_.position_.y + 63;
		if (pField != nullptr)
		{
			int push = pField->CollisionRight(hitX, hitY);
			transform_.position_.x -= push;
		}
	}
	else if (CheckHitKey(KEY_INPUT_A))
	{
		transform_.position_.x -= MOVE_SPEED;
	}
	//ジャンプ
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (prevSpaceKey == false) {
			if (onGround) {
				jumpSpeed = -sqrt(2 * GRAVITY * JUMP_HEIGHT);
				onGround = false;
			}
		}
		prevSpaceKey = true;
	}
	else
	{
		prevSpaceKey = false;
	}
	jumpSpeed += GRAVITY;//速度　+= 加速度
	transform_.position_.y += jumpSpeed;//座標　+=　速度
	if (pField != nullptr)
	{
		int pushR = pField->CollisionDown(transform_.position_.x + 50, transform_.position_.y + 63);
		int pushL = pField->CollisionDown(transform_.position_.x + 14, transform_.position_.y + 63);
		int push = max(pushR, pushL);//２つの足元のめりこみの大きいほう
		if (push >= 1) 
		{
			transform_.position_.y -= push - 1;
			jumpSpeed = 0.0f;
			onGround = true;
		}
		else
		{
			onGround = false;
		}
	}
	if (transform_.position_.y >= 800)
	{
		KillMe();
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_GAMEOVER);
	}
	//ライト
	
	if (CheckHitKey(KEY_INPUT_S))
	{
		if (prevLightSkey)
		{
			Light* li = Instantiate<Light>(GetParent());
			li->SetPosition(transform_.position_);
		}
		prevLightSkey = true;
	}
	else
	{
		prevLightSkey = false;
	}
	//当たり判定
	std::list<Slime*> pSlimes = GetParent()->FindGameObjects<Slime>();
	for (Slime* pSlime : pSlimes)
	{
		if (pSlime->ColliderCircle(transform_.position_.x+32.0f, transform_.position_.y+32.0f , 20.0f))
		{
			//当たった処理
			KillMe();
			SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
			pSM->ChangeScene(SCENE_ID::SCENE_ID_GAMEOVER);
		}
	}
	//カメラ
	//wCamera* cam = GetParent()->FindGameObject<Camera>();
	int x = (int)transform_.position_.x - cam->GetValue();
	if (x > 400)
	{
		x = 400;
		cam->SetValue((int)transform_.position_.x - x);
	}
	/*if (cam != nullptr) {
		cam->GetPlayerPos(this);
	}*/
}

void Player::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage, TRUE);
	//↓後で消す
	DrawCircle(x + 32.0f, y + 32.0f, 50.0f, GetColor(0, 0, 0), 0);//見える範囲
	DrawCircle(x + 32.0f, y + 32.0f, 20.0f, GetColor(255, 0, 0), 0);//当たり判定
}

void Player::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}