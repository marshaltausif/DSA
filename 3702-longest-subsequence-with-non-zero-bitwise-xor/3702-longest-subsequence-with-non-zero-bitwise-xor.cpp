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

/*                   START
                      │
                      ▼
             Calculate XOR of
              the whole array
                      │
                      ▼
               Is XOR != 0?
                 /        \
               YES         NO
                │           │
                ▼           ▼
          Keep all n    Is there at least
          elements?     one non-zero?
                │          /       \
                ▼        YES        NO
           return n       │          │
                          ▼          ▼
                    Remove one    All elements
                    non-zero      are zero
                       │             │
                       ▼             ▼
                  return n-1      return 0*/