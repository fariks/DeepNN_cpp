#include "../header/map.h"

float* CPMap::compute_output(float** source, size2 source_size, int source_count) {
    compute_map_output(source, source_size, source_count);
    compute_pool_output();
    return pool_output;
}

void CPMap::compute_map_output(float** source, size2 source_size, int source_count) {
    for (int ix = 0; ix < map_size.x; ix++) {
        for (int iy = 0; iy < map_size.y; iy++) {
            float sum = 0.f;
            for (int m = 0; m < source_count; m++) {
                for (int jx = 0; jx < weights_size.x; jx++) {
                    for (int jy = 0; jy < weights_size.y; jy++) {
                        sum += weights[jx * weights_size.y + jy] *
                                source[m][ix * source_size.y + iy + jx * source_size.y + jy];
                    }
                }
            }
            sum += bias;
            map_input[ix * map_size.y + iy] = sum;
            map_output[ix * map_size.y + iy] = f(sum);
        }
    }
}

void CPMap::compute_pool_output() {
    for (int ix = 0, kx = 0; ix < map_size.x; ix += pool_size.x, kx++) {
        for (int iy = 0, ky = 0; iy < map_size.y; iy += pool_size.y, ky++) {
            int index = ix * map_size.y + iy;
            float max = map_output[index];
            for (int jx = ix; jx < map_size.x && jx < ix + pool_size.x; jx++) {
                for (int jy = iy; jy < map_size.y && jy < iy + pool_size.y; jy++) {
                    if (map_output[jx * map_size.y + jy] > max) {
                        index = jx * map_size.y + jy;
                        max = map_output[index];
                    }
                }
            }
            pool_output[kx * pool_size.y + ky] = max;
            pool_input_indexes[kx * pool_size.y + ky] = index;
        }
    }
}
