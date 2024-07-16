#include "Needle.h"
#include"Camera.h"

Needle::Needle(GameObject* scene)
{
    hImage = LoadGraph("Assets/Needle.png");
    assert(hImage > 0);
}

Needle::~Needle()
{
    if (hImage > 0)
    {
        DeleteGraph(hImage);
    }
}

void Needle::Update()
{
    int x = (int)transform_.position_.x;
    Camera* cam = GetParent()->FindGameObject<Camera>();
    if (cam != nullptr)
    {
        x -= cam->GetValue();
    }
    cam->DrawDarkOverlay();
}

void Needle::Draw()
{
    int x = (int)transform_.position_.x ;
    int y = (int)transform_.position_.y +32;
    Camera* cam = GetParent()->FindGameObject<Camera>();
    if (cam != nullptr)
    {
        x -= cam->GetValue();
    }
    DrawGraph(x, y, hImage, TRUE);
    float myX = transform_.position_.x;
    float myY = transform_.position_.y+48;
    float myWidth = myX + 32;
    float myHeight = myY + 16;
    //DrawBox(myX, myY, myWidth, myHeight, GetColor(255, 0, 0), 0);
    DrawCircle(myX+16,myY +16, 20, GetColor(255, 0, 0), 0);
}

void Needle::SetPosition(int x, int y)
{
    transform_.position_.x = x;
    transform_.position_.y = y;
}

bool Needle::NColliderRect(float x, float y, float w, float h)
{
    //↓自分の情報
    float myLeft = transform_.position_.x;
    float myTop = transform_.position_.y + 48; // y軸方向に64ピクセル下がった位置が上端
    float myRight = myLeft + 32; // x軸方向に32ピクセル右に広がる位置が右端
    float myBottom = myTop+16; // 上端から48ピクセル下がった位置が下端

    // 相手の情報
    float yLeft = x;
    float yTop = y;
    float yRight = x + w;
    float yBottom = y + h;

    // 当たり判定の条件
    if (myRight >= yLeft &&   // 自分の右端が相手の左端以上
        myLeft <= yRight &&   // 自分の左端が相手の右端以下
        myBottom >= yTop &&   // 自分の下端が相手の上端以上
        myTop <= yBottom) {   // 自分の上端が相手の下端以下
        return true;  // 重なっている場合
    }
    return false;  // 重なっていない場合
}

bool Needle::NColliderCircle(float x, float y, float r)
{
    //x,y,rが相手の円の情報
    //自分の円の情報
    float myCenterX = transform_.position_.x + 16.0f;
    float myCenterY = transform_.position_.y + 64.0f;
    float dx = myCenterX - x;
    float dy = myCenterY - y;
    float dSqrts = dx * dx + dy * dy;
    //float dSqrts =sqrt(dx * dx + dy * dy);

    float myR = 20.0f + r;
    float rSqrt = myR * myR;
    //float rSqrt = sqrt(myR * myR);
    if (dSqrts <= rSqrt)
    {
        return true;
    }
    else
    {
        return false;
    }
}


