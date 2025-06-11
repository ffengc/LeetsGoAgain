

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int getSum(int n) {
    int sum = 0;
    while(n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

int main() {
    std::cout << getSum(123) << std::endl;
    return 0;
}