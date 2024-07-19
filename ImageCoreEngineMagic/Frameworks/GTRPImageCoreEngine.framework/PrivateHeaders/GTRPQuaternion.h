//
//  GTRPQuaternion.h
//
//  Created by kesalin@gmail.com on 12-12-14.
//  Copyright (c) 2012年 http://blog.csdn.net/kesalin/. All rights reserved.
//

#pragma once

#include "GTRPVector.h"
#include "GTRPGlesMath.h"

struct GTRPQuaternion
{
    float x;
    float y;
    float z;
    float w;
    
    GTRPQuaternion();
    GTRPQuaternion(float x, float y, float z, float w);
    
    GTRPQuaternion Slerp(float mu, const GTRPQuaternion& q) const;
    GTRPQuaternion Rotated(const GTRPQuaternion& b) const;
    GTRPQuaternion Scaled(float scale) const;
    
    float Dot(const GTRPQuaternion& q) const;
    void ToMatrix4(KSMatrix4 * m) const;
    Vector4<float> ToVector() const;
    void ToIdentity();
    
    GTRPQuaternion operator-(const GTRPQuaternion& q) const;
    GTRPQuaternion operator+(const GTRPQuaternion& q) const;
    bool operator==(const GTRPQuaternion& q) const;
    bool operator!=(const GTRPQuaternion& q) const;
    
    void Normalize();
    void Rotate(const GTRPQuaternion& q);
    
    static GTRPQuaternion CreateFromVectors(const Vector3<float>& v0, const Vector3<float>& v1);
    static GTRPQuaternion CreateFromAxisAngle(const Vector3<float>& axis, float radians);
};

inline GTRPQuaternion::GTRPQuaternion() : x(0), y(0), z(0), w(1)
{}

inline GTRPQuaternion::GTRPQuaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{}

inline void GTRPQuaternion::ToIdentity()
{
    x = y = z = 0;
    w = 1.0;
}

// Ken Shoemake's famous method.
inline GTRPQuaternion GTRPQuaternion::Slerp(float t, const GTRPQuaternion& v1) const
{
    const float epsilon = 0.0005f;
    float dot = Dot(v1);
    
    if (dot > 1 - epsilon) {
        GTRPQuaternion result = v1 + (*this - v1).Scaled(t);
        result.Normalize();
        return result;
    }
    
    if (dot < 0)
        dot = 0;
    
    if (dot > 1)
        dot = 1;
    
    float theta0 = acos(dot);
    float theta = theta0 * t;
    
    GTRPQuaternion v2 = (v1 - Scaled(dot));
    v2.Normalize();
    
    GTRPQuaternion q = Scaled(cos(theta)) + v2.Scaled(sin(theta));
	q.Normalize();
	return q;
}

inline GTRPQuaternion GTRPQuaternion::Rotated(const GTRPQuaternion& b) const
{
    GTRPQuaternion q;
    q.w = w * b.w - x * b.x - y * b.y - z * b.z;
    q.x = w * b.x + x * b.w + y * b.z - z * b.y;
    q.y = w * b.y + y * b.w + z * b.x - x * b.z;
    q.z = w * b.z + z * b.w + x * b.y - y * b.x;
    q.Normalize();
    return q;
}

inline GTRPQuaternion GTRPQuaternion::Scaled(float s) const
{
    return GTRPQuaternion(x * s, y * s, z * s, w * s);
}

inline float GTRPQuaternion::Dot(const GTRPQuaternion& q) const
{
    return x * q.x + y * q.y + z * q.z + w * q.w;
}

inline void GTRPQuaternion::ToMatrix4(KSMatrix4 * result) const
{
    const float s = 2;
    float xs, ys, zs;
    float wx, wy, wz;
    float xx, xy, xz;
    float yy, yz, zz;
    xs = x * s;  ys = y * s;  zs = z * s;
    wx = w * xs; wy = w * ys; wz = w * zs;
    xx = x * xs; xy = x * ys; xz = x * zs;
    yy = y * ys; yz = y * zs; zz = z * zs;
    
    result->m[0][0] = 1 - (yy + zz);
    result->m[0][1] = xy + wz;
    result->m[0][2] = xz - wy;
    result->m[0][3] = 0; 
    
    result->m[1][0] = xy - wz;
    result->m[1][1] = 1 - (xx + zz); 
    result->m[1][2] = yz + wx;
    result->m[1][3] = 0;
    
    result->m[2][0] = xz + wy;
    result->m[2][1] = yz - wx;
    result->m[2][2]= 1 - (xx + yy);
    result->m[2][3] = 0;
    
    result->m[3][0] = 0;
    result->m[3][1] = 0;
    result->m[3][2] = 0;
    result->m[3][3] = 1;
}

inline Vector4<float> GTRPQuaternion::ToVector() const
{
    return Vector4<float>(x, y, z, w);
}

inline GTRPQuaternion GTRPQuaternion::operator-(const GTRPQuaternion& q) const
{
    return GTRPQuaternion(x - q.x, y - q.y, z - q.z, w - q.w);
}

inline GTRPQuaternion GTRPQuaternion::operator+(const GTRPQuaternion& q) const
{
    return GTRPQuaternion(x + q.x, y + q.y, z + q.z, w + q.w);
}

inline bool GTRPQuaternion::operator==(const GTRPQuaternion& q) const
{
    return x == q.x && y == q.y && z == q.z && w == q.w;
}

inline bool GTRPQuaternion::operator!=(const GTRPQuaternion& q) const
{
    return !(*this == q);
}

inline void GTRPQuaternion::Normalize()
{
    *this = Scaled(1 / sqrt(Dot(*this)));
}

inline void GTRPQuaternion::Rotate(const GTRPQuaternion& q2)
{
    GTRPQuaternion q;
    GTRPQuaternion& q1 = *this;
    
    q.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
    q.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
    q.y = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
    q.z = q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x;
    
    q.Normalize();
    *this = q;
}

// Compute the GTRPQuaternion that rotates from a to b, avoiding numerical instability.
// Taken from "The Shortest Arc GTRPQuaternion" by Stan Melax in "Game Programming Gems".
//
inline GTRPQuaternion GTRPQuaternion::CreateFromVectors(const Vector3<float>& v0, const Vector3<float>& v1)
{
    if (v0 == -v1)
        return GTRPQuaternion::CreateFromAxisAngle(vec3(1, 0, 0), Pi);
    
    Vector3<float> c = v0.Cross(v1);
    float d = v0.Dot(v1);
    float s = sqrt((1 + d) * 2);
    
    GTRPQuaternion q;
    q.x = c.x / s;
    q.y = c.y / s;
    q.z = c.z / s;
    q.w = s / 2.0f;
    
    return q;
}

inline GTRPQuaternion GTRPQuaternion::CreateFromAxisAngle(const Vector3<float>& axis, float radians)
{
    GTRPQuaternion q;
    q.w = cos(radians / 2);
    q.x = q.y = q.z = sin(radians / 2);
    q.x *= axis.x;
    q.y *= axis.y;
    q.z *= axis.z;
    
    return q;
}


