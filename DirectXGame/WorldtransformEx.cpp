#include "math/MathUtility.h"
#include "3d/WorldTransform.h"
#include <cmath>
#include <numbers>

using namespace KamataEngine;

Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 result = {};
	float cos = std::cos(radian);
	float sin = std::sin(radian);
	result = {
		{{1, 0, 0, 0},
		 {0, cos, sin, 0},
		 {
			 0,
			 -sin,
			 cos,
			 0,
		 }, {0, 0, 0, 1}}
	};
	return result;
};

Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 result = {};
	float cos = std::cos(radian);
	float sin = std::sin(radian);
	result = {
		{{cos, 0, -sin, 0},
		 {0, 1, 0, 0},
		 {
			 sin,
			 0,
			 cos,
			 0,
		 }, {0, 0, 0, 1}}
	};
	return result;
};

Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 result = {};
	float cos = std::cos(radian);
	float sin = std::sin(radian);
	result = {
		{{cos, sin, 0, 0}, {-sin, cos, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}
	};
	return result;
};

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}
	return result;
};

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 result = {};

	Matrix4x4 rotateX = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateY = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZ = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateXYZ = Multiply(Multiply(rotateX, rotateY), rotateZ);
	Matrix4x4 Sclae = {
		{{scale.x, 0, 0, 0}, {0, scale.y, 0, 0}, {0, 0, scale.z, 0}, {0, 0, 0, 1}}
	};
	Matrix4x4 Translate{
		{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {translate.x, translate.y, translate.z, 1}}
	};

	result = Multiply(Multiply(Sclae, rotateXYZ), Translate);

	return result;
};

void WorldTransform::UpdateMatrix() {
	// スケール、回転、平行移動を合成して行列を計算する
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);
	// 定数バッファに転送する
	TransferMatrix();
}