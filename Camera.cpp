#include "Camera.h"

void Camera::DrawDarkOverlay()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100); // �����x��ݒ� (0-255)
    DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), TRUE); // ��ʑS�̂ɍ����l�p�`��`��
    if (CheckHitKey(KEY_INPUT_W))
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 175);
        //SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h�����ɖ߂�
    }
}