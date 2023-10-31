cmake_minimum_required(VERSION 3.16)

project(pdfops)

# set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)

link_directories(/usr/local/lib/)
include_directories(/usr/include/poppler)

file(GLOB LIBPDFOPS_SOURCES "src/PdfOps.cpp")

add_library(libpdfops STATIC ${LIBPDFOPS_SOURCES})
target_include_directories(libpdfops PUBLIC include)

file(GLOB UNITEPDF_SOURCES "src/unitepdf.cpp")

add_executable(unitepdf ${UNITEPDF_SOURCES})

target_link_libraries(unitepdf libpdfops poppler)
