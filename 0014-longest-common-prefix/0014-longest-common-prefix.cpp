#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Sort the vector lexicographically
        sort(strs.begin(), strs.end());
        
        string ans = "";
        string f = strs[0];
        string l = strs[strs.size() - 1];
        
        int i = 0;
        // Ensure 'i' does not exceed the bounds of either string
        while (i < f.size() && i < l.size() && f[i] == l[i]) {
            ans += f[i];
            i++;
        }
        
        return ans;
    }
};