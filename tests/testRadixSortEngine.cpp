//
// Created by Pascal Charpentier on 2023-04-12.
//

#include "gtest/gtest.h"
#include "RadixSortEngine.h"
#include <vector>

bool is_sorted(const std::vector<unsigned long>& v) {
    for (auto it = v.begin(), next = it + 1; next != v.end(); ++it, ++next) {
        if (*it > *next) return false ;
    }
    return true ;
}


class RadixSortEngineTest : public ::testing::Test {
protected:
    const static std::vector<std::vector<unsigned long>> testInput ;

};

const std::vector<std::vector<unsigned long>> RadixSortEngineTest::testInput = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {4, 1, 5, 4, 7, 2, 9, 0, 1, 2, 1, 6, 5, 3, 4},
        {1945},
        {1, 1000000},
        {1000000, 1},
        {13243, 56798, 23, 1, 239, 1534, 2648, 13243, 23, 23, 17, 23468}
} ;

TEST_F(RadixSortEngineTest, tests) {
    for (auto input: testInput) {
        size_t taille = input.size() ;
        RadixSortEngine sorter(input, 10) ;
        sorter.sort() ;
        EXPECT_TRUE(is_sorted(input));
        EXPECT_TRUE(taille == input.size()) ;
    };
}
