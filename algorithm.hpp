#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>
#include <vector>

namespace cpp
{
    template <typename T>
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

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

    template<typename T>
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

    template<typename T>
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
                    swap(a[j], a[j + 1]);

                    is_swapped = 1;
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

            swap(a[i], a[min]);
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
                j--;
            }

            a[j + 1] = key;
        }
    }

    template <typename T>
    int partition(std::vector<T>& a, int l, int h)
    {
        T p = a[h];
        int i = l - 1;

        for (int j = l; j < h; ++j)
        {
            if (a[j] <= p)
            {
                ++i;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[h]);

        return i + 1;
    }

    template <typename T>
    void quick_sort(std::vector<T>& a, int l, int h)
    {
        if (l < h)
        {
            int p = partition(a, l, h);

            quick_sort(a, l, p - 1);
            quick_sort(a, p + 1, h);
        }
    }

    template <typename T>
    void quick_sort(std::vector<T> &a) { quick_sort(a, 0, a.size() - 1); }
}

#endif
