cmake_minimum_required(VERSION 3.19)
project(CLion)

set(CMAKE_CXX_STANDARD 14)

add_executable(CLion main.cpp graph.cpp graph.h node.cpp node.h tree.cpp tree.h SegmentTree.cpp SegmentTree.h path.cpp path.h shallowTree.cpp shallowTree.h dataStructure.cpp dataStructure.h DynamicDFS.cpp DynamicDFS.h)