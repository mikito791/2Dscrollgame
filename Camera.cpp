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