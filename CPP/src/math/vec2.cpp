#include "../../include/nika_engine.h"

Vec2::Vec2()
{
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(int x, int y) {
	this->x = x;
	this->y = y;
}

Vec2 Vec2::operator+(Vec2& other)
{
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(Vec2& other)
{
	return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(Vec2& other)
{
	return Vec2(x * other.x, y * other.y);
}

Vec2 Vec2::operator/(Vec2& other)
{
	return Vec2(x / other.x, y / other.y);
}

Vec2 Vec2::operator+=(Vec2& other)
{
	x = x + other.x;
	y = y + other.y;
	return *this;
}

Vec2 Vec2::operator-=(Vec2& other)
{
	x = x - other.x;
	y = y - other.y;
	return *this;
}

Vec2 Vec2::operator*=(Vec2& other)
{
	x = x * other.x;
	y = y * other.y;
	return *this;
}

Vec2 Vec2::operator/=(Vec2& other)
{
	x = x / other.x;
	y = y / other.y;
	return *this;
}