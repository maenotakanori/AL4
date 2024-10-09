#pragma once

namespace KamataEngine {

	/// <summary>
	/// 3次元ベクトル
	/// </summary>
	struct Vector3 final {
		float x;
		float y;
		float z;
	};


	inline Vector3& operator+=(Vector3& lhv, const Vector3& rhv) {
		lhv.x += rhv.x;
		lhv.y += rhv.y;
		lhv.z += rhv.z;
		return lhv;
	}

	inline const Vector3 operator+(const Vector3& v1, const Vector3& v2) {
		Vector3 temp(v1);
		return temp += v2;
	}

	inline Vector3& operator*=(Vector3& v, float s) {
		v.x *= s;
		v.y *= s;
		v.z *= s;
		return v;
	}

	inline const Vector3& operator*(const Vector3& v, float s) {
		Vector3 temp(v);
		return temp *= s;
	}

	inline const Vector3 operator+(const Vector3& v1, const Vector3 v2) {
		Vector3 temp(v1);
		return temp += v2;
	}
}