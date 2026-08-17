#pragma once

#include "../nika_engine.h"

class Vec3 {
public:
	float x;
	float y;
	float z;

	Vec3();
	Vec3(float x, float y, float z);

	float magnitude();
	Vec3 normalize();

	Vec3 operator+ (Vec3& other);
	Vec3 operator- (Vec3& other);
	Vec3 operator* (Vec3& other);
	Vec3 operator/ (Vec3& other);


	template <typename T>
	Vec3 operator+ (const T& other) const;

	template <typename T>
	Vec3 operator- (const T& other) const;

	template <typename T>
	Vec3 operator* (const T& other) const;

	template <typename T>
	Vec3 operator/ (const T& other) const;

	Vec3 operator+= (Vec3& other);
	Vec3 operator-= (Vec3& other);
	Vec3 operator*= (Vec3& other);
	Vec3 operator/= (Vec3& other);

	bool operator== (const Vec3& other) const;
	bool operator!= (const Vec3& other) const;

	friend std::ostream& operator<< (std::ostream& os, const Vec3& vec);
};