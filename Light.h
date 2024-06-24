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
	void SetPosition(int x, int y);
private:
	int hImage;
};

