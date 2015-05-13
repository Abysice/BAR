#include "BARMatrix.h"

//Matrix3 method implementations
Matrix3::Matrix3(Vector3& c1, Vector3& c2, Vector3& c3)
{
	mat[0][0] = c1.x;
	mat[0][1] = c1.y;
	mat[0][2] = c1.z;
	mat[1][0] = c2.x;
	mat[1][1] = c2.y;
	mat[1][2] = c2.z;
	mat[2][0] = c3.x;
	mat[2][1] = c3.y;
	mat[2][2] = c3.z;
}

Matrix3::Matrix3(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22)
{
	mat[0][0] = n00;
	mat[0][1] = n10;
	mat[0][2] = n20;
	mat[1][0] = n01;
	mat[1][1] = n11;
	mat[1][2] = n21;
	mat[2][0] = n02;
	mat[2][1] = n12;
	mat[2][2] = n22;
}

Matrix3& Matrix3::Set(const Vector3& c1, const Vector3& c2, const Vector3& c3)
{
	mat[0][0] = c1.x;
	mat[0][1] = c1.y;
	mat[0][2] = c1.z;
	mat[1][0] = c2.x;
	mat[1][1] = c2.y;
	mat[1][2] = c2.z;
	mat[2][0] = c3.x;
	mat[2][1] = c3.y;
	mat[2][2] = c3.z;

	return (*this);
}

Matrix3& Matrix3::SetIdentity(void)
{
	mat[0][0] = mat[1][1] = mat[2][2] = 1.0F;
	mat[0][1] = mat[0][2] = mat[1][0] = mat[1][2] = mat[2][0] = mat[2][1] = 0.0F;

	return (*this);
}

Matrix3 Matrix3::Identity(void)
{
	Matrix3 m;
	m.SetIdentity();
	return m;
}

Matrix3& Matrix3::SetRotationX(float angle)
{
	mat[1][1] = cos(angle);
	mat[1][2] = sin(angle);
	mat[2][2] = mat[1][1];
	mat[2][1] = -mat[1][2];
	mat[0][0] = 1.0F;
	mat[0][1] = mat[0][2] = mat[1][0] = mat[2][0] = 0.0F;
	return (*this);
}
Matrix3& Matrix3::SetRotationY(float angle)
{
	mat[0][0] = cos(angle);
	mat[2][0] = sin(angle);
	mat[2][2] = mat[0][0];
	mat[0][2] = -mat[2][0];
	mat[1][1] = 1.0F;
	mat[1][0] = mat[1][2] = mat[0][1] = mat[2][1] = 0.0F;
	return (*this);
}
Matrix3& Matrix3::SetRotationZ(float angle)
{
	mat[0][0] = cos(angle);
	mat[0][1] = sin(angle);
	mat[1][1] = mat[0][0];
	mat[1][0] = -mat[0][1];
	mat[2][2] = 1.0F;
	mat[2][0] = mat[2][1] = mat[0][2] = mat[1][2] = 0.0F;
	return (*this);
}

Matrix3& Matrix3::SetRotationAxis(float angle, const Vector3& axis)
{
	Vector2 t = Vector2(cos(angle), sin(angle));
	float u = 1.0F - t.x;
	mat[0][0] = t.x + u * axis.x * axis.x;
	mat[0][1] = u * axis.x * axis.y + t.y * axis.z;
	mat[0][2] = u * axis.x * axis.z - t.y * axis.y;
	mat[1][0] = u * axis.x * axis.y - t.y * axis.z;
	mat[1][1] = t.x + u * axis.y * axis.y;
	mat[1][2] = u * axis.y * axis.z + t.y * axis.x;
	mat[2][0] = u * axis.x * axis.z + t.y * axis.y;
	mat[2][1] = u * axis.y * axis.z - t.y * axis.x;
	mat[2][2] = t.x + u * axis.z * axis.z;
	return (*this);
}

//void Matrix3::GetEulerAngles(float *x, float *y, float *z) const
//{
//	return;
//}

Matrix3& Matrix3::SetEulerAngles(float x, float y, float z)
{
	Vector2 xrot = Vector2(cos(x), sin(x));
	Vector2 yrot = Vector2(cos(y), sin(y));
	Vector2 zrot = Vector2(cos(z), sin(z));
	mat[0][0] = yrot.x * zrot.x;
	mat[0][1] = xrot.x * zrot.y + xrot.y * yrot.y * zrot.x;
	mat[0][2] = xrot.y * zrot.y - xrot.x * yrot.y * zrot.x;
	mat[1][0] = -yrot.x * zrot.y;
	mat[1][1] = xrot.x * zrot.x - xrot.y * yrot.y * zrot.y;
	mat[1][2] = xrot.y * zrot.x + xrot.x * yrot.y * zrot.y;
	mat[2][0] = yrot.y;
	mat[2][1] = -xrot.y * yrot.x;
	mat[2][2] = xrot.x * yrot.x;
	return (*this);
}

Matrix3& Matrix3::SetScale(float t)
{
	mat[0][0] = mat[1][1] = mat[2][2] = t;
	mat[0][1] = mat[0][2] = mat[1][0] = mat[1][2] = mat[2][0] = mat[2][1] = 0.0F;
	return (*this);
}

