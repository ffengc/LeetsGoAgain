

#include <iostream>
#include <algorithm>
#include <vector>

/**
    6 1
    2 2 3 1 5 2
    2 3 1 5 4 3
 */

int binaryKnapsackProblem(const int &capacity, const std::vector<int> &weight, const std::vector<int> &value)
{
    int n = weight.size(); // 物品的数量
    // 创建一个dp数组再说
    // std::vector<std::vector<int>> dp(n, std::vector<int>(capacity + 1, 0)); // 先全部初始化为0
    std::vector<int> dp(capacity + 1, 0);
    // 然后第一列都是初始化为0，就不用处理了，处理第一行
    // for (int j = 0; j < capacity + 1; j++)
    // {
    //     // j 表示当前背包的容量, 看看第一行能否放入物品0
    //     if (j < weight[0])
    //         dp[0][j] = 0;
    //     else
    //         dp[0][j] = value[0];
    // }
    // 初始化完成了
    for (int i = 0; i < n; ++i)
        for (int j = capacity; j >= weight[i]; --j)
                // 选择放物品i
                dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
    return dp[capacity];
}

int main()
{
    int n = 0, capacity = 0;
    std::cin >> n >> capacity;
    std::vector<int> weight(n, 0);
    std::vector<int> value(n, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> weight[i];
    for (int i = 0; i < n; ++i)
        std::cin >> value[i];

    std::cout << binaryKnapsackProblem(capacity, weight, value) << std::endl;

    return 0;
}