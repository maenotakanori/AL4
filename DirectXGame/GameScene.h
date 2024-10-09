#pragma once

#include <KamataEngine.h>
#include "Player.h"

using namespace KamataEngine;


class GameScene {

public:
	GameScene();
	~GameScene();
	void Initialize();
	void Update();
	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	uint32_t textureHandle_ = 0;
	Model* model_ = nullptr;
	WorldTransform worldTransform_;
	Camera camera_;

	Player* player_ = nullptr;

	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;
	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;

};