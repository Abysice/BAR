#ifndef MATRIX_H
#define MATRIX_H


#include "BARVector.h"

/*
* This file Contains the prototypes for the matrix classes and their related methods
*/


//This class Encapsulates a 3x3 matrix
class Matrix3
{
	friend class Matrix4;
private:
	float mat[3][3];

public:
	Matrix3() = default;
	Matrix3(Vector3& c1, Vector3& c2, Vector3& c3);
	Matrix3(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22);
	//Set the internal colums of the Matrix to the given vectors
	Matrix3& Set(const Vector3& c1, const Vector3& c2, const Vector3& c3);
	//Set the matrix to the identity matrix
	Matrix3& SetIdentity(void);
	//Returns an identity Matrix
	static Matrix3 Identity(void);
	//Set the matrix to a X-axis rotation matrix
	Matrix3& SetRotationX(float angle);
	//Set the matrix to a Y-axis rotation matrix
	Matrix3& SetRotationY(float angle);
	//Set the matrix to a Z-axis rotation matrix
	Matrix3& SetRotationZ(float angle);
	//Set the matrix to an arbitray axis rotation matrix
	Matrix3& SetRotationAxis(float angle, const Vector3& axis);
	//Get the Euler Angles of a matrix
	//void GetEulerAngles(float *x, float *y, float *z) const;
	//Set the rotation matrix from the Euler angles
	Matrix3& SetEulerAngles(float x, float y, float z);
	//Set the matrix to a uniform scaling matrix 
	Matrix3& SetScale(float t);
	//Set the matrix to a 3 axis scaling matrix
	Matrix3& SetScale(float r, float s, float t);

	float& operator ()(int i, int j)
	{
		return (mat[j][i]);
	}

	const float& operator ()(int i, int j) const
	{
		return (mat[j][i]);
	}

	Vector3& operator [](int j)
	{
		return (*reinterpret_cast<Vector3 *>(mat[j]));
	}

	const Vector3& operator [](int j) const
	{
		return (*reinterpret_cast<const Vector3 *>(mat[j]));
	}

	Matrix3& operator *=(const Matrix3& m);
	Matrix3& operator *=(float t);
	Matrix3& operator /=(float t);
	friend Matrix3 operator *(const Matrix3& m1, const Matrix3& m2);
	friend Matrix3 operator *(const Matrix3& m, float t);
	friend Matrix3 operator /(const Matrix3& m, float t);
	friend Vector3 operator *(const Matrix3& m, const Vector3& v);
	friend Vector3 operator *(const Vector3& v, const Matrix3& m);
	friend bool operator ==(const Matrix3& m1, const Matrix3& m2);
	friend bool operator !=(const Matrix3& m1, const Matrix3& m2);
	friend Matrix4 operator *(const Matrix4& m1, const Matrix3& m2);
};

//Return the Determinant of a Matrix3
float Determinant(const Matrix3& m);
//Returns the inverse matrix of a given Matrix3
Matrix3 Inverse(const Matrix3& m);
//Returns the Adjugate matrix of a given Matrix3
Matrix3 Adjugate(const Matrix3& m);
//Returns the Transpose matrix of a given Matrix3
Matrix3 Transpose(const Matrix3& m);



//this class encapsulates a 4x4 matrix
class Matrix4
{
private:
	float mat[4][4];

public:

	Matrix4() = default;
	Matrix4(const Vector4& c1, const Vector4& c2, const Vector4& c3, const Vector4& c4);
	Matrix4(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);

	//Set the internal colums of the Matrix to the given vectors
	Matrix4& Set(const Vector4& c1, const Vector4& c2, const Vector4& c3, const Vector4& c4);
	//Set the matrix to the identity matrix
	Matrix4& SetIdentity(void);
	//Returns an identity Matrix
	static Matrix4 Identity(void);
	//Set the matrix to a X-axis rotation matrix
	Matrix4& SetRotationX(float angle);
	//Set the matrix to a Y-axis rotation matrix
	Matrix4& SetRotationY(float angle);
	//Set the matrix to a Z-axis rotation matrix
	Matrix4& SetRotationZ(float angle);
	//Set the matrix to an arbitray axis rotation matrix
	Matrix4& SetRotationAxis(float angle, const Vector4& axis);
	//Get the Euler Angles of a matrix
	//void GetEulerAngles(float *x, float *y, float *z) const;
	//Set the rotation matrix from the Euler angles
	Matrix4& SetEulerAngles(float x, float y, float z);
	//Set the matrix to a uniform scaling matrix 
	Matrix4& SetScale(float t);
	//Set the matrix to a 3 axis scaling matrix
	Matrix4& SetScale(float r, float s, float t);
	//Set the matrix to a translation matrix
	Matrix4& SetTranslation(const Vector3& p);
	//Set the matrix to a translation matrix
	Matrix4& SetTranslation(float x, float y, float z);

	float& operator ()(int i, int j)
	{
		return (mat[j][i]);
	}

	const float& operator ()(int i, int j) const
	{
		return (mat[j][i]);
	}
	Vector4& operator [](int j)
	{
		return (*reinterpret_cast<Vector4 *>(mat[j]));
	}

	const Vector4& operator [](int j) const
	{
		return (*reinterpret_cast<const Vector4 *>(mat[j]));
	}

	Matrix4& operator =(const Matrix4& m);
	Matrix4& operator *=(const Matrix4& m);
	Matrix4& operator *=(const Matrix3& m);
	friend Matrix4 operator *(const Matrix4& m1, const Matrix4& m2);
	friend Matrix4 operator *(const Matrix4& m1, const Matrix3& m2);
	friend Vector4 operator *(const Matrix4& m, const Vector4& v);
	friend Vector4 operator *(const Matrix4& m, const Vector3& v);
	friend Vector4 operator *(const Vector3& v, const Matrix4& m);
	friend Vector4 operator *(const Matrix4& m, const Vector2& v);
	friend Vector4 operator *(const Vector2& v, const Matrix4& m);
	friend bool operator ==(const Matrix4& m1, const Matrix4& m2);
	friend bool operator !=(const Matrix4& m1, const Matrix4& m2);

};

float Determinant(const Matrix4& m);
Matrix4 Inverse(const Matrix4& m);
Matrix4 Adjugate(const Matrix4& m);
Matrix4 Transpose(const Matrix4& m);




#endif