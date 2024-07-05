#include "TitleScene.h"
#include"Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
{
	hImage = LoadGraph("Assets/TitleScene1.png");
	assert(hImage > 0);
}

TitleScene::~TitleScene()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_S))
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	DrawRectGraph(x, y, 0, 0, 1280, 720, hImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
