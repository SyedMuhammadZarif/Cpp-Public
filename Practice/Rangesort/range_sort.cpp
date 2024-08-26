#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(0));

    // Create a very complex array
    std::vector<int> list;
    list.reserve(1000000);
    for (int i = 0; i < 1000000; ++i) {
        list.push_back(std::rand() % 100000000 + 1);
    }

    std::vector<int> ar1;
    ar1.reserve(list.size());
    size_t n = 0;
    double j = 0.0;
    double k = 0.100;
    
    auto start_time = std::clock();

    while (ar1.size() != list.size()) {
        if (j <= list[n] && list[n] <= k) {
            ar1.push_back(list[n]);
            n++;
        }
        j *= 1.125;
        k *= 1.825;
    }

    auto end_time = std::clock();

    for (const auto& num : ar1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Execution time: " << double(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}
