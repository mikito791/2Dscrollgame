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
	int GoalCount;
	int SoundJump;
	int animType;//状況
	int animFrame;//コマ
	int frameCounter;
	int GameOverSound;
	int GameClearSound;
	int RunSound;
};