Matrix3& Matrix3::SetScale(float r, float s, float t)
{
	mat[0][0] = r;
	mat[1][1] = s;
	mat[2][2] = t;
	mat[0][1] = mat[0][2] = mat[1][0] = mat[1][2] = mat[2][0] = mat[2][1] = 0.0F;
	return (*this);
}

Matrix3& Matrix3::operator *=(const Matrix3& m)
{
	float t = mat[0][0] * m.mat[0][0] + mat[1][0] * m.mat[0][1] + mat[2][0] * m.mat[0][2];
	float u = mat[0][0] * m.mat[1][0] + mat[1][0] * m.mat[1][1] + mat[2][0] * m.mat[1][2];
	mat[2][0] = mat[0][0] * m.mat[2][0] + mat[1][0] * m.mat[2][1] + mat[2][0] * m.mat[2][2];
	mat[0][0] = t;
	mat[1][0] = u;

	t = mat[0][1] * m.mat[0][0] + mat[1][1] * m.mat[0][1] + mat[2][1] * m.mat[0][2];
	u = mat[0][1] * m.mat[1][0] + mat[1][1] * m.mat[1][1] + mat[2][1] * m.mat[1][2];
	mat[2][1] = mat[0][1] * m.mat[2][0] + mat[1][1] * m.mat[2][1] + mat[2][1] * m.mat[2][2];
	mat[0][1] = t;
	mat[1][1] = u;

	t = mat[0][2] * m.mat[0][0] + mat[1][2] * m.mat[0][1] + mat[2][2] * m.mat[0][2];
	u = mat[0][2] * m.mat[1][0] + mat[1][2] * m.mat[1][1] + mat[2][2] * m.mat[1][2];
	mat[2][2] = mat[0][2] * m.mat[2][0] + mat[1][2] * m.mat[2][1] + mat[2][2] * m.mat[2][2];
	mat[0][2] = t;
	mat[1][2] = u;

	return (*this);
}

Matrix3& Matrix3::operator *=(float t)
{
	mat[0][0] *= t;
	mat[0][1] *= t;
	mat[0][2] *= t;
	mat[1][0] *= t;
	mat[1][1] *= t;
	mat[1][2] *= t;
	mat[2][0] *= t;
	mat[2][1] *= t;
	mat[2][2] *= t;

	return (*this);
}

Matrix3& Matrix3::operator /=(float t)
{
	float f = 1.0F / t;
	mat[0][0] *= f;
	mat[0][1] *= f;
	mat[0][2] *= f;
	mat[1][0] *= f;
	mat[1][1] *= f;
	mat[1][2] *= f;
	mat[2][0] *= f;
	mat[2][1] *= f;
	mat[2][2] *= f;

	return (*this);
}

Matrix3 operator *(const Matrix3& m1, const Matrix3& m2)
{
	return (Matrix3(m1.mat[0][0] * m2.mat[0][0] + m1.mat[1][0] * m2.mat[0][1] + m1.mat[2][0] * m2.mat[0][2],
					m1.mat[0][0] * m2.mat[1][0] + m1.mat[1][0] * m2.mat[1][1] + m1.mat[2][0] * m2.mat[1][2],
					m1.mat[0][0] * m2.mat[2][0] + m1.mat[1][0] * m2.mat[2][1] + m1.mat[2][0] * m2.mat[2][2],
					m1.mat[0][1] * m2.mat[0][0] + m1.mat[1][1] * m2.mat[0][1] + m1.mat[2][1] * m2.mat[0][2],
					m1.mat[0][1] * m2.mat[1][0] + m1.mat[1][1] * m2.mat[1][1] + m1.mat[2][1] * m2.mat[1][2],
					m1.mat[0][1] * m2.mat[2][0] + m1.mat[1][1] * m2.mat[2][1] + m1.mat[2][1] * m2.mat[2][2],
					m1.mat[0][2] * m2.mat[0][0] + m1.mat[1][2] * m2.mat[0][1] + m1.mat[2][2] * m2.mat[0][2],
					m1.mat[0][2] * m2.mat[1][0] + m1.mat[1][2] * m2.mat[1][1] + m1.mat[2][2] * m2.mat[1][2],
					m1.mat[0][2] * m2.mat[2][0] + m1.mat[1][2] * m2.mat[2][1] + m1.mat[2][2] * m2.mat[2][2]));
}

Matrix3 operator *(const Matrix3& m, float t)
{
	return (Matrix3(m.mat[0][0] * t, m.mat[1][0] * t, m.mat[2][0] * t, m.mat[0][1] * t, m.mat[1][1] * t, m.mat[2][1] * t, m.mat[0][2] * t, m.mat[1][2] * t, m.mat[2][2] * t));
}

Matrix3 operator /(const Matrix3& m, float t)
{
	float f = 1.0F / t;
	return (Matrix3(m.mat[0][0] * f, m.mat[1][0] * f, m.mat[2][0] * f, m.mat[0][1] * f, m.mat[1][1] * f, m.mat[2][1] * f, m.mat[0][2] * f, m.mat[1][2] * f, m.mat[2][2] * f));
}

