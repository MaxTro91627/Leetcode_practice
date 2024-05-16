#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> res;
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[0] < b[0];
              });
    int start_inter = intervals[0][0], end_inter = intervals[0][1];
    for (auto inter : intervals) {
      if (inter[0] <= end_inter) {
        end_inter = std::max(end_inter, inter[1]);
      } else {
        std::vector<int> inter_to_add;
        inter_to_add.push_back(start_inter);
        inter_to_add.push_back(end_inter);
        res.push_back(inter_to_add);
        start_inter = inter[0];
        end_inter = inter[1];
      }
    }
    res.push_back(std::vector{start_inter, end_inter});
    return res;
  }
};
