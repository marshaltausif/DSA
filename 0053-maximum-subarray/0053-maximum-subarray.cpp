class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum= INT_MIN;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            max_sum=max(currsum,max_sum);
            if(currsum<0){
                currsum=0;
            
            }
            
        }return max_sum;
    }
};