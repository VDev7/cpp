#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>
#include <vector>
#include <string>
#include <random>

namespace cpp
{
    template <typename T>
    bool is_sorted(const T a);

    template <typename T>
    void shuffle(std::vector<T>& a);

    template <typename T>
    void print_vector(const std::vector<T> a);

    template<typename T>
    int linear_search(std::vector<T> a);

    template<typename T>
    int binary_search(std::vector<T> a);

    template<typename T>
    void bubble_sort(std::vector<T>& a);

    template <typename T>
    void selection_sort(std::vector<T>& a);

    template <typename T>
    void insertion_sort(std::vector<T>& a);
}

#endif
