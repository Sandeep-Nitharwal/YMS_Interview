#ifndef FIB_H
#define FIB_H

#include <vector>

namespace fib {
    // Recursive solution (exponential time)
    int solve1(int n);
    
    // Memoization solution (top-down DP)
    int solve2(int n);
    
    // Iterative solution (linear time, constant space)
    int solve3(int n);
    
    // Matrix exponentiation solution (logarithmic time)
    int solve4(int n);
    
    // Helper function for matrix multiplication
    std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
    
    // Helper function for matrix exponentiation
    std::vector<std::vector<int>> matrixPower(const std::vector<std::vector<int>>& M, int power);
}

#endif // FIB_H