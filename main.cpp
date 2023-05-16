#include <iostream>
#include <vector>
#include <cstring>

extern "C" {
std::vector<int>* process_string(const char* input);
size_t get_result_size(const std::vector<int>* result);
const int* get_result_data(const std::vector<int>* result);
void free_result(std::vector<int>* result);
}

int main() {
    // Call the Rust function
    const char* input = "Hello, Rust!";
    std::vector<int>* result = process_string(input);

    if (result) {
        // Get the size of the result vector
        size_t result_size = get_result_size(result);

        // Access and print the vector elements
        const int* result_data = get_result_data(result);
        for (size_t i = 0; i < result_size; ++i) {
            std::cout << result_data[i] << " ";
        }
        std::cout << std::endl;

        // Free the allocated vector memory
        free_result(result);
    } else {
        std::cout << "Error occurred while calling the Rust function." << std::endl;
    }

    return 0;
}
