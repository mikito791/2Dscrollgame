#include "Camera.h"

namespace
{
    const int RIGHT_MOVE_CAMERA = 1200; // 右に特定の位置に着いたら動く
    //const int LEFT_MOVE_CAMERA = -600; // 左に特定の位置に着いたら動く
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