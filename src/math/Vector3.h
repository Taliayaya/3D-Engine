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

        // Right handed
        static const Vector3 up;
        static const Vector3 right;
        static const Vector3 forward;

        // Opposite
        static const Vector3 down;
        static const Vector3 left;
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
        friend std::ostream &operator<<(std::ostream &stream, Vector3 const &v);
    };

    static constexpr bool operator==(const Vector3 &left, const Vector3 &right)
    {
        return {left.x == right.x && left.y == right.y && left.z == right.z};
    }

}

#endif