Vector3 operator *(const Matrix3& m, const Vector3& v)
{
	return (Vector3(m.mat[0][0] * v.x + m.mat[1][0] * v.y + m.mat[2][0] * v.z, m.mat[0][1] * v.x + m.mat[1][1] * v.y + m.mat[2][1] * v.z, m.mat[0][2] * v.x + m.mat[1][2] * v.y + m.mat[2][2] * v.z));
}

Vector3 operator *(const Vector3& v, const Matrix3& m)
{
	return (Vector3(m.mat[0][0] * v.x + m.mat[0][1] * v.y + m.mat[0][2] * v.z, m.mat[1][0] * v.x + m.mat[1][1] * v.y + m.mat[1][2] * v.z, m.mat[2][0] * v.x + m.mat[2][1] * v.y + m.mat[2][2] * v.z));
}

bool operator ==(const Matrix3& m1, const Matrix3& m2)
{
	return ((m1.mat[0][0] == m2.mat[0][0]) && (m1.mat[0][1] == m2.mat[0][1]) && (m1.mat[0][2] == m2.mat[0][2]) && (m1.mat[1][0] == m2.mat[1][0]) && (m1.mat[1][1] == m2.mat[1][1]) && (m1.mat[1][2] == m2.mat[1][2]) && (m1.mat[2][0] == m2.mat[2][0]) && (m1.mat[2][1] == m2.mat[2][1]) && (m1.mat[2][2] == m2.mat[2][2]));
}

bool operator !=(const Matrix3& m1, const Matrix3& m2)
{
	return ((m1.mat[0][0] != m2.mat[0][0]) || (m1.mat[0][1] != m2.mat[0][1]) || (m1.mat[0][2] != m2.mat[0][2]) || (m1.mat[1][0] != m2.mat[1][0]) || (m1.mat[1][1] != m2.mat[1][1]) || (m1.mat[1][2] != m2.mat[1][2]) || (m1.mat[2][0] != m2.mat[2][0]) || (m1.mat[2][1] != m2.mat[2][1]) || (m1.mat[2][2] != m2.mat[2][2]));
}

float Determinant(const Matrix3& m)
{
	return (m(0, 0) * (m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1)) - m(0, 1) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) + m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0)));
}

Matrix3 Inverse(const Matrix3& m)
{
	float n00 = m(0, 0);
	float n01 = m(0, 1);
	float n02 = m(0, 2);
	float n10 = m(1, 0);
	float n11 = m(1, 1);
	float n12 = m(1, 2);
	float n20 = m(2, 0);
	float n21 = m(2, 1);
	float n22 = m(2, 2);

	float p00 = n11 * n22 - n12 * n21;
	float p10 = n12 * n20 - n10 * n22;
	float p20 = n10 * n21 - n11 * n20;

	float t = 1.0F / (n00 * p00 + n01 * p10 + n02 * p20);

	return (Matrix3(p00 * t, (n02 * n21 - n01 * n22) * t, (n01 * n12 - n02 * n11) * t,
					p10 * t, (n00 * n22 - n02 * n20) * t, (n02 * n10 - n00 * n12) * t,
					p20 * t, (n01 * n20 - n00 * n21) * t, (n00 * n11 - n01 * n10) * t));
}

Matrix3 Adjugate(const Matrix3& m)
{
	float n00 = m(0, 0);
	float n01 = m(0, 1);
	float n02 = m(0, 2);
	float n10 = m(1, 0);
	float n11 = m(1, 1);
	float n12 = m(1, 2);
	float n20 = m(2, 0);
	float n21 = m(2, 1);
	float n22 = m(2, 2);

	return (Matrix3(n11 * n22 - n12 * n21, n02 * n21 - n01 * n22, n01 * n12 - n02 * n11,
					n12 * n20 - n10 * n22, n00 * n22 - n02 * n20, n02 * n10 - n00 * n12,
					n10 * n21 - n11 * n20, n01 * n20 - n00 * n21, n00 * n11 - n01 * n10));
}

Matrix3 Transpose(const Matrix3& m)
{
	return (Matrix3(m(0, 0), m(1, 0), m(2, 0), m(0, 1), m(1, 1), m(2, 1), m(0, 2), m(1, 2), m(2, 2)));
}



//////////////////////////////////
//Matrix4 Method implementations//
//////////////////////////////////


Matrix4::Matrix4(const Vector4& c1, const Vector4& c2, const Vector4& c3, const Vector4& c4)
{
	mat[0][0] = c1.x;
	mat[0][1] = c1.y;
	mat[0][2] = c1.z;
	mat[0][3] = c1.w;
	mat[1][0] = c2.x;
	mat[1][1] = c2.y;
	mat[1][2] = c2.z;
	mat[1][3] = c2.w;
	mat[2][0] = c3.x;
	mat[2][1] = c3.y;
	mat[2][2] = c3.z;
	mat[2][3] = c3.w;
	mat[3][0] = c4.x;
	mat[3][1] = c4.y;
	mat[3][2] = c4.z;
	mat[3][3] = c4.w;
}

