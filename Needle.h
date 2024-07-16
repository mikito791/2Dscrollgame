#pragma once
#include "Engine/GameObject.h"
class Needle :
    public GameObject
{
public:
	Needle(GameObject* scene);
	~Needle();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool NColliderRect(float x, float y, float w,float h);
	bool NColliderCircle(float x, float y, float r);
private:
	int hImage;

};

