

#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool isValid(const std::string& s, int begin, int end) {
    // 判断 s中，[begin, end] 区间是否是合法ip地址
    if (end - begin > 2)
        return false; // 大于3位数肯定不合法
    if (s[begin] == '0')
        return false; // 有前导0不合法
    int num = std::stoi(std::string(s.begin() + begin, s.begin() + end + 1));
    if (num < 0 || num > 255)
        return false; // 判断数字范围
    return true;
}

int main() {
    std::string s = "012245";
    std::cout << isValid(s, 0, 5) << std::endl;
}