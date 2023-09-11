find_package(GTest REQUIRED)

add_executable(mpi_tests mpi_tests.cpp)
target_link_libraries(mpi_tests PRIVATE
        GTest::gtest_main
        mpi_class)

add_test(NAME test_mpi_class COMMAND test_mpi_class)
