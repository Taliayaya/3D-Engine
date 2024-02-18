#include "Vector3.h"

namespace Math
{

    const Vector3 Vector3::zero{Vector3(0.0f, 0.0f, 0.0f)};

    const Vector3 Vector3::up{Vector3(0.0f, 1.0f, 0.0f)};
    const Vector3 Vector3::right{Vector3(1.0f, 0.0f, 0.0f)};
    const Vector3 Vector3::forward{Vector3(0.0f, 0.0f, 1.0f)};

    const Vector3 Vector3::down{Vector3(0.0f, -1.0f, 0.0f)};
    const Vector3 Vector3::left{Vector3(-1.0f, 0.0f, 0.0f)};
    const Vector3 Vector3::backward{Vector3(0.0f, 0.0f, -1.0f)};

    void Vector3::Print() const
    {
        std::cout << "( " << x << ", " << y << ", " << z << " )\n";
    }

    std::ostream &operator<<(std::ostream &stream, Vector3 const &v)
    {
        stream << "( " << v.x << ", " << v.y << ", " << v.z << " )";
        return stream;
    }

} // namespace Math