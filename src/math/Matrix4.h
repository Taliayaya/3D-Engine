#ifndef MATRIX4_H
#define MATRIX4_H

#include <array>
#include <iostream>
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

        void Print() const;
        Matrix4 &Negate();
        Matrix4 &Transpose();

        Matrix4 &Translate();
        Matrix4 &Rotate();
        Matrix4 &Scale();

        float operator[](std::size_t row, std::size_t col) const
        {
            return matrix[row][col];
        }
    };
}
#endif