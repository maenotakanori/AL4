#include "Player.h"
#include <cassert>
#include "numbers"
#include "math/Vector3.h"

using namespace KamataEngine;

void Player::Initialize(Model* model, Camera* camera, const Vector3& position) {
	assert(model);
	model_ = model;
	//textureHandle_ = textureHandle;
	camera_ = camera;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
	
	objColor.Initialize();

}

void Player::Update() {


	// 行列を更新
	//worldTransform_.TransferMatrix();
}


void Player::Draw() {
	


	// 3Dモデルを描画
	model_->Draw(worldTransform_, *camera_, &objColor);
}