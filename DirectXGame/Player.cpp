#include "Player.h"
#include <cassert>
#include "numbers"
#include "math/Vector3.h"
#include <2d\ImGuiManager.h>
#include <algorithm>
//#include <math\MathUtility.h>

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
	input_ = Input::GetInstance();

}

void Player::Update() {
	// キャラクターの移動ベクトル
	Vector3 move = { 0,0,0 };
	// キャラクターの移動速度
	const float kCharacterSpeed = 1.0f;
	// 押した方向で移動ベクトルを変更（左右）
	if (input_->PushKey(DIK_LEFT)) {
		move.x -= kCharacterSpeed;
	}
	else if (input_->PushKey(DIK_RIGHT)) {
		move.x += kCharacterSpeed;
	}
	// 押した方向で移動ベクトルを変更（上下）
	if (input_->PushKey(DIK_UP)) {
		move.y += kCharacterSpeed;
	}
	else if (input_->PushKey(DIK_DOWN)) {
		move.y -= kCharacterSpeed;
	}

	move *= kCharacterSpeed;

	// 座標移動（ベクトルの加算）
	worldTransform_.translation_ += move;
	
	// 移動限界座標
	worldTransform_.translation_.x = std::clamp(worldTransform_.translation_.x, -35.0f, 35.0f);
	worldTransform_.translation_.y = std::clamp(worldTransform_.translation_.y, -20.0f, 20.0f);

	// 行列を更新
	worldTransform_.UpdateMatrix();

	ImGui::SetWindowSize(ImVec2(200, 100));
	ImGui::Begin("PlayerInfo");
	ImGui::DragFloat2("Postiton", &worldTransform_.translation_.x);
	ImGui::End();

}


void Player::Draw() {
	


	// 3Dモデルを描画
	model_->Draw(worldTransform_, *camera_, &objColor);
}