#include "../header/map.h"

float *CPMap::compute_output(float **source, size2 source_size, int source_count) {
    compute_map_output(source, source_size, source_count);
    compute_pool_output();
    return pool_output;
}

void CPMap::compute_map_output(float **source, size2 source_size, int source_count) {

}

void CPMap::compute_pool_output() {

}
