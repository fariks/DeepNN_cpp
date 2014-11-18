#include "header.h"

class CPMap {
public:
    float *compute_output(float **source, size2 source_size, int source_count);
    float *compute_error(float** weights, float* errors);
    void update_weights();

    CPMap(float *shared_weights, size2 const &shared_weights_size, size2 const &map_size, size2 const &pool_window_size)
            : shared_weights(shared_weights),
              shared_weights_size(shared_weights_size),
              map_size(map_size),
              pool_window_size(pool_window_size) {
        pool_size = {map_size.x / pool_window_size.x, map_size.y / pool_window_size.y};
        map_input = new float[map_size.size()];
        map_output = new float[map_size.size()];
        computed_error = new float[map_size.size()];
        pool_output = new float[pool_size.size()];
        pool_input_indexes = new int[pool_size.size()];
    }

private:
    float shared_weights[], map_input[], map_output[], computed_error[], pool_output[];
    size2 map_size, pool_size, shared_weights_size, pool_window_size;
    int pool_input_indexes[];

    void compute_map_output(float **source, size2 source_size, int source_count);
    void compute_pool_output();
};