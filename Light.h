#pragma once
#include "Engine/GameObject.h"
class Light :
    public GameObject
{
public:
	Light(GameObject* scene);
	~Light();
	void Update() override;
	void Draw() override;
	void SetPosition(XMFLOAT3 pos);
private:
	int hImage;
	int timer;
};

