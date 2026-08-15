class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorelem=0;
        for(int i=0;i<nums.size();i++){
            xorelem=xorelem^nums[i];
        }
        if(xorelem!=0){
            return nums.size();
        }
        else{//xorelem ==0
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=0){
                return nums.size()-1;
            }
        }
        // when xorelem of all elements is zerp just remove any one element 

        }
        return 0;
    }
};