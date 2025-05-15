#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>
#include <vector>

namespace cpp
{
    template <typename T>
    bool is_sorted(const T a)
    {
        bool is_ascending = 1;
        bool is_descending = 1;
    
        for (size_t i = 0; i < a.size() - 1; i++)
        {
            if (a[i] > a[i + 1]) is_ascending = 0;
            if (a[i] < a[i + 1]) is_descending = 0;
        }
    
        if (is_debugging)
        {
            if (is_ascending) std::cout << "The container is sorted and ascending" << '\n';
            else if (is_descending) std::cout << "The container is sorted and descending" << '\n';
            else std::cout << "The a isn't sorted" << '\n';
        }
    
        return is_ascending || is_descending;
    }

    template <typename T>
    void print_vector(const std::vector<T> a)
    {
        std::cout << "[";
    
        for (size_t i = 0; i < a.size(); i++)
        {
            std::cout << a[i];
    
            if (i != a.size() - 1) std::cout << ", ";
        }
    
        std::cout << "]" << '\n';
    }

    template <typename T>
    int linear_search(std::vector<T> a)
    {
        int n = a.size();
        T input;
    
        std::cout << "linear_search::input: ";
        std::cin >> input;
    
        for (int i = 0; i < n; i++)
        {
            if (a[i] == input)
            {
                std::cout << input << " Found at index number " << i << '\n';
                return i;
            }
        }
    
        std::cout << input << " Can't be found" << '\n';
        return 0;
    }

    template <typename T>
    int binary_search(std::vector<T> a)
    {
        int l = 0;
        int r = a.size() - 1;
        T input;
    
        if (!is_sorted(a))
        {
            std::cout << "binary_search::Container isn't sorted, unable to search" << '\n';
    
            return 0;
        }
    
        std::cout << "binary_search::Input data: ";
        std::cin >> input;
    
        while (l <= r)
        {
            int m = l + (r - l) / 2;
    
            if (a[m] == input)
            {
                std::cout << input << " Found at index number " << m << '\n';
                return m;
            }
    
            else if (a[m] < input) l = m + 1;
            else r = m - 1;
        }
    
        std::cout << input << " Can't be found" << '\n';
        return 0;
    }

    template<typename T>
    void bubble_sort(std::vector<T>& a)
    {
        bool is_swapped;
    
        for (size_t i = 0; i < a.size() - 1; i++)
        {
            is_swapped = 0;
    
            for (size_t j = 0; j < a.size() - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    T temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
    
                    is_swapped = 1;
    
                    if (is_debugging) print_vector(a);
                }
            }
    
            if (!is_swapped) break;
        }
    }

    template <typename T>
    void selection_sort(std::vector<T>& a)
    {
        int n = a.size();
    
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
    
            for (int j = i + 1; j < n; j++) if (a[j] < a[min]) min = j;
    
            T temp = a[i];
            a[i] = a[min];
            a[min] = temp;
    
            if (is_debugging) print_vector(a);
        }
    }

    template <typename T>
    void insertion_sort(std::vector<T>& a)
    {
        int n = a.size();
    
        for(int i = 1; i < n; i++)
        {
            T key = a[i];
            int j = i - 1;
    
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                --j;
            }
    
            a[j + 1] = key;
            if (is_debugging) print_vector(a);
        }
    }
}

#endif
