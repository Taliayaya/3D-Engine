#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

namespace Math
{

    class Vector3
    {
    public:
        float x{};
        float y{};
        float z{};

        static const Vector3 zero;

        // Shortcut for (0, 1, 0)
        static const Vector3 up;
        // Shortcut for (1, 0, 0)
        static const Vector3 right;
        // Shortcut for (0, 0, 1)
        static const Vector3 forward;

        // Opposite

        // Shortcut for (0, -1, 0)
        static const Vector3 down;
        // Shortcut for (-1, 0, 0)
        static const Vector3 left;
        // Shortcut for (0, 0, -1)
        static const Vector3 backward;

        constexpr Vector3(float x, float y, float z) : x{x}, y{y}, z{z}
        {
        }

        void Print() const;

        constexpr float Magnitude() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        constexpr void Negate()
        {
            x = -x;
            y = -y;
            z = -z;
        };

        constexpr Vector3 Negated() const
        {
            return {-x, -y, -z};
        }

        constexpr void Normalize()
        {
            float magn = Magnitude();
            if (magn == 0)
                return;
            x /= magn;
            y /= magn;
            z /= magn;
        }

        constexpr Vector3 Normalized() const
        {
            float magn = Magnitude();
            if (magn == 0)
                return {0.0f, 0.0f, 0.0f};
            return {
                x / magn,
                y / magn,
                z / magn};
        }

        constexpr float Dot(const Vector3 &other) const
        {
            return {
                x * other.x +
                y * other.y +
                z * other.z};
        }

        constexpr Vector3 Cross(const Vector3 &other) const
        {
            return {
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x};
        }

        constexpr Vector3 &operator+=(const Vector3 &other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        constexpr Vector3 &operator-=(const Vector3 &other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &stream, Vector3 const &v);
    };

    static constexpr bool operator==(const Vector3 &vleft, const Vector3 &vright)
    {
        return {vleft.x == vright.x && vleft.y == vright.y && vleft.z == vright.z};
    }

    static constexpr Vector3 operator+(const Vector3 &vleft, const Vector3 &vright)
    {
        return {
            vleft.x + vright.x,
            vleft.y + vright.y,
            vleft.z + vright.z};
    }

    static constexpr Vector3 operator-(const Vector3 &vleft, const Vector3 &vright)
    {
        return {
            vleft.x - vright.x,
            vleft.y - vright.y,
            vleft.z - vright.z};
    }

    static constexpr Vector3 operator*(const Vector3 &vleft, float a)
    {
        return {
            vleft.x * a,
            vleft.y * a,
            vleft.z * a};
    }

    static constexpr Vector3 operator*(float a, const Vector3 &vright)
    {
        return {
            vright.x * a,
            vright.y * a,
            vright.z * a};
    }

    static constexpr float operator*(const Vector3 &vleft, const Vector3 &vright)
    {
        return {vleft.Dot(vright)};
    }

}

#endif