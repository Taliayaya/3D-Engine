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

    Matrix4 &Matrix4::Translate()
    {
        // TODO: insert return statement here
    }
    Matrix4 &Matrix4::Rotate()
    {
        // TODO: insert return statement here
    }
    Matrix4 &Matrix4::Scale()
    {
        // TODO: insert return statement here
    }
}