Matrix4::Matrix4(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33)
{
	mat[0][0] = n00;
	mat[1][0] = n01;
	mat[2][0] = n02;
	mat[3][0] = n03;
	mat[0][1] = n10;
	mat[1][1] = n11;
	mat[2][1] = n12;
	mat[3][1] = n13;
	mat[0][2] = n20;
	mat[1][2] = n21;
	mat[2][2] = n22;
	mat[3][2] = n23;
	mat[0][3] = n30;
	mat[1][3] = n31;
	mat[2][3] = n32;
	mat[3][3] = n33;
}

Matrix4& Matrix4::Set(const Vector4& c1, const Vector4& c2, const Vector4& c3, const Vector4& c4)
{
	mat[0][0] = c1.x;
	mat[0][1] = c1.y;
	mat[0][2] = c1.z;
	mat[0][3] = c1.w;
	mat[1][0] = c2.x;
	mat[1][1] = c2.y;
	mat[1][2] = c2.z;
	mat[1][3] = c2.w;
	mat[2][0] = c3.x;
	mat[2][1] = c3.y;
	mat[2][2] = c3.z;
	mat[2][3] = c3.w;
	mat[3][0] = c4.x;
	mat[3][1] = c4.y;
	mat[3][2] = c4.z;
	mat[3][3] = c4.w;

	return (*this);
}

Matrix4& Matrix4::operator *=(const Matrix4& m)
{
	float x = mat[0][0];
	float y = mat[1][0];
	float z = mat[2][0];
	float w = mat[3][0];
	mat[0][0] = x * m.mat[0][0] + y * m.mat[0][1] + z * m.mat[0][2] + w * m.mat[0][3];
	mat[1][0] = x * m.mat[1][0] + y * m.mat[1][1] + z * m.mat[1][2] + w * m.mat[1][3];
	mat[2][0] = x * m.mat[2][0] + y * m.mat[2][1] + z * m.mat[2][2] + w * m.mat[2][3];
	mat[3][0] = x * m.mat[3][0] + y * m.mat[3][1] + z * m.mat[3][2] + w * m.mat[3][3];

	x = mat[0][1];
	y = mat[1][1];
	z = mat[2][1];
	w = mat[3][1];
	mat[0][1] = x * m.mat[0][0] + y * m.mat[0][1] + z * m.mat[0][2] + w * m.mat[0][3];
	mat[1][1] = x * m.mat[1][0] + y * m.mat[1][1] + z * m.mat[1][2] + w * m.mat[1][3];
	mat[2][1] = x * m.mat[2][0] + y * m.mat[2][1] + z * m.mat[2][2] + w * m.mat[2][3];
	mat[3][1] = x * m.mat[3][0] + y * m.mat[3][1] + z * m.mat[3][2] + w * m.mat[3][3];

	x = mat[0][2];
	y = mat[1][2];
	z = mat[2][2];
	w = mat[3][2];
	mat[0][2] = x * m.mat[0][0] + y * m.mat[0][1] + z * m.mat[0][2] + w * m.mat[0][3];
	mat[1][2] = x * m.mat[1][0] + y * m.mat[1][1] + z * m.mat[1][2] + w * m.mat[1][3];
	mat[2][2] = x * m.mat[2][0] + y * m.mat[2][1] + z * m.mat[2][2] + w * m.mat[2][3];
	mat[3][2] = x * m.mat[3][0] + y * m.mat[3][1] + z * m.mat[3][2] + w * m.mat[3][3];

	x = mat[0][3];
	y = mat[1][3];
	z = mat[2][3];
	w = mat[3][3];
	mat[0][3] = x * m.mat[0][0] + y * m.mat[0][1] + z * m.mat[0][2] + w * m.mat[0][3];
	mat[1][3] = x * m.mat[1][0] + y * m.mat[1][1] + z * m.mat[1][2] + w * m.mat[1][3];
	mat[2][3] = x * m.mat[2][0] + y * m.mat[2][1] + z * m.mat[2][2] + w * m.mat[2][3];
	mat[3][3] = x * m.mat[3][0] + y * m.mat[3][1] + z * m.mat[3][2] + w * m.mat[3][3];

	return (*this);
}

Matrix4& Matrix4::operator *=(const Matrix3& m)
{
	float x = mat[0][0];
	float y = mat[1][0];
	float z = mat[2][0];
	mat[0][0] = x * m.mat[0][0] + y * m.mat[0][1] + z * m.mat[0][2];
	mat[1][0] = x * m.mat[1][0] + y * m.mat[1][1] + z * m.mat[1][2];
	mat[2][0] = x * m.mat[2][0] + y * m.mat[2][1] + z * m.mat[2][2];

	x = mat[0][1];
	y = mat[1][1];
	z = mat[2][1];
	mat[0][1] = x * m.mat[0][0] + y * m.mat[0][1] + z * m.mat[0][2];
	mat[1][1] = x * m.mat[1][0] + y * m.mat[1][1] + z * m.mat[1][2];
	mat[2][1] = x * m.mat[2][0] + y * m.mat[2][1] + z * m.mat[2][2];

	x = mat[0][2];
	y = mat[1][2];
	z = mat[2][2];
	mat[0][2] = x * m.mat[0][0] + y * m.mat[0][1] + z * m.mat[0][2];
	mat[1][2] = x * m.mat[1][0] + y * m.mat[1][1] + z * m.mat[1][2];
	mat[2][2] = x * m.mat[2][0] + y * m.mat[2][1] + z * m.mat[2][2];

	x = mat[0][3];
	y = mat[1][3];
	z = mat[2][3];
	mat[0][3] = x * m.mat[0][0] + y * m.mat[0][1] + z * m.mat[0][2];
	mat[1][3] = x * m.mat[1][0] + y * m.mat[1][1] + z * m.mat[1][2];
	mat[2][3] = x * m.mat[2][0] + y * m.mat[2][1] + z * m.mat[2][2];

	return (*this);
}

