

#include <iostream>
#include <set>
#include <hash_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
        std::vector<int> res(std::min(nums1.size(), nums2.size()));
        auto it = std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), res.begin());
        for(int i = 0; i < res.size(); ++i) {
            std::cout << res[i] << " ";
        }
        std::cout << std::endl;
        std::set<int>s(res.begin(), it);
        return std::vector<int>(s.begin(), s.end());
    }
};

int main() {
    Solution().intersection({4,9,5}, {9,4,9,8,4});
    return 0;
}