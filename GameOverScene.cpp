#include "GameOverScene.h"
#include"TestScene.h"
#include"Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent) :GameObject(parent, "SceneManager")
{
	hImage = LoadGraph("Assets/GameOver.png");
	assert(hImage > 0);
	BlendAlpha = 0;
}

GameOverScene::~GameOverScene()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void GameOverScene::Update()
{
	BlendAlpha++;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendAlpha);	
	if (BlendAlpha == 255)
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		//DrawString(32, 32, "Cキーでコンティニュー", GetColor(255, 255, 255));
	}
	if (CheckHitKey(KEY_INPUT_C))
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_TEST);
	}
}

void GameOverScene::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	DrawRectGraph(x, y, 0, 0, 1280, 720, hImage, TRUE);
}
