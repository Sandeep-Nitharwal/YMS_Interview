#include "fib.h"
#include <iostream>
#include <chrono>

void profileFunction(int (*func)(int), int n, const std::string& name) {
    auto start = std::chrono::high_resolution_clock::now();
    int result = func(n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << name << "(" << n << ") = " << result 
              << " | Time: " << duration.count() << " μs" << std::endl;
}

int main() {
    int n = 40; // Large enough to show performance differences
    
    profileFunction(fib::solve1, n, "Recursive");
    profileFunction(fib::solve2, n, "Memoization");
    profileFunction(fib::solve3, n, "Iterative");
    profileFunction(fib::solve4, n, "Matrix");
    
    return 0;
}