#pragma once
#include "Engine/GameObject.h"
class GameClearScene :
    public GameObject
{
public:
	GameClearScene(GameObject* parent);

	~GameClearScene();

	void Update() override;

	void Draw() override;
private:
	int hImage;
};

