//
// Created by jaime on 9/11/2023.
//

#ifndef TUTORIAL_MPI_H
#define TUTORIAL_MPI_H
#include <vector>

namespace tutorial {
    class MPI {
    public:
        std::vector<int> distributeAndCollect(const std::vector<int> &numbers);

        void processNumbers();

        // Separate out the squaring function for testing
        static int square(int number);
    };
} // namespace tutorial

#endif //TUTORIAL_MPI_H