Matrix4& Matrix4::SetIdentity(void)
{
	mat[0][0] = mat[1][1] = mat[2][2] = mat[3][3] = 1.0F;
	mat[1][0] = mat[2][0] = mat[3][0] = mat[0][1] = mat[2][1] = mat[3][1] = mat[0][2] = mat[1][2] = mat[3][2] = mat[0][3] = mat[1][3] = mat[2][3] = 0.0F;
	return (*this);
}


Matrix4 operator *(const Matrix4& m1, const Matrix4& m2)
{
	return (Matrix4(m1.mat[0][0] * m2.mat[0][0] + m1.mat[1][0] * m2.mat[0][1] + m1.mat[2][0] * m2.mat[0][2] + m1.mat[3][0] * m2.mat[0][3],
					m1.mat[0][0] * m2.mat[1][0] + m1.mat[1][0] * m2.mat[1][1] + m1.mat[2][0] * m2.mat[1][2] + m1.mat[3][0] * m2.mat[1][3],
					m1.mat[0][0] * m2.mat[2][0] + m1.mat[1][0] * m2.mat[2][1] + m1.mat[2][0] * m2.mat[2][2] + m1.mat[3][0] * m2.mat[2][3],
					m1.mat[0][0] * m2.mat[3][0] + m1.mat[1][0] * m2.mat[3][1] + m1.mat[2][0] * m2.mat[3][2] + m1.mat[3][0] * m2.mat[3][3],
					m1.mat[0][1] * m2.mat[0][0] + m1.mat[1][1] * m2.mat[0][1] + m1.mat[2][1] * m2.mat[0][2] + m1.mat[3][1] * m2.mat[0][3],
					m1.mat[0][1] * m2.mat[1][0] + m1.mat[1][1] * m2.mat[1][1] + m1.mat[2][1] * m2.mat[1][2] + m1.mat[3][1] * m2.mat[1][3],
					m1.mat[0][1] * m2.mat[2][0] + m1.mat[1][1] * m2.mat[2][1] + m1.mat[2][1] * m2.mat[2][2] + m1.mat[3][1] * m2.mat[2][3],
					m1.mat[0][1] * m2.mat[3][0] + m1.mat[1][1] * m2.mat[3][1] + m1.mat[2][1] * m2.mat[3][2] + m1.mat[3][1] * m2.mat[3][3],
					m1.mat[0][2] * m2.mat[0][0] + m1.mat[1][2] * m2.mat[0][1] + m1.mat[2][2] * m2.mat[0][2] + m1.mat[3][2] * m2.mat[0][3],
					m1.mat[0][2] * m2.mat[1][0] + m1.mat[1][2] * m2.mat[1][1] + m1.mat[2][2] * m2.mat[1][2] + m1.mat[3][2] * m2.mat[1][3],
					m1.mat[0][2] * m2.mat[2][0] + m1.mat[1][2] * m2.mat[2][1] + m1.mat[2][2] * m2.mat[2][2] + m1.mat[3][2] * m2.mat[2][3],
					m1.mat[0][2] * m2.mat[3][0] + m1.mat[1][2] * m2.mat[3][1] + m1.mat[2][2] * m2.mat[3][2] + m1.mat[3][2] * m2.mat[3][3],
					m1.mat[0][3] * m2.mat[0][0] + m1.mat[1][3] * m2.mat[0][1] + m1.mat[2][3] * m2.mat[0][2] + m1.mat[3][3] * m2.mat[0][3],
					m1.mat[0][3] * m2.mat[1][0] + m1.mat[1][3] * m2.mat[1][1] + m1.mat[2][3] * m2.mat[1][2] + m1.mat[3][3] * m2.mat[1][3],
					m1.mat[0][3] * m2.mat[2][0] + m1.mat[1][3] * m2.mat[2][1] + m1.mat[2][3] * m2.mat[2][2] + m1.mat[3][3] * m2.mat[2][3],
					m1.mat[0][3] * m2.mat[3][0] + m1.mat[1][3] * m2.mat[3][1] + m1.mat[2][3] * m2.mat[3][2] + m1.mat[3][3] * m2.mat[3][3]));
}

