

#include <deque>
#include <iostream>
#include <vector>

// 239: 滑动窗口最大值
// 这一题非常重要！

class Solution {
private:
    class MonotonicQueue {
    private:
        std::deque<int> __que; //
    public:
        void push(int val) {
            while (!__que.empty() && val > __que.back())
                __que.pop_back();
            __que.push_back(val);
        }
        void pop(int val) {
            if (!__que.empty() && __que.front() == val)
                __que.pop_front();
        }
        int front() { return __que.front(); }
    }; //
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        MonotonicQueue que;
        std::vector<int> res;
        // 先把头k个插入到que里面
        for (int i = 0; i < k; ++i)
            que.push(nums[i]);
        res.push_back(que.front()); // 记录结果
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front()); // 记录结果
        }
        return res;
    }
};
