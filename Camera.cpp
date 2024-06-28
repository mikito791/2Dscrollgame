#include "Camera.h"

namespace
{
    const int RIGHT_MOVE_CAMERA = 1200; // �E�ɓ���̈ʒu�ɒ������瓮��
    //const int LEFT_MOVE_CAMERA = -600; // ���ɓ���̈ʒu�ɒ������瓮��
}

void Camera::Update()
{
    if (pPlayer)
    {
        float PCamera = pPlayer->GetPosition().x;

        if (PCamera > RIGHT_MOVE_CAMERA / 2)
        {
            value = PCamera - RIGHT_MOVE_CAMERA / 2;
        }
    }
}
void Camera::DrawDarkOverlay()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50); // �����x��ݒ� (0-255)
    DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), TRUE); // ��ʑS�̂ɍ����l�p�`��`��
    //if (CheckHitKey(KEY_INPUT_W))
    //{
    //    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
    //    //SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h�����ɖ߂�
    //}
}