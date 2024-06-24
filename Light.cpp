#include "Light.h"
#include"Camera.h"
Light::Light(GameObject* scene)
{
	//hImage=LoadGraph("Assets/")
	assert(hImage > 0);
	transform_.position_.x = 10.0f;
	transform_.position_.y = 400.0;
}

Light::~Light()
{
}

void Light::Update()
{
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
	//DrawRectGraph(x, y, 0, 0, 64, 64, hImage, TRUE);
}

void Light::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}
