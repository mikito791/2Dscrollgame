#include "PlayScene.h"
#include"UI.h"
#include"BackGround.h"
#include"Camera.h"
#include "Player.h"
#include "Slime.h"
#include "Field.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	
	Instantiate<BackGround>(this);
	Instantiate<Camera>(this);
	Field* pField = Instantiate<Field>(this);
	//Instantiate<Slime>(this);
	Instantiate<Player>(this);
	pField->Reset();
	Instantiate<UI>(this);
	//Instantiate<Bird>(this);
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
	
}

//開放
void PlayScene::Release()
{
}
