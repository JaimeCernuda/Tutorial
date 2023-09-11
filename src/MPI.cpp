//
// Created by jaime on 9/11/2023.
//

#include "mpi_class.h"
#include <mpi.h>
#include <vector>

std::vector<int> MPIClass::distributeAndCollect(const std::vector<int>& numbers) {
    int world_size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::vector<int> squared_numbers(numbers.size());

    if (rank == 0) { // producer
        // Distribute data
        for (int i = 1; i < world_size; ++i) {
            MPI_Send(&numbers[i-1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }

        // Collect squared numbers
        for (int i = 1; i < world_size; ++i) {
            MPI_Recv(&squared_numbers[i-1], 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    } else { // consumers
        int number;
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        square(number); // Square it
        MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    return squared_numbers;
}

void MPIClass::processNumbers() {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank != 0) { // Only consumers do this
        int number;
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        square(number); // Square it
        MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
}


int MPIClass::square(int number) {
    return number * number;
}