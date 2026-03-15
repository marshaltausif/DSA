class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        
        if(m == 1){
            long long ans = LLONG_MIN;
            for(long long x : nums)
                ans = max(ans, x*x);
            return ans;
        }

        long long ans = LLONG_MIN;
        long long mx = nums[0];
        long long mn = nums[0];

        for(int j = m-1; j < n; j++){
            int i = j - m + 1;

            mx = max(mx, (long long)nums[i]);
            mn = min(mn, (long long)nums[i]);

            ans = max(ans, mx * nums[j]);
            ans = max(ans, mn * nums[j]);
        }

        return ans;
    }
};