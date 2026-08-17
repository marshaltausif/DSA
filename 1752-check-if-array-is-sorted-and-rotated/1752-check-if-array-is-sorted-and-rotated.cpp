class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> a = nums;
        int n = nums.size();

        sort(a.begin(), a.end());

        for (int x = 0; x < n; x++) {

            int i;

            for (i = 0; i < n; i++) {

                if (a[i] == nums[(i + x) % n]) {
                    continue;
                }
                else {
                    break;
                }
            }

            if (i == n)
                return true;
        }

        return false;
    }
};