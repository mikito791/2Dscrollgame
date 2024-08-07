#pragma once
#include "Engine/GameObject.h"
#include"Player.h"
#include"Slime.h"
#include"Needle.h"

/// <summary>
/// 地面（プレイフィールド）
/// </summary>
class Field : public GameObject
{
public:
	Field(GameObject* scene);
	~Field();
	void Reset();
	void DifficlutStageSet();
	void Update() override;
	void Draw() override;
	/// <summary>
	/// 右側の点が当たっているか調べる
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <returns>めり込んだ量（ドット）</returns>
	int CollisionRight(int x, int y);
	int CollisionLeft(int x, int y);
	/// <summary>
	/// 下の点に当たっているか調べる
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <returns>めり込んだ量（ドット）</returns>
	int CollisionDown(int x, int y);
	int CollisionUp(int x, int y);
	bool IsGoal(int x, int y);
	bool IsLeftEnd(int x, int y);
private:
	int hImage;
	bool IsWallBlock(int x, int y);
	int* Map;
	int height;
	int width;
	int mapnum;
	//Player* pPlayer;
	Slime* pSlime;
	//Needle* pNeedle;
};
