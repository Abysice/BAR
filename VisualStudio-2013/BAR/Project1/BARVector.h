#include <math.h>

/*
 * This file Contains the prototypes for the Vector classes and their related methods
 */




//This class encapsulates a 2 dimensional vector
class Vector2
{
public:
	float x;
	float y;

	Vector2() = default; 
	Vector2(float _x, float _y) : x(_x), y(_y) {}

	//Normalize and return the Vector2
	Vector2& Normalized(void)
	{
		(*this *= (1.0F / sqrt(x*x + y*y)));
	}
	//Normalize the Vector2
	void Normalize(void)
	{
		float t = (1.0F / sqrt(x*x + y*y));
		x *= t;
		y *= t;
	}
	//Return the magnitude of the Vector2
	float Magnitude(void)
	{
		return sqrt(x*x + y*y);
	}
	//Interpolates from a to b at timestep t (t should be between 0-1)
	static Vector2 Lerp(Vector2& a, Vector2& b, float t)
	{
		return Vector2(a.x + b.x - a.x * t, a.y + b.y - a.y * t);
	}
	//Returns a zero vector
	static Vector2 Zero(void)
	{
		return Vector2();
	}
	//rotate the vector by a given angle(radians)
	Vector2& Rotate(float angle);

	float& operator [](int _k)
	{
		return ((&x)[_k]);
	}

	const float& operator [](int _k) const
	{
		return ((&x)[_k]);
	}

	Vector2 operator =(const Vector2& _vec)
	{
		x = _vec.x;
		y = _vec.y;
		return (*this);
	}
	
	Vector2& operator +=(const Vector2& _vec)
	{
		x += _vec.x;
		y += _vec.y;
		return (*this);
	}

	Vector2& operator -=(const Vector2& _vec)
	{
		x -= _vec.x;
		y -= _vec.y;
		return (*this);
	}

	Vector2& operator *=(const float f)
	{
		x *= f;
		y *= f;
		return (*this);
	}

	Vector2& operator /=(const float f)
	{
		float t = 1.0F / f;
		x *= t;
		y *= t;
		return (*this);
	}

};

inline Vector2 operator +(const Vector2& v1, const Vector2& v2)
{
	return (Vector2(v1.x + v2.x, v1.y + v2.y));
}

inline Vector2 operator -(const Vector2& v1, const Vector2& v2)
{
	return (Vector2(v1.x - v2.x, v1.y - v2.y));
}

inline Vector2 operator -(const Vector2& v)
{
	return (Vector2(-v.x, -v.y));
}

inline Vector2 operator *(const Vector2& v, float t)
{
	return (Vector2(v.x * t, v.y * t));
}

inline Vector2 operator *(float t, const Vector2& v)
{
	return (Vector2(t * v.x, t * v.y));
}

