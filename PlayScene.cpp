#include "PlayScene.h"
#include"UI.h"
#include"BackGround.h"
#include"Camera.h"
#include "Player.h"
#include "Slime.h"
#include "Field.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
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

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
	
}

//�J��
void PlayScene::Release()
{
}
