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
	// �����x��ς��ĈÂ��𒲐�����ꍇ
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150); // 150�͓����x�̒l�i0����255�͈̔́j
	DrawBox(0, 0, ScreenWidth, ScreenHeight, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h�����ɖ߂�
}

void Vision::Draw()
{
}
