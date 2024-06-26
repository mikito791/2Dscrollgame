#pragma once
#include "Engine/GameObject.h"
class Vision :
    public GameObject
{
public:
	Vision(GameObject* scene);
	~Vision();
	void Update() override;
	void Draw() override;
private:
	int ScreenWidth;
	int ScreenHeight;
};

