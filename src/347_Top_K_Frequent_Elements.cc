

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

// 347. 前 K 个高频元素
// std::priority_queue 默认是大顶堆
// 重写一下 pq 对比的逻辑就行了

class Solution {
private:
    struct CompareFunction {
        bool operator()(const std::pair<int, int>& e1, const std::pair<int, int>& e2) {
            return e1.second > e2.second;
        }
    }; //
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // 先记录频率
        std::unordered_map<int, int> hash_table;
        for (const auto& e : nums)
            hash_table[e]++;
        // 构建堆
        /**
         * note: std::priority_queue这里传入的是类，std::sort那里传的是函数
         * 要注意好！
         */
        std::priority_queue<std::pair<int, int>, std::deque<std::pair<int, int>>, CompareFunction> pq;
        for (auto it = hash_table.begin(); it != hash_table.end(); ++it)
            pq.push(*it);
        // 记录结果
        std::vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main() {
    std::priority_queue<int> pq;
    pq.push(1);
    pq.push(-2);
    pq.push(3);
    std::cout << pq.top() << std::endl;
    return 0;
}