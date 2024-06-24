#include "BackGround.h"
#include <assert.h>
BackGround::BackGround(GameObject* scene):GameObject(scene)
{
	hImage = LoadGraph("Assets/background2.png");
	assert(hImage > 0);
}

BackGround::~BackGround()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}


void BackGround::Update()
{
}

void BackGround::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	DrawRectGraph(x, y, 0, 0, 1280, 720, hImage, TRUE);
}

