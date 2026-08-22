class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>k;
        for(int i=0;i<nums.size();i++){
            int j;
            for( j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    k.push_back(nums[j]);
                    break;
                }
               

            }
             if(j==nums.size()){
                int r;
                    for( r=0;r<i;r++){
                        if(nums[r]>nums[i]){
                            k.push_back(nums[r]);
                            break;
                        }
                       
                        
                    }
                     if(r==i){
                    k.push_back(-1);
                }
                }
            
        }return k;
        
    }
};