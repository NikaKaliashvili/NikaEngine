#include "../../include/nika_engine.h"

Vec3::Vec3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vec3::magnitude()
{
	return sqrt(
		(this->x * this->x) +
		(this->y * this->y) +
		(this->z * this->z)
	);
}

Vec3 Vec3::normalize()
{
	float magnitude = this->magnitude();
	return Vec3(this->x / magnitude, this->y / magnitude, this->z);
}

float Vec3::dot(const Vec3& b) const
{
	return (
		(this->x * b.x)+
		(this->y * b.y)+
		(this->z * b.z)
	);
}

Vec3 Vec3::cross(const Vec3& b) const
{
	return Vec3(
		(this->y * b.z - this->z * b.y),
		(this->z*b.x - this->x*b.z),
		(this->x*b.y - this->y*b.x)
	);
}

Vec3 Vec3::operator+(const Vec3& other) const
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(const Vec3& other) const
{
	return Vec3(x * other.x, y * other.y, z * other.z);
}

Vec3 Vec3::operator/(const Vec3& other) const
{
	return Vec3(x / other.x, y / other.y, z / other.z);
}

template <typename T>
Vec3 Vec3::operator+(const T& other) const {
	return Vec3(this->x + other, this->y + other, this->z + other);
}

template <typename T>
Vec3 Vec3::operator-(const T& other) const {
	return Vec3(this->x - other, this->y - other, this->z - other);
}

template <typename T>
Vec3 Vec3::operator*(const T& other) const {
	return Vec3(this->x * other, this->y * other, this->z * other);
}

template <typename T>
Vec3 Vec3::operator/(const T& other) const {
	return Vec3(this->x / other, this->y / other, this->z / other);
}

Vec3 Vec3::operator+=(Vec3& other)
{
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
	return *this;
}

Vec3 Vec3::operator-=(Vec3& other)
{
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;
	return *this;
}

Vec3 Vec3::operator*=(Vec3& other)
{
	x = x * other.x;
	y = y * other.y;
	z = z * other.z;
	return *this;
}

Vec3 Vec3::operator/=(Vec3& other)
{
	x = x / other.x;
	y = y / other.y;
	z = z / other.z;
	return *this;
}

bool Vec3::operator==(const Vec3& other) const
{
	return (this->x == other.x && this->y == other.y && this->z == other.z);
}

bool Vec3::operator!=(const Vec3& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Vec3& other)
{
	return os << "Vec3(" << other.x << ", " << other.y << ", " << other.z << ")";
}

template Vec3 Vec3::operator+<int>(const int&) const;
template Vec3 Vec3::operator+<float>(const float&) const;
template Vec3 Vec3::operator+<double>(const double&) const;

template Vec3 Vec3::operator-<int>(const int&) const;
template Vec3 Vec3::operator-<float>(const float&) const;
template Vec3 Vec3::operator-<double>(const double&) const;

template Vec3 Vec3::operator*<int>(const int&) const;
template Vec3 Vec3::operator*<float>(const float&) const;
template Vec3 Vec3::operator*<double>(const double&) const;

template Vec3 Vec3::operator/<int>(const int&) const;
template Vec3 Vec3::operator/<float>(const float&) const;
template Vec3 Vec3::operator/<double>(const double&) const;