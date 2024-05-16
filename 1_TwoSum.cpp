class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        std::vector<int> res;
        for (int i = 0; i < size; ++i) {
            auto iter = std::find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if (iter != nums.end()) {
                int idx = iter - nums.begin();
                res = {i, idx};
                break;
            }
        }
        return res;
    }
};
