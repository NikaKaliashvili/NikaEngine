#include "../../include/nika_engine.h"


Vec2::Vec2()
{
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

float Vec2::magnitude()
{
	return sqrt(
		(this->x * this->x) +
		(this->y * this->y)
	);
}

Vec2 Vec2::normalize()
{
	float magnitude = this->magnitude();
	return Vec2(this->x/magnitude, this->y/magnitude);
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

template <typename T>
Vec2 Vec2::operator+(const T& other) const{
	return Vec2(this->x + other, this->y + other);
}

template <typename T>
Vec2 Vec2::operator-(const T& other) const {
	return Vec2(this->x - other, this->y - other);
}

template <typename T>
Vec2 Vec2::operator*(const T& other) const {
	return Vec2(this->x * other, this->y * other);
}

template <typename T>
Vec2 Vec2::operator/(const T& other) const {
	return Vec2(this->x / other, this->y / other);
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

bool Vec2::operator==(const Vec2& other) const
{
	return (this->x == other.x && this->y == other.y);
}

bool Vec2::operator!=(const Vec2& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Vec2& other)
{
	return os << "Vec2(" << other.x << ", " << other.y << ")";
}

template Vec2 Vec2::operator+<int>(const int&) const;
template Vec2 Vec2::operator+<float>(const float&) const;
template Vec2 Vec2::operator+<double>(const double&) const;

template Vec2 Vec2::operator-<int>(const int&) const;
template Vec2 Vec2::operator-<float>(const float&) const;
template Vec2 Vec2::operator-<double>(const double&) const;

template Vec2 Vec2::operator*<int>(const int&) const;
template Vec2 Vec2::operator*<float>(const float&) const;
template Vec2 Vec2::operator*<double>(const double&) const;

template Vec2 Vec2::operator/<int>(const int&) const;
template Vec2 Vec2::operator/<float>(const float&) const;
template Vec2 Vec2::operator/<double>(const double&) const;