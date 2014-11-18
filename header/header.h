#include <math.h>

struct size2 {
public:
    const int x, y;
    int size() const {
        return x * y;
    };
};

float f(float x)
{
    return (float) (1.f / (1.f + exp(-x)));
}

float df(float x)
{
    float tmp = f(x);
    return tmp * (1 - tmp);
}
