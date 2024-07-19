#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// プレイヤーキャラ
/// </summary>
class Player : public GameObject
{
public:
	Player(GameObject* scene);
	~Player();
	void CamReset();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	//bool PColliderCircle(float x, float y, float r);
private:
	int hImage;
	GameObject* sceneTop;
	bool prevSpaceKey;
	float jumpSpeed;
	bool onGround;
	//int HImage;
	enum State
	{
		S_PLAY = 0,
		S_GOAL,
	};
	State state;
};