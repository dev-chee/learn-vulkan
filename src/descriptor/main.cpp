#include "application.h"
#include <iostream>
#include <stdexcept>

int main(int argc, const char *argv[])
{
    std::string dir(argv[0]);
    size_t pos = dir.find_last_of("\\/");
    dir = (std::string::npos == pos) ? "." : dir.substr(0, pos);

    Application app(std::move(dir));

    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}