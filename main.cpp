#include "RadixSortEngine.h"

void output_vector(const std::vector<unsigned long>& v) {
    if (v.empty()) std::cout << "Vecteur vide" ;
    for (auto it = v.begin(); it != v.end(); ++it) std::cout << *it << " - " ;
    std::cout << std::endl ;
}

bool is_sorted(const std::vector<unsigned long>& v) {
    for (auto it = v.begin(), next = it + 1; next != v.end(); ++it, ++next) {
        if (*it > *next) return false ;
    }
    return true ;
}

void test_input (std::vector<unsigned long> input) {
    size_t taille = input.size() ;
    output_vector(input) ;
    RadixSortEngine sorter(input, 10) ;
    sorter.sort() ;
    output_vector(input) ;
    if (is_sorted(input) && taille == input.size()) std::cout << "TEST RÉUSSI!\n" ;
    else std::cout << "TEST ÉCHOUÉ!\n" ;


};
int main() {
    std::vector<std::vector<unsigned long>> testInput {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {4, 1, 5, 4, 7, 2, 9, 0, 1, 2, 1, 6, 5, 3, 4},
            {1945},
            {1, 1000000},
            {1000000, 1},
            {13243, 56798, 23, 1, 239, 1534, 2648, 13243, 23, 23, 17, 23468}
    } ;

    for (const auto& input: testInput) test_input(input) ;
    return 0;
}
