#ifndef MATRIX4_H
#define MATRIX4_H

#include <array>
#include <iostream>
#include <cmath>

#include "Vector3.h"

namespace Math
{
    class Matrix4
    {
        using Array4x4 = std::array<std::array<float, 4>, 4>;
        Array4x4 matrix{};

    public:
        Matrix4()
        {
        }

        Matrix4(float eigen)
        {
            for (std::size_t i{0}; i < 4; ++i)
                matrix[i][i] = eigen;
        }

        Matrix4(const Matrix4 &&matrix4) noexcept : matrix{matrix4.matrix}
        {
        }

        void Print() const;
        Matrix4 &Negate();
        Matrix4 &Transpose();

        Matrix4 Translate(const Vector3 &translation) const;
        Matrix4 Rotate(float angle, const Vector3 &rotation) const;
        Matrix4 Scale(const Vector3 &scaling) const;

        const float &operator[](std::size_t row, std::size_t col) const
        {
            return matrix[row][col];
        }
        float &operator[](std::size_t row, std::size_t col)
        {
            return matrix[row][col];
        }
    };

    Matrix4 operator+(const Matrix4 &left, const Matrix4 &right);
    Matrix4 operator*(const Matrix4 &left, const Matrix4 &right);
}
#endif