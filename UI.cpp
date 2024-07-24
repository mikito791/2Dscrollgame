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
	DrawFormatString(0, 5, GetColor(0, 0, 0), "今は動けないよ");
	DrawFormatString(0, 25, GetColor(255, 255, 255), "Aキーで←");
	DrawFormatString(0, 45, GetColor(255, 255, 255), "Dキーで→");
	DrawFormatString(0, 65, GetColor(255, 255, 255), "SPACEキーでJUMP");
	DrawFormatString(0, 85, GetColor(255, 255, 255), "WキーでLIGHT");
	DrawFormatString(0, 105, GetColor(255, 255, 255), "Cキーでコンティニュー");
	
}

void UI::Release()
{
}
