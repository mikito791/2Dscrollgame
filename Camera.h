#pragma once
#include"Player.h"
#include"Engine/GameObject.h"
class Camera : public GameObject
{
public:
	Camera(GameObject* parent) :GameObject(parent) { value = 0; }
	~Camera() {}
	void GetPlayerPos(Player* _player) { pPlayer = _player; }
	void Update() override;
	void SetValue(int v) { value = v; }
	int GetValue() { return value; }
private:
	Player* pPlayer;
	int value;
};