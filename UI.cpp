#include "UI.h"
#include"Engine/SceneManager.h"

UI::UI(GameObject* parent)
{
}

void UI::Initialize()
{
}

void UI::Update()
{
}

void UI::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawFormatString(0, 5, GetColor(0, 0, 0), "���͓����Ȃ���");
	DrawFormatString(0, 25, GetColor(255, 255, 255), "A�L�[�Ł�");
	DrawFormatString(0, 45, GetColor(255, 255, 255), "D�L�[�Ł�");
	DrawFormatString(0, 65, GetColor(255, 255, 255), "SPACE�L�[��JUMP");
	DrawFormatString(0, 85, GetColor(255, 255, 255), "W�L�[��LIGHT");
	DrawFormatString(0, 105, GetColor(255, 255, 255), "C�L�[�ŃR���e�B�j���[");
	
}

void UI::Release()
{
}
