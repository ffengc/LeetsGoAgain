

#include <iostream>
#include <vector>
#include <assert.h>

int fib(int n) {
    // return the i-th fib number
    // fib[1] = 1
    // fib[2] = 2
    if(n == 0) assert(false);
    if(n == 1) return 1;
    if(n == 2) return 1;
    std::vector<int>dp(n);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < n; ++i) 
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n-1];
}

int main() {
    // std::cout << fib(1) << std::endl;
    // std::cout << fib(2) << std::endl;
    // std::cout << fib(3) << std::endl;
    // std::cout << fib(4) << std::endl;
    // std::cout << fib(5) << std::endl;
    // exit(1);
    // int idx = 1;
    // int sum = 0;
    // while(1) {
    //     int current_fib = fib(idx);
    //     if(current_fib <= 11112025) sum += current_fib;
    //     else break;
    // }
    // std::cout << sum << std::endl;

    std::cout << fib(35) << std::endl;
    std::cout << fib(36) << std::endl;
    std::cout << fib(37) << std::endl;


    return 0;
}