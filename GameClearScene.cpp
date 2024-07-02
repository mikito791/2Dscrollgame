#include "GameClearScene.h"
#include"Engine/SceneManager.h"

GameClearScene::GameClearScene(GameObject* parent) :GameObject(parent, "GamoClear")
{
	hImage = LoadGraph("Assets/GameClear.png");
	assert(hImage > 0);
}

GameClearScene::~GameClearScene()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void GameClearScene::Update()
{
	if (CheckHitKey(KEY_INPUT_C))
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_PLAY);
	}
}

void GameClearScene::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	DrawRectGraph(x, y, 0, 0, 1280, 720, hImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
