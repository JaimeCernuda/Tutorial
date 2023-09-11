//
// Created by jaime on 9/11/2023.
//

#include <gtest/gtest.h>
#include "mpi_class.h"

TEST(MPIClassTest, TestSquaringFunction) {
EXPECT_EQ(MPIClass::square(0), 0);
EXPECT_EQ(MPIClass::square(5), 25);
EXPECT_EQ(MPIClass::square(-3), 9); // Squaring a negative number should yield a positive result
}

TEST(MPIClassTest, TestDistributeAndCollect) {
MPIClass mpi_obj;

std::vector<int> numbers1 = {1, 2, 3, 4, 5};
std::vector<int> expected1 = {1, 4, 9, 16, 25};
ASSERT_EQ(mpi_obj.distributeAndCollect(numbers1), expected1);

std::vector<int> numbers2 = {-1, -2, -3, -4, -5};
std::vector<int> expected2 = {1, 4, 9, 16, 25};
ASSERT_EQ(mpi_obj.distributeAndCollect(numbers2), expected2);
}

TEST(MPIClassTest, TestFailedDistributeAndCollect) {
MPIClass mpi_obj;

std::vector<int> numbers = {1, 2, 3, 4, 5};
std::vector<int> incorrect_expected = {2, 5, 10, 17, 26};
ASSERT_NE(mpi_obj.distributeAndCollect(numbers), incorrect_expected);
}
