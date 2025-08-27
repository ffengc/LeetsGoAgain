

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
private:
    void print(const std::vector<std::vector<int>> &arr)
    {
        for (const auto &e : arr)
        {
            std::cout << "(" << e[0] << "," << e[1] << ") ";
        }
        std::cout << std::endl;
    } //
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people)
    {
        std::sort(people.begin(), people.end(), [](const auto &a, const auto &b)
                  { 
                    if (a[0] == b[0]) return a[1] < b[1];
                    return a[0] > b[0]; });
        // print(people);
        auto res = std::vector<std::vector<int>>();
        for (int i = 0; i < people.size(); ++i)
        {
            int pos = people[i][1];
            // 这里要注意：是不用担心 pos 会被弄成在一个越界的位置上的，如果这样，题目就是有问题的
            res.insert(res.begin() + pos, people[i]);
        }
        return res;
    }
};

int main()
{
    std::vector<std::vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution().reconstructQueue(people);
    return 0;
}