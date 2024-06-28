#include "Player.h"
#include <DxLib.h>
#include <assert.h>
#include"Field.h"
#include"Slime.h"
#include"Camera.h"
#include"Engine/SceneManager.h"
namespace
{
	const float MOVE_SPEED = 5.0f;
	const float GROUND = 400.0f;
	const float JUMP_HEIGHT = 64.0f * 4.0f;//�W�����v�̍���
	const float GRAVITY = 40.0f / 60.0f;//�d�͉����x
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
	//�ړ�
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
	//�W�����v
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
	jumpSpeed += GRAVITY;//���x�@+= �����x
	transform_.position_.y += jumpSpeed;//���W�@+=�@���x
	if (pField != nullptr)
	{
		int pushR = pField->CollisionDown(transform_.position_.x + 50, transform_.position_.y + 63);
		int pushL = pField->CollisionDown(transform_.position_.x + 14, transform_.position_.y + 63);
		int push = max(pushR, pushL);//�Q�̑����̂߂肱�݂̑傫���ق�
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
	//�����蔻��
	std::list<Slime*> pSlimes = GetParent()->FindGameObjects<Slime>();
	for (Slime* pSlime : pSlimes)
	{
		if (pSlime->ColliderCircle(transform_.position_.x+32.0f, transform_.position_.y+32.0f , 20.0f))
		{
			//������������
			KillMe();
			SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
			pSM->ChangeScene(SCENE_ID::SCENE_ID_GAMEOVER);
		}
	}
	//�J����
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
	if (CheckHitKey(KEY_INPUT_W))
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h�����ɖ߂�

	}
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
	//����ŏ���
	//DrawCircle(x + 32.0f, y + 32.0f, 50.0f, GetColor(0, 0, 0), 0);//������͈�
	//DrawCircle(x + 32.0f, y + 32.0f, 20.0f, GetColor(255, 0, 0), 0);//�����蔻��
}

void Player::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}