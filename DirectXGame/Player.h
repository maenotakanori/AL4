#pragma once

#include <3d\Model.h>
#include <3d\WorldTransform.h>
#include <3d\Camera.h>
#include <math\MathUtility.h>
#include <input\Input.h>

//#include <KamataEngine.h>
//using namespace KamataEngine;

namespace KamataEngine {
	class Input;
}

class Player {

	//Vector3 move;

public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* viewProjection, const KamataEngine::Vector3& position);
	void Update();
	void Draw();

private:
	KamataEngine::WorldTransform worldTransform_ = {};
	KamataEngine::Camera* camera_ = nullptr;
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::ObjectColor objColor = {};
	
	// キーボード入力
	KamataEngine::Input* input_ = nullptr;

};