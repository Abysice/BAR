#include "BARVector.h"

// Vector2 method implementations
Vector2& Vector2::Rotate(float angle)
{
	float cTheta = cos(angle);
	float sTheta = sin(angle);
	float dx = (x*cTheta - y*sTheta);
	float dy = (x*sTheta + y*cTheta);
	x = dx;
	y = dy;
	
	return (*this);
}


//Vector3 method implementations
Vector3& Vector3::RotateAboutX(float angle)
{
	float cTheta = cos(angle);
	float sTheta = sin(angle);
	float dy = (y*cTheta - z*sTheta);
	float dz = (y*sTheta + z*cTheta);
	y = dy;
	z = dz;
	return (*this);
}

Vector3& Vector3::RotateAboutY(float angle)
{
	float cTheta = cos(angle);
	float sTheta = sin(angle);
	float dx = (x*cTheta + z*sTheta);
	float dz = (z*cTheta - x*sTheta);
	x = dx;
	z = dz;
	return (*this);
}

Vector3& Vector3::RotateAboutZ(float angle)
{
	float cTheta = cos(angle);
	float sTheta = sin(angle);
	float dx = (x*cTheta - y*sTheta);
	float dy = (x*sTheta + y*cTheta);
	x = dx;
	y = dy;
	return (*this);
}

Vector3& Vector3::RotateAboutAxis(float angle, const Vector3& axis)
{
	Vector2 t = Vector2(cos(angle), sin(angle));
	float u = 1.0F - t.x;
	float nx = x * (t.x + u * axis.x * axis.x) + y * (u * axis.x * axis.y - t.y * axis.z) + z * (u * axis.x * axis.z + t.y * axis.y);
	float ny = x * (u * axis.x * axis.y + t.y * axis.z) + y * (t.x + u * axis.y * axis.y) + z * (u * axis.y * axis.z - t.y * axis.x);
	float nz = x * (u * axis.x * axis.z - t.y * axis.y) + y * (u * axis.y * axis.z + t.y * axis.x) + z * (t.x + u * axis.z * axis.z);
	x = nx;
	y = ny;
	z = nz;
	return (*this);
}


//Vector4's method implementations
Vector4& Vector4::RotateAboutX(float angle)
{
	Vector2 t = Vector2(cos(angle), sin(angle));
	float ny = t.x * y - t.y * z;
	float nz = t.x * z + t.y * y;
	y = ny;
	z = nz;
	return (*this);
}

Vector4& Vector4::RotateAboutY(float angle)
{
	Vector2 t = Vector2(cos(angle), sin(angle));
	float nx = t.x * x + t.y * z;
	float nz = t.x * z - t.y * x;
	x = nx;
	z = nz;
	return (*this);
}

Vector4& Vector4::RotateAboutZ(float angle)
{
	Vector2 t = Vector2(cos(angle), sin(angle));
	float nx = t.x * x - t.y * y;
	float ny = t.x * y + t.y * x;
	x = nx;
	y = ny;
	return (*this);
}

Vector4& Vector4::RotateAboutAxis(float angle, const Vector3& axis)
{
	Vector2 t = Vector2(cos(angle), sin(angle));
	float u = 1.0F - t.x;
	float nx = x * (t.x + u * axis.x * axis.x) + y * (u * axis.x * axis.y - t.y * axis.z) + z * (u * axis.x * axis.z + t.y * axis.y);
	float ny = x * (u * axis.x * axis.y + t.y * axis.z) + y * (t.x + u * axis.y * axis.y) + z * (u * axis.y * axis.z - t.y * axis.x);
	float nz = x * (u * axis.x * axis.z - t.y * axis.y) + y * (u * axis.y * axis.z + t.y * axis.x) + z * (t.x + u * axis.z * axis.z);
	x = nx;
	y = ny;
	z = nz;
	return (*this);
}