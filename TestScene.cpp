#include "TestScene.h"
#include"BackGround.h"
#include"Camera.h"
#include "Player.h"
#include "Slime.h"
#include "Field.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Instantiate<BackGround>(this);
	Instantiate<Camera>(this);
	Field* pField = Instantiate<Field>(this);
	//Instantiate<Slime>(this);
	Instantiate<Player>(this);
	pField->Reset();
	//Instantiate<Bird>(this);
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
