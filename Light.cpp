#include "Light.h"
#include"Camera.h"
Light::Light(GameObject* scene)
{
	hImage = LoadGraph("Assets/stone.png");
	assert(hImage > 0);

}

Light::~Light()
{
}

void Light::Update()
{
	if (--timer <= 0)
	{
		KillMe();
	}
}

void Light::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage, TRUE);
}

void Light::SetPosition(XMFLOAT3 pos)
{
	transform_.position_ = pos;	
	timer = 90;
}
