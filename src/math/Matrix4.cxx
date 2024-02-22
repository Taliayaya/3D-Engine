#include "Matrix4.h"

namespace Math
{
    void Matrix4::Print() const
    {
        for (std::size_t i{0}; i < 4; ++i)
        {
            std::cout << "| ";
            for (std::size_t j{0}; j < 4; ++j)
                std::cout
                    << matrix[i][j] << " ";
            std::cout << "|\n";
        }
    }
    Matrix4 &Matrix4::Negate()
    {
        for (std::size_t i{0}; i < 4; ++i)
            for (std::size_t j{0}; j < 4; ++j)
                matrix[i][j] = -matrix[i][j];
        return *this;
    }
    Matrix4 &Matrix4::Transpose()
    {
        for (std::size_t i{0}; i < 4; ++i)
            for (std::size_t j{i}; j < 4; ++j)
                std::swap<float>(matrix[i][j], matrix[j][i]);
        return *this;
    }

    Matrix4 Matrix4::Translate(const Vector3 &translation) const
    {
        Matrix4 translateMatrix{Matrix4(1.f)};
        translateMatrix[0, 3] += translation.x;
        translateMatrix[1, 3] += translation.y;
        translateMatrix[2, 3] += translation.z;
        translateMatrix[3, 3] = 1.f;
        return *this * translateMatrix;
    }
    Matrix4 Matrix4::Rotate(float angle, const Vector3 &axis) const
    {
        Matrix4 rotateMatrix{};
        float cos_a{std::cos(angle)};
        float sin_a{std::sin(angle)};

        auto norm_axis = axis.Normalized();
        float x{norm_axis.x};
        float y{norm_axis.y};
        float z{norm_axis.z};

        float x_sq{x * x};
        // first row
        rotateMatrix[0, 0] = x_sq + (1 - x_sq) * cos_a;
        rotateMatrix[0, 1] = x * y * (1 - cos_a) - z * sin_a;
        rotateMatrix[0, 2] = x * z * (1 - cos_a) + y * sin_a;

        float y_sq{y * y};
        // second row
        rotateMatrix[1, 0] = x * y * (1 - cos_a) + z * sin_a;
        rotateMatrix[1, 1] = y_sq + (1 - y_sq) * cos_a;
        rotateMatrix[1, 2] = y * z * (1 - cos_a) - x * sin_a;

        float z_sq{z * z};
        // third row
        rotateMatrix[2, 0] = x * z * (1 - cos_a) - y * sin_a;
        rotateMatrix[2, 1] = y * z * (1 - cos_a) + x * sin_a;
        rotateMatrix[2, 2] = z_sq + (1 - z_sq) * cos_a;

        rotateMatrix[3, 3] = 1.f;
        return *this * rotateMatrix;
    }
    Matrix4 Matrix4::Scale(const Vector3 &scaling) const
    {
        Matrix4 scaleMatrix{};
        scaleMatrix[0, 0] = scaling.x;
        scaleMatrix[1, 1] = scaling.y;
        scaleMatrix[2, 2] = scaling.z;
        scaleMatrix[3, 3] = 1;
        return *this * scaleMatrix;
    }
    Matrix4 operator+(const Matrix4 &left, const Matrix4 &right)
    {
        Matrix4 sum{};

        for (std::size_t i{0}; i < 4; ++i)
            for (std::size_t j{0}; j < 4; ++j)
                sum[i, j] = left[i, j] + right[i, j];
        return sum;
    }

    Matrix4 operator*(const Matrix4 &left, const Matrix4 &right)
    {
        Matrix4 product{};

        for (std::size_t i{0}; i < 4; ++i)
            for (std::size_t j{0}; j < 4; ++j)
                for (std::size_t k{0}; k < 4; ++k)
                    product[i, j] = left[i, k] * right[k, j];
        return product;
    }

}