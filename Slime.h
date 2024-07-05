#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// スライム（敵）
/// </summary>
class Slime : public GameObject
{
public:
	Slime(GameObject* scene);
	~Slime();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool SColliderCircle(float x, float y, float r);
private:
	int hImage;
};
