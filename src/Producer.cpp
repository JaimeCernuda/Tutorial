//
// Created by jaime on 9/11/2023.
//

#include "mpi_class.h"
#include <iostream>
#include <vector>

int main() {
    MPIClass mpi_obj;

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto squared_numbers = mpi_obj.distributeAndCollect(numbers);

    std::cout << "Original numbers: ";
    for (const auto &num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Squared numbers: ";
    for (const auto &num : squared_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
