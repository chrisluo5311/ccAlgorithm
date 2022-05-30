cmake_minimum_required(VERSION 3.21)
project(cpractice C)

set(CMAKE_C_STANDARD 99)

add_executable(cpractice main.c maxmin.h binarysearch.h mergesort.h insertionsort.h util.h quicksort.h selectionsort.h
        activityselection.h knapsack.h jobsequence.h jobsequence_disjointset.h prime_mst.h containerloading.h kruskalAlgo.h optimalStorageOnTape.h singleSourceShortestPath.h)
