#pragma once
#include "Engine/GameObject.h"
class BackGround :public GameObject
{
public:
	BackGround(GameObject* scene);
	~BackGround();
	void Update() override;
	void Draw() override;
private:
	int hImage[2];
};