inline float operator *(const Vector2& v1, const Vector2& v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

inline Vector2 operator /(const Vector2& v, float t)
{
	float f = 1.0F / t;
	return (Vector2(v.x * f, v.y * f));
}

inline bool operator ==(const Vector2& v1, const Vector2& v2)
{
	return ((v1.x == v2.x) && (v1.y == v2.y));
}

inline bool operator !=(const Vector2& v1, const Vector2& v2)
{
	return ((v1.x != v2.x) || (v1.y != v2.y));
}




//This class encapsulates a 3 dimensional vector
class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3() = default;
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	Vector3(Vector2& vec) : x(vec.x), y(vec.y), z(0.0F) {}
	Vector3(Vector2& vec, float _z) : x(vec.x), y(vec.y), z(_z) {}

	//Normalize and return the Vector3
	Vector3& Normalized(void)
	{
		(*this *= (1.0F / sqrt(x*x + y*y + z*z)));
	}
	//Normalize the Vector3
	void Normalize(void)
	{
		float t = (1.0F / sqrt(x*x + y*y + z*z));
		x *= t;
		y *= t;
		z *= t;
	}
	//Return the magnitude of the Vector3
	float Magnitude(void)
	{
		return sqrt(x*x + y*y + z*z);
	}

	//Interpolates from a to b at timestep t (t should be between 0-1)
	static Vector3 Lerp(Vector3& a, Vector3& b, float t)
	{
		return Vector3(a.x + b.x - a.x * t, a.y + b.y - a.y * t, a.z + b.z - a.z * t);
	}
	//Returns a zero vector
	static Vector3 Zero(void)
	{
		return Vector3();
	}
	//rotates the Vector about the X axis by angle theta(radians)
	Vector3& RotateAboutX(float angle);
	//rotates the Vector about the Y axis by angle theta(radians)
	Vector3& RotateAboutY(float angle);
	//rotates the Vector about the Z axis by angle theta(radians)
	Vector3& RotateAboutZ(float angle);
	//rotates the Vector about an abitrary axis by angle theta(radians)
	Vector3& RotateAboutAxis(float angle, const Vector3& axis);

	float& operator [](int _k)
	{
		return ((&x)[_k]);
	}

	const float& operator [](int _k) const
	{
		return ((&x)[_k]);
	}

	Vector3 operator =(const Vector3& _vec)
	{
		x = _vec.x;
		y = _vec.y;
		z = _vec.z;
		return (*this);
	}

	Vector3& operator +=(const Vector3& _vec)
	{
		x += _vec.x;
		y += _vec.y;
		z += _vec.z;
		return (*this);
	}

	Vector3& operator -=(const Vector3& _vec)
	{
		x -= _vec.x;
		y -= _vec.y;
		z -= _vec.z;
		return (*this);
	}

	Vector3& operator *=(const float f)
	{
		x *= f;
		y *= f;
		z *= f;
		return (*this);
	}

	Vector3& operator /=(const float f)
	{
		float t = 1.0F / f;
		x *= t;
		y *= t;
		z *= t;
		return (*this);
	}
};

inline Vector3 operator +(const Vector3& v1, const Vector3& v2)
{
	return (Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

inline Vector3 operator -(const Vector3& v1, const Vector3& v2)
{
	return (Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

inline Vector3 operator -(const Vector3& v)
{
	return (Vector3(-v.x, -v.y, -v.z));
}

inline Vector3 operator *(const Vector3& v, float t)
{
	return (Vector3(v.x * t, v.y * t, v.z * t));
}

inline float operator *(const Vector3& v1, const Vector3& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z + v2.z);
}

inline Vector3 operator /(const Vector3& v, float t)
{
	float f = 1.0F / t;
	return (Vector3(v.x * f, v.y * f, v.z * f));
}

inline bool operator ==(const Vector3& v1, const Vector3& v2)
{
	return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
}

inline bool operator !=(const Vector3& v1, const Vector3& v2)
{
	return ((v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z));
}




//This class encapsulates a 4 dimensional vector
class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;

	Vector4() = default;
	Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
	Vector4(Vector2& vec) : x(vec.x), y(vec.y), z(0.0F), w(0.0F) {}
	Vector4(Vector3& vec) : x(vec.x), y(vec.y), z(vec.z), w(0.0F) {}
	Vector4(Vector3& vec, float _w) : x(vec.x), y(vec.y), z(vec.z), w(_w) {}

	//Normalize and return the Vector3
	Vector4& Normalized(void)
	{
		(*this *= (1.0F / sqrt(x*x + y*y + z*z + w*w)));
	}
	//Normalize the Vector3
	void Normalize(void)
	{
		float t = (1.0F / sqrt(x*x + y*y + z*z + w*w));
		x *= t;
		y *= t;
		z *= t;
		w *= t;
	}
	//Return the magnitude of the Vector3
	float Magnitude(void)
	{
		return sqrt(x*x + y*y + z*z);
	}

	//Interpolates from a to b at timestep t (t should be between 0-1)
	static Vector4 Lerp(Vector4& a, Vector4& b, float t)
	{
		return Vector4(a.x + b.x - a.x * t, a.y + b.y - a.y * t, a.z + b.z - a.z * t, a.w + b.w - a.w * t);
	}
	//Returns a zero vector
	static Vector4 Zero(void)
	{
		return Vector4();
	}
	//rotates the Vector about the X axis by angle theta(radians)
	Vector4& RotateAboutX(float angle);
	//rotates the Vector about the Y axis by angle theta(radians)
	Vector4& RotateAboutY(float angle);
	//rotates the Vector about the Z axis by angle theta(radians)
	Vector4& RotateAboutZ(float angle);
	//rotates the Vector about an abitrary axis by angle theta(radians)
	Vector4& RotateAboutAxis(float angle, const Vector3& axis);

	float& operator [](int k)
	{
		return ((&x)[k]);
	}

	const float& operator [](int k) const
	{
		return ((&x)[k]);
	}

	Vector4& operator =(const Vector4& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return (*this);
	}

	Vector4& operator =(const Vector3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = 0.0F;
		return (*this);
	}

	Vector4& operator +=(const Vector4& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return (*this);
	}

	Vector4& operator +=(const Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return (*this);
	}

	Vector4& operator +=(const Vector2& v)
	{
		x += v.x;
		y += v.y;
		return (*this);
	}

	Vector4& operator -=(const Vector4& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return (*this);
	}

	Vector4& operator -=(const Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return (*this);
	}

	Vector4& operator -=(const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
		return (*this);
	}

	Vector4& operator *=(float t)
	{
		x *= t;
		y *= t;
		z *= t;
		w *= t;
		return (*this);
	}

	Vector4& operator /=(float t)
	{
		float f = 1.0F / t;
		x *= f;
		y *= f;
		z *= f;
		w *= f;
		return (*this);
	}

	Vector4& operator &=(const Vector4& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return (*this);
	}

};

inline Vector4 operator -(const Vector4& v)
{
	return (Vector4(-v.x, -v.y, -v.z, -v.w));
}

inline Vector4 operator +(const Vector4& v1, const Vector4& v2)
{
	return (Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w));
}

inline Vector4 operator +(const Vector4& v1, const Vector3& v2)
{
	return (Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w));
}