Matrix4 operator *(const Matrix4& m1, const Matrix3& m2)
{
	return (Matrix4(m1.mat[0][0] * m2.mat[0][0] + m1.mat[1][0] * m2.mat[0][1] + m1.mat[2][0] * m2.mat[0][2],
					m1.mat[0][0] * m2.mat[1][0] + m1.mat[1][0] * m2.mat[1][1] + m1.mat[2][0] * m2.mat[1][2],
					m1.mat[0][0] * m2.mat[2][0] + m1.mat[1][0] * m2.mat[2][1] + m1.mat[2][0] * m2.mat[2][2],
					m1.mat[3][0],
					m1.mat[0][1] * m2.mat[0][0] + m1.mat[1][1] * m2.mat[0][1] + m1.mat[2][1] * m2.mat[0][2],
					m1.mat[0][1] * m2.mat[1][0] + m1.mat[1][1] * m2.mat[1][1] + m1.mat[2][1] * m2.mat[1][2],
					m1.mat[0][1] * m2.mat[2][0] + m1.mat[1][1] * m2.mat[2][1] + m1.mat[2][1] * m2.mat[2][2],
					m1.mat[3][1],
					m1.mat[0][2] * m2.mat[0][0] + m1.mat[1][2] * m2.mat[0][1] + m1.mat[2][2] * m2.mat[0][2],
					m1.mat[0][2] * m2.mat[1][0] + m1.mat[1][2] * m2.mat[1][1] + m1.mat[2][2] * m2.mat[1][2],
					m1.mat[0][2] * m2.mat[2][0] + m1.mat[1][2] * m2.mat[2][1] + m1.mat[2][2] * m2.mat[2][2],
					m1.mat[3][2],
					m1.mat[0][3] * m2.mat[0][0] + m1.mat[1][3] * m2.mat[0][1] + m1.mat[2][3] * m2.mat[0][2],
					m1.mat[0][3] * m2.mat[1][0] + m1.mat[1][3] * m2.mat[1][1] + m1.mat[2][3] * m2.mat[1][2],
					m1.mat[0][3] * m2.mat[2][0] + m1.mat[1][3] * m2.mat[2][1] + m1.mat[2][3] * m2.mat[2][2],
					m1.mat[3][3]));
}

Vector4 operator *(const Matrix4& m, const Vector4& v)
{
	return (Vector4(m.mat[0][0] * v.x + m.mat[1][0] * v.y + m.mat[2][0] * v.z + m.mat[3][0] * v.w,
					m.mat[0][1] * v.x + m.mat[1][1] * v.y + m.mat[2][1] * v.z + m.mat[3][1] * v.w,
					m.mat[0][2] * v.x + m.mat[1][2] * v.y + m.mat[2][2] * v.z + m.mat[3][2] * v.w,
					m.mat[0][3] * v.x + m.mat[1][3] * v.y + m.mat[2][3] * v.z + m.mat[3][3] * v.w));
}

Vector4 operator *(const Matrix4& m, const Vector3& v)
{
	return (Vector4(m.mat[0][0] * v.x + m.mat[1][0] * v.y + m.mat[2][0] * v.z,
					m.mat[0][1] * v.x + m.mat[1][1] * v.y + m.mat[2][1] * v.z,
					m.mat[0][2] * v.x + m.mat[1][2] * v.y + m.mat[2][2] * v.z,
					m.mat[0][3] * v.x + m.mat[1][3] * v.y + m.mat[2][3] * v.z));
}

Vector4 operator *(const Vector3& v, const Matrix4& m)
{
	return (Vector4(m.mat[0][0] * v.x + m.mat[0][1] * v.y + m.mat[0][2] * v.z,
					m.mat[1][0] * v.x + m.mat[1][1] * v.y + m.mat[1][2] * v.z,
					m.mat[2][0] * v.x + m.mat[2][1] * v.y + m.mat[2][2] * v.z,
					m.mat[3][0] * v.x + m.mat[3][1] * v.y + m.mat[3][2] * v.z));
}

Vector4 operator *(const Matrix4& m, const Vector2& v)
{
	return (Vector4(m.mat[0][0] * v.x + m.mat[1][0] * v.y,
					m.mat[0][1] * v.x + m.mat[1][1] * v.y,
					m.mat[0][2] * v.x + m.mat[1][2] * v.y,
					m.mat[0][3] * v.x + m.mat[1][3] * v.y));
}

Vector4 operator *(const Vector2& v, const Matrix4& m)
{
	return (Vector4(m.mat[0][0] * v.x + m.mat[0][1] * v.y,
					m.mat[1][0] * v.x + m.mat[1][1] * v.y,
					m.mat[2][0] * v.x + m.mat[2][1] * v.y,
					m.mat[3][0] * v.x + m.mat[3][1] * v.y));
}

