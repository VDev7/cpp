#include "algorithm.hpp"

int main()
{
    std::vector<int> data = {4, 7, 1, 3};
    std::vector<int> sorted_data = {1, 3, 5, 7, 11, 13};
    std::vector<std::string> string_data =
    {
        "Iqbal",
        "Dhiya'",
        "Jakarta",
        "Bandung",
        "Faruq",
        "Aqhsa",
        "Alpha",
        "Saber",
        "kemarin",
        "hebat",
        "zeta",
        "peta",
        "tera",
        "giga",
        "mega",
        "kilo",
        "byte",
        "bit"
    };

    cpp::linear_search(string_data);
    // cpp::insertion_sort(string_data);
    // cpp::binary_search(string_data);

    return 0;
}