inline Vector4 operator +(const Vector3& v1, const Vector4& v2)
{
	return (Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v2.w));
}

inline Vector4 operator +(const Vector4& v1, const Vector2& v2)
{
	return (Vector4(v1.x + v2.x, v1.y + v2.y, v1.z, v1.w));
}

inline Vector4 operator +(const Vector2& v1, const Vector4& v2)
{
	return (Vector4(v1.x + v2.x, v1.y + v2.y, v2.z, v2.w));
}

inline Vector4 operator -(const Vector4& v1, const Vector4& v2)
{
	return (Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w));
}

inline Vector4 operator -(const Vector4& v1, const Vector3& v2)
{
	return (Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w));
}

inline Vector4 operator -(const Vector3& v1, const Vector4& v2)
{
	return (Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, -v2.w));
}

inline Vector4 operator -(const Vector4& v1, const Vector2& v2)
{
	return (Vector4(v1.x - v2.x, v1.y - v2.y, v1.z, v1.w));
}

inline Vector4 operator -(const Vector2& v1, const Vector4& v2)
{
	return (Vector4(v1.x - v2.x, v1.y - v2.y, -v2.z, -v2.w));
}

inline Vector4 operator *(const Vector4& v, float t)
{
	return (Vector4(v.x * t, v.y * t, v.z * t, v.w * t));
}

inline Vector4 operator *(float t, const Vector4& v)
{
	return (Vector4(t * v.x, t * v.y, t * v.z, t * v.w));
}

inline Vector4 operator /(const Vector4& v, float t)
{
	float f = 1.0F / t;
	return (Vector4(v.x * f, v.y * f, v.z * f, v.w * f));
}

inline float operator *(const Vector4& v1, const Vector4& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

inline float operator *(const Vector4& v1, const Vector3& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline float operator *(const Vector3& v1, const Vector4& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline float operator *(const Vector4& v1, const Vector2& v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

inline float operator *(const Vector2& v1, const Vector4& v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

inline Vector4 operator &(const Vector4& v1, const Vector4& v2)
{
	return (Vector4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w));
}

inline bool operator ==(const Vector4& v1, const Vector4& v2)
{
	return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z) && (v1.w == v2.w));
}

inline bool operator !=(const Vector4& v1, const Vector4& v2)
{
	return ((v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z) || (v1.w != v2.w));
}