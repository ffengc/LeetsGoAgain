

#include <iostream>
#include <string>

std::string replaceString(std::string s) {
    // 1. 先统计空格的个数
    int space_count = 0;
    int old_sz = s.size();
    for (char ch : s)
        if (ch == ' ')
            space_count++;
    // 2. 给字符串扩容
    s.resize(s.size() + space_count * 2);
    int new_sz = s.size();
    // 3. 从后向前替换
    // abcdefg***
    int left = old_sz - 1;
    int right = new_sz - 1;
    while (left < right) { // 如果right向左追上了left，表示前面已经没有空格需要处理了
        if (s[left] != ' ')
            s[right--] = s[left--];
        else if (s[left] == ' ') {
            s[right] = '0';
            s[right - 1] = '2';
            s[right - 2] = '%';
            right -= 3;
            left--;
        }
    }
    return s;
}

int main() {
    std::string str = " abc abc";
    std::cout << replaceString(str) << std::endl;
    return 0;
}