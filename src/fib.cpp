#include "fib.h"
#include <vector>

namespace fib {

// Solution 1: Basic recursive
int solve1(int n) {
    if (n == 1 || n == 2) return n;
    return solve1(n - 1) + solve1(n - 2);
}

// Solution 2: Memoization
int solve2Helper(int n, std::vector<int>& dp) {
    if (n == 1 || n == 2) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = solve2Helper(n - 1, dp) + solve2Helper(n - 2, dp);
    return dp[n];
}

int solve2(int n) {
    std::vector<int> dp(n + 1, -1);
    return solve2Helper(n, dp);
}

// Solution 3: Iterative
int solve3(int n) {
    if (n == 1 || n == 2) return n;
    int a = 1, b = 2, temp;
    for (int i = 3; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Solution 4: Matrix exponentiation
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    std::vector<std::vector<int>> result(2, std::vector<int>(2, 0));
    result[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    result[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    result[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    result[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    return result;
}

std::vector<std::vector<int>> matrixPower(const std::vector<std::vector<int>>& M, int power) {
    if (power == 0) return {{1, 0}, {0, 1}}; // Identity matrix
    if (power % 2 == 1) return matrixMultiply(M, matrixPower(M, power - 1));
    std::vector<std::vector<int>> half = matrixPower(M, power / 2);
    return matrixMultiply(half, half);
}

int solve4(int n) {
    if (n == 1 || n == 2) return n;
    std::vector<std::vector<int>> M = {{1, 1}, {1, 0}};
    std::vector<std::vector<int>> result = matrixPower(M, n - 1);
    return result[0][0] * 2 + result[0][1] * 1;
}
} // namespace fib