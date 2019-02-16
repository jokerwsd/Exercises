cmake_minimum_required(VERSION 3.0)
project(BiTree)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-m64 -march=native -O3 -ggdb3")

get_filename_component(BITREE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" REALPATH)

include_directories(
	${BITREE_DIR}
	${BITREE_DIR}/include
	)

add_executable(BiTree_Tests
	${BITREE_DIR}/bi_tree.cpp
        ${BITREE_DIR}/include/bi_tree.h
	${BITREE_DIR}/bi_tree_tests.cpp
	)

add_library(BiTree
	${BITREE_DIR}/bi_tree.cpp
	)

install(TARGETS BiTree_Tests DESTINATION bin COMPONENT applications)
