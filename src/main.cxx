#include <iostream>

#include "./math/Vector3.h"
#include "config.h"

int main()
{
    std::cout << "Hello World: " << Engine_VERSION_MAJOR << "\n";

    auto up{Math::Vector3::up};
    std::cout << up;
    return 0;
}