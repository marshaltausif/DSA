class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current=0;
        int best=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                current ++;
                best = max(current,best); 
            }
            else
            current =0;
           
        }

    return best;
    }
};