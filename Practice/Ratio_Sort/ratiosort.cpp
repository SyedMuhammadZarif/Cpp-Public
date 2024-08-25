#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cmath>   // For round()
#include <limits>  // For numeric_limits

int main() {
    // Seed for random number generation
    std::srand(std::time(0));

    // Generate the list with random integers
    const int SIZE = 100000;
    std::vector<int> list(SIZE);
    for (int &num : list) {
        num = std::rand() % 1000000 + 1;
    }

    // Find the maximum value in the list
    int max = 0;
    int lth = 0;
    for (int num : list) {
        lth++;
        if (num > max) {
            max = num;
        }
    }

    // Initialize arrays
    std::vector<int> ar4(max + 1, 0);
    const int NONE = std::numeric_limits<int>::min(); // Sentinel value
    std::vector<int> ar2(static_cast<int>(std::round(max * 1.25)), NONE);

    // Process the list and populate ar2 and ar4
    for (int num : list) {
        int temp = static_cast<int>(std::round(static_cast<double>(num) / max * lth));
        if (ar2[temp] == num) {
            ar4[num]++;
            ar2[temp + ar4[num]] = num;
        } else {
            ar2[temp] = num;
        }
    }

    // Collect results
    std::vector<int> ar3;
    for (int i : ar2) {
        if (i != NONE) {
            ar3.push_back(i);
        }
    }

    // Print the results
    std::cout << "Sorted list: \n";
    for (int num : ar3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
