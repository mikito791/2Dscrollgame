#include "Slime.h"
#include <assert.h>
#include"Camera.h"
#include"Field.h"
#include"Player.h"
namespace {
	static const int SCREEN_WIDTH = 1280;
	const float GRAVITY = 48.0f / 60.0f;
}
Slime::Slime(GameObject* scene)
{
	hImage = LoadGraph("Assets/slime_run1.png");
	assert(hImage > 0);
	/*transform_.position_.x = 800.0f;
	transform_.position_.y = 500.0f;*/
	frameCounter = 0;
	animType = 0;
	animFrame = 0;
}

Slime::~Slime()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void Slime::Update()
{
	Field* pField = GetParent()->FindGameObject<Field>();
	int x = (int)transform_.position_.x;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	if (x > SCREEN_WIDTH)//即値、マジックナンバー
		return;
	else if (x < -SCREEN_WIDTH)
	{
		KillMe();
		return;
	}
	transform_.position_.y += GRAVITY;
	
	if (pField != nullptr)
	{
		int pushR = pField->CollisionDown(transform_.position_.x+50, transform_.position_.y+42);
		int pushL = pField->CollisionDown(transform_.position_.x+14, transform_.position_.y+42);
		//int pushR = pField->CollisionDown(transform_.position_.x + 50, transform_.position_.y + 63);
		//int pushL = pField->CollisionDown(transform_.position_.x + 14, transform_.position_.y + 63);
		int push = max(pushR, pushL);//２つの足元のめりこみの大きいほう
		if (push >= 1) 
		{
			transform_.position_.y -= push;
			transform_.position_.x -= 0.5f;
			if (transform_.position_.y == 450)
			{
				KillMe();
			}
			if (++frameCounter >= 6) {
				animFrame = (animFrame + 1) % 3;
				frameCounter = 0;
			}
		}
	}
	int pushEnd = pField->IsLeftEnd(transform_.position_.x + 50, transform_.position_.y + 42);
	if (pushEnd >= 1)
	{
		KillMe();
	}

}

void Slime::Draw()
{
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 40); 
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	DrawRectGraph(x, y, animFrame*64, 0, 64, 64,hImage,TRUE,TRUE);
	//DrawCircle(x + 36.0f, y + 32.0f, 20.0f, GetColor(255, 0, 0), 0);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100); // 透明度を設定 (0-255)
	//DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), TRUE); // 画面全体に黒い四角形を描画
	// 透明度を設定 (0-255)
	
}

void Slime::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

//当たり判定
bool Slime::SColliderCircle(float x, float y, float r)
{
	//x,y,rが相手の円の情報
	//自分の円の情報
	float myCenterX = transform_.position_.x + 36.0f;
	float myCenterY = transform_.position_.y + 32.0f;
	float dx = myCenterX - x;
	float dy = myCenterY - y;
	float dSqrts = dx * dx + dy * dy;
	//float dSqrts =sqrt(dx * dx + dy * dy);

	float myR = 20.0f+r;
	float rSqrt = myR * myR;
	//float rSqrt = sqrt(myR * myR);
	if (dSqrts <= rSqrt)
	{
		return true;
	}
	else
	{
		return false;
	}
}

