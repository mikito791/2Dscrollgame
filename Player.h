#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// �v���C���[�L����
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
	int animType;//��
	int animFrame;//�R�}
	int frameCounter;
	int GameOverSound;
	int GameClearSound;
	int RunSound;
};