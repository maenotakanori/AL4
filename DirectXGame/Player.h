#pragma once

#include <3d\Model.h>
#include <3d\WorldTransform.h>
#include <3d\Camera.h>
#include <math\MathUtility.h>
#include <input\Input.h>


//#include <KamataEngine.h>
using namespace KamataEngine;

class Player {
public:
	void Initialize(Model* model, Camera* viewProjection, const Vector3& position);
	void Update();
	void Draw();

private:
	WorldTransform worldTransform_ = {};
	Camera* camera_ = nullptr;
	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;
	ObjectColor objColor = {};

};