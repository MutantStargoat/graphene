#include <math.h>

namespace gph {

#undef GPH_SWIZZLE2
#undef GPH_SWIZZLE3
#undef GPH_SWIZZLE4
#define GPH_SWIZZLE2(T, a, b)		inline Vector2 T::a##b() const { return Vector2(a, b); }
#define GPH_SWIZZLE3(T, a, b, c)	inline Vector3 T::a##b##c() const { return Vector3(a, b, c); }
#define GPH_SWIZZLE4(T, a, b, c, d)	inline Vector4 T::a##b##c##d() const { return Vector4(a, b, c, d); }

// ---- Vector3 ----

inline void Vector3::normalize()
{
	float len = (float)sqrt(x * x + y * y + z * z);
	if(len != 0.0f) {
		x /= len;
		y /= len;
		z /= len;
	}
}

inline float &Vector3::operator[] (int idx)
{
	return idx == 0 ? x : (idx == 1 ? y : z);
}

inline const float &Vector3::operator[] (int idx) const
{
	return idx == 0 ? x : (idx == 1 ? y : z);
}

inline Vector3 operator +(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector3 operator -(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Vector3 operator *(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

inline Vector3 operator /(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.x / b.x, a.y / b.y, a.z / b.z);
}

inline Vector3 operator *(const Vector3 &v, float s)
{
	return Vector3(v.x * s, v.y * s, v.z * s);
}

inline Vector3 operator *(float s, const Vector3 &v)
{
	return Vector3(s * v.x, s * v.y, s * v.z);
}

inline Vector3 operator /(const Vector3 &v, float s)
{
	return Vector3(v.x / s, v.y / s, v.z / s);
}

inline Vector3 operator /(float s, const Vector3 &v)
{
	return Vector3(s / v.x, s / v.y, s / v.z);
}

inline Vector3 &operator +=(Vector3 &a, const Vector3 &b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}

inline Vector3 &operator -=(Vector3 &a, const Vector3 &b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

inline Vector3 &operator *=(Vector3 &a, const Vector3 &b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}

inline Vector3 &operator /=(Vector3 &a, const Vector3 &b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline Vector3 &operator *=(Vector3 &v, float s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	return v;
}

inline Vector3 &operator /=(Vector3 &v, float s)
{
	v.x /= s;
	v.y /= s;
	v.z /= s;
	return v;
}

inline bool operator ==(const Vector3 &a, const Vector3 &b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

inline bool operator !=(const Vector3 &a, const Vector3 &b)
{
	return !(a == b);
}

inline float dot(const Vector3 &a, const Vector3 &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Vector3 cross(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
}

inline float length(const Vector3 &v)
{
	return (float)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline float length_sq(const Vector3 &v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline Vector3 normalize(const Vector3 &v)
{
	float len = length(v);
	if(len == 0.0f) {
		return v;
	}

	return Vector3(v.x / len, v.y / len, v.z / len);
}

inline Vector3 reflect(const Vector3 &v, const Vector3 &n)
{
	return v - n * dot(n, v) * 2.0;
}

inline Vector3 refract(const Vector3 &v, const Vector3 &n, float ior)
{
	float ndotv = dot(n, v);
	float k = 1.0f - ior * ior * (1.0f - ndotv * ndotv);
	if(k < 0.0f) {
		return Vector3();
	}
	return ior * v - (ior * ndotv + sqrt(k)) * n;
}

inline Vector3 refract(const Vector3 &v, const Vector3 &n, float from_ior, float to_ior)
{
	if(to_ior == 0.0f) to_ior = 1.0f;
	return refract(v, n, from_ior / to_ior);
}

inline Vector3 distance(const Vector3 &a, const Vector3 &b)
{
	return length(a - b);
}

inline Vector3 distance_sq(const Vector3 &a, const Vector3 &b)
{
	return length_sq(a - b);
}

inline Vector3 faceforward(const Vector3 &n, const Vector3 &vi, const Vector3 &ng)
{
	return dot(ng, i) < 0.0f ? n : -n;
}

inline Vector3 major(const Vector3 &v)
{
	int m = major_idx(v);
	Vector3 res;
	res[m] = v[m];
	return res;
}

inline int major_idx(const Vector3 &v)
{
	return fabs(v.x) >= fabs(v.y) && fabs(v.x) > fabs(v.z) ? 0 :
		(fabs(v.y) >= fabs(v.z) ? 1 : 2);
}

inline Vector3 proj_axis(const Vector3 &v, const Vector3 &axis)
{
	return axis * dot(v, axis);
}


inline Vector3 rotate(const Vector3 &v, const Quaternion &q)
{
	return v;	// TODO
}

inline Vector3 rotate(const Vector3 &v, const Vector3 &axis, float angle)
{
	return v;	// TODO
}

inline Vector3 rotate(const Vector3 &v, const Vector3 &euler)
{
	return v;	// TODO
}


GPH_VEC3_SWIZZLE

// ---- Vector4 ----


inline void Vector4::normalize()
{
	float len = (float)sqrt(x * x + y * y + z * z + w * w);
	if(len != 0.0f) {
		x /= len;
		y /= len;
		z /= len;
		w /= len;
	}
}

inline float &Vector4::operator[] (int idx)
{
	return idx == 0 ? x : (idx == 1 ? y : (idx == 2 ? z : w));
}

inline const float &Vector4::operator[] (int idx) const
{
	return idx == 0 ? x : (idx == 1 ? y : (idx == 2 ? z : w));
}

GPH_VEC4_SWIZZLE

// ---- Vector2 ----

inline void Vector2::normalize()
{
	float len = (float)sqrt(x * x + y * y);
	if(len != 0.0f) {
		x /= len;
		y /= len;
	}
}

inline float &Vector2::operator[] (int idx)
{
	return idx == 0 ? x : y;
}

inline const float &Vector2::operator[] (int idx) const
{
	return idx == 0 ? x : y;
}

GPH_VEC2_SWIZZLE

}	// namespace gph
