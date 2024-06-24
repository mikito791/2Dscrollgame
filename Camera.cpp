#include "Camera.h"

namespace
{
    const int RIGHT_MOVE_CAMERA = 1200; // ‰E‚É“Á’è‚ÌˆÊ’u‚É’…‚¢‚½‚ç“®‚­
    //const int LEFT_MOVE_CAMERA = -600; // ¶‚É“Á’è‚ÌˆÊ’u‚É’…‚¢‚½‚ç“®‚­
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