

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <assert.h>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        // ababcbaca defegdehijhklij
        // a: (0, 8)
        // b: (1, 5)
        // c: (4, 7)
        // d: (9, 14)
        // e: (10, 12)
        // f: (11, 11)
        // g: (13, 13)
        // h: (16, 19)
        // i: (17, 22)
        // j: (18, 23)
        // h: (19, 19)
        // k: (20, 20)
        // l: (21, 21)
        // 先统计出现的位置
        std::unordered_map<char, std::vector<int>> mmap;
        for(int i = 0; i < s.size(); ++i)
            mmap[s[i]].push_back(i);
        // 统计区间
        std::vector<std::vector<int>> intervals;
        for(auto& e : mmap) {
            // e.first -> char
            // e.second -> vector
            int cur_min = e.second[0];
            int cur_max = e.second[e.second.size() - 1];
            intervals.push_back({cur_min, cur_max});
        }
        // 排序
        std::sort(intervals.begin(), intervals.end(), [](const auto& e1, const auto& e2){
            if(e1[0] == e2[0]) assert(false);
            return e1[0] < e2[0];
        });
        std::vector<int> res;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] > intervals[i-1][1]) {
                // 不重叠
                res.push_back(intervals[i-1][1] - intervals[i-1][0] + 1); // 处理上一个结果
            } else {
                // 重叠，说明需要放在一起
                intervals[i][0] = std::min(intervals[i][0], intervals[i-1][0]); // 要处理，因为要用来求长度
                intervals[i][1] = std::max(intervals[i][1], intervals[i-1][1]); // 有边界
            }
        }
        return res;
    }
};

