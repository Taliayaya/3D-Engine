#include <iostream>

#include "./math/Vector3.h"
#include "./math/Matrix4.h"
#include "config.h"

int main()
{
    std::cout << "Hello World: " << Engine_VERSION_MAJOR << "\n";
    Math::Matrix4 matrix{};
    matrix.Print();
    Math::Matrix4 matrix2{Math::Matrix4(5)};
    matrix2.Print();
    return 0;
}