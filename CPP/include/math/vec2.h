#pragma once

#include "../nika_engine.h"


class Vec2 {
public:
	float x;
	float y;

	Vec2();
	Vec2(float x, float y);

	float magnitude();
	Vec2 normalize();

	Vec2 operator+ (const Vec2& other) const;
	Vec2 operator- (const Vec2& other) const;
	Vec2 operator* (const Vec2& other) const;
	Vec2 operator/ (const Vec2& other) const;

	template <typename T>
	Vec2 operator+ (const T& other) const;

	template <typename T>
	Vec2 operator- (const T& other) const;

	template <typename T>
	Vec2 operator* (const T& other) const;

	template <typename T>
	Vec2 operator/ (const T& other) const;

	Vec2 operator+= (Vec2& other);
	Vec2 operator-= (Vec2& other);
	Vec2 operator*= (Vec2& other);
	Vec2 operator/= (Vec2& other);

	bool operator== (const Vec2& other) const;
	bool operator!= (const Vec2& other) const;

	friend std::ostream& operator<< (std::ostream& os, const Vec2& vec);
};