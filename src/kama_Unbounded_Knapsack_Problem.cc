

#include <iostream>
#include <vector>
#include <algorithm>

/**
4 5
1 2
2 4
3 4
4 5
 */

int unboundedKnapsackProblem(const int &capacity, const std::vector<int> &weight, const std::vector<int> &value)
{
    int n = weight.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(capacity + 1, 0));
    // 初始化
    // 初始化第一列，默认是0
    // 初始化第一行
    for (int j = weight[0]; j <= capacity; j++)
    {
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    }
    // 开始dp
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= capacity; ++j)
        {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
        }
    }
    return dp[n - 1][capacity];
}

int main()
{
    int n = 0;        // 物品数量
    int capacity = 0; // 背包能承受的重量
    std::vector<int> weight;
    std::vector<int> value;
    std::cin >> n >> capacity;
    for (int i = 0; i < n; ++i)
    {
        int w, v;
        std::cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }
    std::cout << unboundedKnapsackProblem(capacity, weight, value) << std::endl;
    return 0;
}