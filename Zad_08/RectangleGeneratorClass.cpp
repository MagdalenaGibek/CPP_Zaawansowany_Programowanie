#include "RectangleGeneratorClass.hpp"
#include <random>

RectangleGenerator::RectangleGenerator(unsigned int sizeFrom, unsigned int sizeTo)
    :_sizeFrom(sizeFrom), _sizeTo(sizeTo)
{
}

Rectangle RectangleGenerator::generate()
{
    std::random_device r;
    std::default_random_engine defEngine(r());
    std::uniform_int_distribution<int> intDistro(_sizeFrom, _sizeTo);
    int a = intDistro(defEngine);
    int b = intDistro(defEngine);
    
    Rectangle rect(a,b);
    return rect;
}
