#pragma once
#include "Engine/GameObject.h"
class GameOverScene :
    public GameObject
{
public:

	GameOverScene(GameObject* parent);

	~GameOverScene();

	void Update() override;

	void Draw() override;
private:
	int hImage;
	int BlendAlpha;
};

