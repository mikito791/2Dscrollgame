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
    //cam->DrawDarkOverlay();
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

    //DrawBox(x, y+32, x+32, y+16, GetColor(255, 0, 0), 0);

    //DrawCircle(x+16, y+32, 17, GetColor(255, 0, 0), 0);
}

void Needle::SetPosition(int x, int y)
{
    transform_.position_.x = x;
    transform_.position_.y = y;
}

bool Needle::NColliderRect(float x, float y, float w, float h)
{
    //�������̏��
    float myLeft = transform_.position_.x;
    float myTop = transform_.position_.y + 64; // y��������64�s�N�Z�����������ʒu����[
    float myRight = transform_.position_.x + 32; // x��������32�s�N�Z���E�ɍL����ʒu���E�[
    float myBottom = transform_.position_.x+64+16; // ��[����48�s�N�Z�����������ʒu�����[

    // ����̏��
    float yLeft = x;
    float yTop = y;
    float yRight = x + w;
    float yBottom = y + h;

    // �����蔻��̏���
    if (myRight >= yLeft &&   // �����̉E�[������̍��[�ȏ�
        myLeft <= yRight &&   // �����̍��[������̉E�[�ȉ�
        myBottom >= yTop &&   // �����̉��[������̏�[�ȏ�
        myTop <= yBottom) {   // �����̏�[������̉��[�ȉ�
        return true;  // �d�Ȃ��Ă���ꍇ
    }
    return false;  // �d�Ȃ��Ă��Ȃ��ꍇ
}

bool Needle::NColliderCircle(float x, float y, float r)
{
    //x,y,r������̉~�̏��
    //�����̉~�̏��
    float myCenterX = transform_.position_.x + 16.0f;
    float myCenterY = transform_.position_.y + 64.0f;
    float dx = myCenterX - x;
    float dy = myCenterY - y;
    float dSqrts = dx * dx + dy * dy;
    //float dSqrts =sqrt(dx * dx + dy * dy);

    float myR = 17.0f + r;
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


