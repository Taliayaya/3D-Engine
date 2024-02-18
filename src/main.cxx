# include <iostream>

# include "./math/Vector3.h"
# include "config.h"

int main()
{
    std::cout << "Hello World: " << Engine_VERSION_MAJOR << "\n";
    std::cout << getVersion();
    std::cout << "\nMyVersion: " << MyVersion;
    return 0;
}