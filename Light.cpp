#include "Light.h"
#include"Camera.h"

Light::Light(GameObject* scene)
{
	hImage = LoadGraph("Assets/light.png");
	assert(hImage > 0);
}

Light::~Light()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
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
	int x = (int)transform_.position_.x+40;
	int y = (int)transform_.position_.y+30;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	DrawGraph(x, y, hImage, TRUE);
}

void Light::SetPosition(XMFLOAT3 pos)
{
	transform_.position_ = pos;
	timer = 30;
}