bool operator ==(const Matrix4& m1, const Matrix4& m2)
{
	return ((m1.mat[0][0] == m2.mat[0][0]) && (m1.mat[0][1] == m2.mat[0][1]) && (m1.mat[0][2] == m2.mat[0][2]) && (m1.mat[0][3] == m2.mat[0][3]) && (m1.mat[1][0] == m2.mat[1][0]) && (m1.mat[1][1] == m2.mat[1][1]) && (m1.mat[1][2] == m2.mat[1][2]) && (m1.mat[1][3] == m2.mat[1][3]) && (m1.mat[2][0] == m2.mat[2][0]) && (m1.mat[2][1] == m2.mat[2][1]) && (m1.mat[2][2] == m2.mat[2][2]) && (m1.mat[2][3] == m2.mat[2][3]) && (m1.mat[3][0] == m2.mat[3][0]) && (m1.mat[3][1] == m2.mat[3][1]) && (m1.mat[3][2] == m2.mat[3][2]) && (m1.mat[3][3] == m2.mat[3][3]));
}

bool operator !=(const Matrix4& m1, const Matrix4& m2)
{
	return ((m1.mat[0][0] != m2.mat[0][0]) || (m1.mat[0][1] != m2.mat[0][1]) || (m1.mat[0][2] != m2.mat[0][2]) || (m1.mat[0][3] != m2.mat[0][3]) || (m1.mat[1][0] != m2.mat[1][0]) || (m1.mat[1][1] != m2.mat[1][1]) || (m1.mat[1][2] != m2.mat[1][2]) || (m1.mat[1][3] != m2.mat[1][3]) || (m1.mat[2][0] != m2.mat[2][0]) || (m1.mat[2][1] != m2.mat[2][1]) || (m1.mat[2][2] != m2.mat[2][2]) || (m1.mat[2][3] != m2.mat[2][3]) || (m1.mat[3][0] != m2.mat[3][0]) || (m1.mat[3][1] != m2.mat[3][1]) || (m1.mat[3][2] != m2.mat[3][2]) || (m1.mat[3][3] != m2.mat[3][3]));
}

float Determinant(const Matrix4& m)
{
	float n00 = m(0, 0);
	float n01 = m(0, 1);
	float n02 = m(0, 2);
	float n03 = m(0, 3);
	float n10 = m(1, 0);
	float n11 = m(1, 1);
	float n12 = m(1, 2);
	float n13 = m(1, 3);
	float n20 = m(2, 0);
	float n21 = m(2, 1);
	float n22 = m(2, 2);
	float n23 = m(2, 3);
	float n30 = m(3, 0);
	float n31 = m(3, 1);
	float n32 = m(3, 2);
	float n33 = m(3, 3);

	return (n00 * (n11 * (n22 * n33 - n23 * n32) + n12 * (n23 * n31 - n21 * n33) + n13 * (n21 * n32 - n22 * n31)) +
			n01 * (n10 * (n23 * n32 - n22 * n33) + n12 * (n20 * n33 - n23 * n30) + n13 * (n22 * n30 - n20 * n32)) +
			n02 * (n10 * (n21 * n33 - n23 * n31) + n11 * (n23 * n30 - n20 * n33) + n13 * (n20 * n31 - n21 * n30)) +
			n03 * (n10 * (n22 * n31 - n21 * n32) + n11 * (n20 * n32 - n22 * n30) + n12 * (n21 * n30 - n20 * n31)));
}

Matrix4 Inverse(const Matrix4& m)
{
	float n00 = m(0, 0);
	float n01 = m(0, 1);
	float n02 = m(0, 2);
	float n03 = m(0, 3);
	float n10 = m(1, 0);
	float n11 = m(1, 1);
	float n12 = m(1, 2);
	float n13 = m(1, 3);
	float n20 = m(2, 0);
	float n21 = m(2, 1);
	float n22 = m(2, 2);
	float n23 = m(2, 3);
	float n30 = m(3, 0);
	float n31 = m(3, 1);
	float n32 = m(3, 2);
	float n33 = m(3, 3);
	float p00 = n11 * (n22 * n33 - n23 * n32) + n12 * (n23 * n31 - n21 * n33) + n13 * (n21 * n32 - n22 * n31);
	float p10 = n10 * (n23 * n32 - n22 * n33) + n12 * (n20 * n33 - n23 * n30) + n13 * (n22 * n30 - n20 * n32);
	float p20 = n10 * (n21 * n33 - n23 * n31) + n11 * (n23 * n30 - n20 * n33) + n13 * (n20 * n31 - n21 * n30);
	float p30 = n10 * (n22 * n31 - n21 * n32) + n11 * (n20 * n32 - n22 * n30) + n12 * (n21 * n30 - n20 * n31);
	float t = 1.0F / (n00 * p00 + n01 * p10 + n02 * p20 + n03 * p30);
	
	return (Matrix4(p00 * t,
		(n01 * (n23 * n32 - n22 * n33) + n02 * (n21 * n33 - n23 * n31) + n03 * (n22 * n31 - n21 * n32)) * t,
		(n01 * (n12 * n33 - n13 * n32) + n02 * (n13 * n31 - n11 * n33) + n03 * (n11 * n32 - n12 * n31)) * t,
		(n01 * (n13 * n22 - n12 * n23) + n02 * (n11 * n23 - n13 * n21) + n03 * (n12 * n21 - n11 * n22)) * t,
		p10 * t,
		(n00 * (n22 * n33 - n23 * n32) + n02 * (n23 * n30 - n20 * n33) + n03 * (n20 * n32 - n22 * n30)) * t,
		(n00 * (n13 * n32 - n12 * n33) + n02 * (n10 * n33 - n13 * n30) + n03 * (n12 * n30 - n10 * n32)) * t,
		(n00 * (n12 * n23 - n13 * n22) + n02 * (n13 * n20 - n10 * n23) + n03 * (n10 * n22 - n12 * n20)) * t,
		p20 * t,
		(n00 * (n23 * n31 - n21 * n33) + n01 * (n20 * n33 - n23 * n30) + n03 * (n21 * n30 - n20 * n31)) * t,
		(n00 * (n11 * n33 - n13 * n31) + n01 * (n13 * n30 - n10 * n33) + n03 * (n10 * n31 - n11 * n30)) * t,
		(n00 * (n13 * n21 - n11 * n23) + n01 * (n10 * n23 - n13 * n20) + n03 * (n11 * n20 - n10 * n21)) * t,
		p30 * t,
		(n00 * (n21 * n32 - n22 * n31) + n01 * (n22 * n30 - n20 * n32) + n02 * (n20 * n31 - n21 * n30)) * t,
		(n00 * (n12 * n31 - n11 * n32) + n01 * (n10 * n32 - n12 * n30) + n02 * (n11 * n30 - n10 * n31)) * t,
		(n00 * (n11 * n22 - n12 * n21) + n01 * (n12 * n20 - n10 * n22) + n02 * (n10 * n21 - n11 * n20)) * t));
}

