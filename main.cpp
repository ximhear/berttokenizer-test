#include <iostream>
#include <vector>
#include <cstring>

struct ProcessedResult {
    const int* result_vec;
    size_t result_len;
    const int* mask_vec;
    size_t mask_len;
    std::vector<int> result_box;
    std::vector<int> mask_box;
};

extern "C" {
ProcessedResult* process_string(const char* input);
void free_processed_result(ProcessedResult* result);
}

int main() {
    // Call the Rust function
    const char* input = "Hello, Rust!";
    ProcessedResult* result = process_string(input);

    if (result) {
        // Access and print the result vector elements
        const int* result_data = result->result_vec;
        for (size_t i = 0; i < result->result_len; ++i) {
            std::cout << result_data[i] << " ";
        }
        std::cout << std::endl;

        // Access and print the mask vector elements
        const int* mask_data = result->mask_vec;
        for (size_t i = 0; i < result->mask_len; ++i) {
            std::cout << mask_data[i] << " ";
        }
        std::cout << std::endl;

        // Free the allocated memory
        free_processed_result(result);
    } else {
        std::cout << "Error occurred while calling the Rust function." << std::endl;
    }

    return 0;
}
