
#include<list>
#include "map.h"

using namespace std;

class Layer {
public:
    virtual float* step_forward(float* src);
};

class CPLayer : Layer {
public:
    virtual float *step_forward(float *src) override;

private:
    list<CPMap> maps;
};