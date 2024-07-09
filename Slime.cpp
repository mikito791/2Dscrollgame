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
	hImage = LoadGraph("Assets/slime.png");
	assert(hImage > 0);
	/*transform_.position_.x = 800.0f;
	transform_.position_.y = 500.0f;*/
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
	cam->DrawDarkOverlay();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	if (x > SCREEN_WIDTH)//���l�A�}�W�b�N�i���o�[
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
		int push = max(pushR, pushL);//�Q�̑����̂߂肱�݂̑傫���ق�
		if (push >= 1) 
		{
			transform_.position_.y -= push;
			transform_.position_.x -= 0.5f;
			int pushEnd = pField->IsLeftEnd(transform_.position_.x + 50, transform_.position_.y + 42);
			if (pushEnd >= 1)
			{
				KillMe();
			}
		}
	}
	
}

void Slime::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	DrawRectGraph(x, y, 0, 0, 64, 64,hImage,TRUE,TRUE);
	//DrawCircle(x + 32.0f, y + 32.0f, 20.0f, GetColor(255, 0, 0), 0);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100); // �����x��ݒ� (0-255)
	//DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), TRUE); // ��ʑS�̂ɍ����l�p�`��`��
	
}

void Slime::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

//�����蔻��
bool Slime::SColliderCircle(float x, float y, float r)
{
	//x,y,r������̉~�̏��
	//�����̉~�̏��
	float myCenterX = transform_.position_.x + 32.0f;
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

