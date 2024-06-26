#include "Vision.h"

Vision::Vision(GameObject* scene)
{
	ScreenWidth = 1280;
	ScreenHeight = 720;
}

Vision::~Vision()
{
}

void Vision::Update()
{
	// 透明度を変えて暗さを調整する場合
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150); // 150は透明度の値（0から255の範囲）
	DrawBox(0, 0, ScreenWidth, ScreenHeight, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを元に戻す
}

void Vision::Draw()
{
}
