#include<unordered_map>
#include<iostream>
#include<string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        ushort max_len = 0;
        std::unordered_map<char, bool> substring;
        ushort start = 0, i;
        ushort size = s.size();
        for (i = 0; i < size; ++i) {
            while (substring[s[i]]) {
                substring[s[start]] = false;
                start++;
            }
            substring[s[i]] = true;
            if (i - start + 1 > max_len) {
                max_len = i - start + 1;
            }
        }
        return max_len;
    }
};