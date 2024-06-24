#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// �X���C���i�G�j
/// </summary>
class Slime : public GameObject
{
public:
	Slime(GameObject* scene);
	~Slime();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool ColliderCircle(float x, float y, float r);
private:
	int hImage;
};
