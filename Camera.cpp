#include "Camera.h"


void Camera::DrawDarkOverlay()
{   
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 20); // 透明度を設定 (0-255)
    DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), TRUE); // 画面全体に黒い四角形を描画
    if (CheckHitKey(KEY_INPUT_W))
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
    }
}
