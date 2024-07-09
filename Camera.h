#pragma once
#include"Player.h"
#include"Engine/GameObject.h"
class Camera : public GameObject
{
public:
	Camera(GameObject* parent) :GameObject(parent) { value = 0, OnField = true; }
	~Camera() {}
	//void GetPlayerPos(Player* _player) { pPlayer = _player; }
	//void Update() override;
	void SetValue(int v) { value = v; }
	int GetValue() { return value; }
	void DrawDarkOverlay();
	/*void SetResetCamPos(int c) { camPos = c; }
	void ResetCamera() { value = camPos; }*/
private:
	bool OnField;
	int value;
	//int camPos;
};