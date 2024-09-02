#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Function to calculate ratios
std::vector<double> calculateRatios(const std::vector<int>& arr) {
    std::vector<double> ratios(arr.size());
    int max_value = *std::max_element(arr.begin(), arr.end());
    
    for (size_t i = 0; i < arr.size(); ++i) {
        ratios[i] = (static_cast<double>(arr[i]) / max_value) * arr.size();
    }
    
    return ratios;
}

// Function to perform bucket sort by ratios
std::vector<int> bucketSortByRatios(const std::vector<int>& arr) {
    // Calculate ratios
    std::vector<double> ratios = calculateRatios(arr);
    
    // Number of buckets is the size of the array
    size_t num_buckets = arr.size();
    
    // Create buckets as vectors
    std::vector<std::vector<int>> buckets(num_buckets);
    
    // Place each element into its corresponding bucket
    for (size_t i = 0; i < arr.size(); ++i) {
        int index = static_cast<int>(ratios[i]);
        if (index >= num_buckets) {
            index = num_buckets - 1;
        }
        buckets[index].push_back(arr[i]);
    }
    
    // Collect the elements from buckets into the sorted list
    std::vector<int> sorted_elements;
    for (const auto& bucket : buckets) {
        sorted_elements.insert(sorted_elements.end(), bucket.begin(), bucket.end());
    }
    
    return sorted_elements;
}

int main() {
    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Generate a random unsorted list
    size_t size = 1000000;
    std::vector<int> unsorted_list(size);
    for (size_t i = 0; i < size; ++i) {
        unsorted_list[i] = std::rand() % 1000000 + 1;
    }

    // Start timer
    clock_t start_time = clock();

    // Sort the list
    std::vector<int> sorted_list = bucketSortByRatios(unsorted_list);

    // End timer
    clock_t end_time = clock();

    // Calculate time taken
    double time_taken = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // Print results
    std::cout << "Time taken to sort: " << time_taken << " seconds" << std::endl;
    std::cout << "Length of unsorted list: " << unsorted_list.size() << std::endl;
    std::cout << "Length of sorted list: " << sorted_list.size() << std::endl;

    // Uncomment the following lines if you want to print the sorted list
    // std::cout << "Sorted List:" << std::endl;
    // for (const auto& num : sorted_list) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    return 0;
}