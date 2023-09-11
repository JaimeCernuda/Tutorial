add_library(mpi_class SHARED mpi_class.cpp)
target_include_directories(mpi_class PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(mpi_class PUBLIC MPI::MPI_CXX)

add_executable(producer Producer.cpp)
add_executable(consumer Consumer.cpp)

target_link_libraries(producer mpi_class)
target_link_libraries(consumer mpi_class)