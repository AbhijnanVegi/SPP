cmake_minimum_required(VERSION 3.4)

project(blis)

add_executable(blis src/blis.c)
target_include_directories(blis PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(BLA_VENDOR FLAME)
find_package( BLAS REQUIRED )
message( STATUS BLAS found: ${BLAS_LIBRARIES} )
target_link_libraries(blis ${BLAS_LIBRARIES})
target_link_libraries(blis m)