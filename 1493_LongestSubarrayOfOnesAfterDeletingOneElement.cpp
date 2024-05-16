#include <vector>

class Solution {
public:
  int longestSubarray(std::vector<int> &nums) {
    if (std::find(nums.begin(), nums.end(), 1) == nums.end()) {
      return 0;
    } else if (std::find(nums.begin(), nums.end(), 0) == nums.end()) {
      return nums.size() - 1;
    }
    int prev_len = 0;
    int curr_len = 0;
    int max_len = 0;
    for (auto num : nums) {
      if (num == 1) {
        curr_len += 1;
      } else if (num == 0) {
        max_len = std::max(max_len, prev_len + curr_len);
        prev_len = curr_len;
        curr_len = 0;
      }
    }
    max_len = std::max(max_len, prev_len + curr_len);
    return max_len;
  }
};