Matrix4 Adjugate(const Matrix4& m)
{
	float n00 = m(0, 0);
	float n01 = m(0, 1);
	float n02 = m(0, 2);
	float n03 = m(0, 3);
	float n10 = m(1, 0);
	float n11 = m(1, 1);
	float n12 = m(1, 2);
	float n13 = m(1, 3);
	float n20 = m(2, 0);
	float n21 = m(2, 1);
	float n22 = m(2, 2);
	float n23 = m(2, 3);
	float n30 = m(3, 0);
	float n31 = m(3, 1);
	float n32 = m(3, 2);
	float n33 = m(3, 3);
	//this shit takes so long to write out
	return (Matrix4(n11 * (n22 * n33 - n23 * n32) + n12 * (n23 * n31 - n21 * n33) + n13 * (n21 * n32 - n22 * n31),
					n01 * (n23 * n32 - n22 * n33) + n02 * (n21 * n33 - n23 * n31) + n03 * (n22 * n31 - n21 * n32),
					n01 * (n12 * n33 - n13 * n32) + n02 * (n13 * n31 - n11 * n33) + n03 * (n11 * n32 - n12 * n31),
					n01 * (n13 * n22 - n12 * n23) + n02 * (n11 * n23 - n13 * n21) + n03 * (n12 * n21 - n11 * n22),
					n10 * (n23 * n32 - n22 * n33) + n12 * (n20 * n33 - n23 * n30) + n13 * (n22 * n30 - n20 * n32),
					n00 * (n22 * n33 - n23 * n32) + n02 * (n23 * n30 - n20 * n33) + n03 * (n20 * n32 - n22 * n30),
					n00 * (n13 * n32 - n12 * n33) + n02 * (n10 * n33 - n13 * n30) + n03 * (n12 * n30 - n10 * n32),
					n00 * (n12 * n23 - n13 * n22) + n02 * (n13 * n20 - n10 * n23) + n03 * (n10 * n22 - n12 * n20),
					n10 * (n21 * n33 - n23 * n31) + n11 * (n23 * n30 - n20 * n33) + n13 * (n20 * n31 - n21 * n30),
					n00 * (n23 * n31 - n21 * n33) + n01 * (n20 * n33 - n23 * n30) + n03 * (n21 * n30 - n20 * n31),
					n00 * (n11 * n33 - n13 * n31) + n01 * (n13 * n30 - n10 * n33) + n03 * (n10 * n31 - n11 * n30),
					n00 * (n13 * n21 - n11 * n23) + n01 * (n10 * n23 - n13 * n20) + n03 * (n11 * n20 - n10 * n21),
					n10 * (n22 * n31 - n21 * n32) + n11 * (n20 * n32 - n22 * n30) + n12 * (n21 * n30 - n20 * n31),
					n00 * (n21 * n32 - n22 * n31) + n01 * (n22 * n30 - n20 * n32) + n02 * (n20 * n31 - n21 * n30),
					n00 * (n12 * n31 - n11 * n32) + n01 * (n10 * n32 - n12 * n30) + n02 * (n11 * n30 - n10 * n31),
					n00 * (n11 * n22 - n12 * n21) + n01 * (n12 * n20 - n10 * n22) + n02 * (n10 * n21 - n11 * n20)));
}

Matrix4 Transpose(const Matrix4& m)
{
	return (Matrix4(m(0, 0), m(1, 0), m(2, 0), m(3, 0), m(0, 1), m(1, 1), m(2, 1), m(3, 1), m(0, 2), m(1, 2), m(2, 2), m(3, 2), m(0, 3), m(1, 3), m(2, 3), m(3, 3)));
}
