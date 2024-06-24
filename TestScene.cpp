#include "TestScene.h"
#include"BackGround.h"
#include"Camera.h"
#include "Player.h"
#include "Slime.h"
#include "Field.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
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

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}
