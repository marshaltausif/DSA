class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int j;
        for(int i=0;i<nums.size();i++){
            for(j=0;j<nums.size();j++){
                if(i!=j&&nums[i]==nums[j]){
                    break;
                }
                
            }
            if(j==nums.size()){
                    return nums[i];
                }

        }
     return -1;
    }
};
/*
    KEY POINTS / LOGIC:

    1. i selects the element we are currently checking.
       j searches the entire array to find another copy of nums[i].

    2. We use:
           for(j = 0; j < nums.size(); j++)

       NOT j = i + 1.

       Reason:
       j = i + 1 only searches to the RIGHT of i.
       A duplicate can be to the LEFT of i.

       Example:
           [2, 2, 1]
            ↑  ↑
            duplicate

       When i = 1, the other 2 is at index 0.
       If j starts from i + 1, index 0 is never checked.

    3. Since j starts from 0, j can become equal to i.
       We must prevent comparing the element with itself:

           if(i != j && nums[i] == nums[j])

       i != j → don't compare the element with itself.
       nums[i] == nums[j] → another equal element exists.

    4. We use break when a duplicate is found:

           if(i != j && nums[i] == nums[j])
               break;

       break means:
       "We found a duplicate, so this element is NOT the answer.
        Stop searching for this i."

    5. After the inner loop:

           if(j == nums.size())

       means the loop reached the end WITHOUT finding a duplicate.

       Why?

       The loop condition is:

           j < nums.size()

       If no break happens, j eventually becomes nums.size(),
       the condition becomes false, and the loop ends.

       Therefore:

           j == nums.size()
           → searched the whole array
           → no duplicate found
           → nums[i] is the single number.

    6. We cannot check j == nums.size() INSIDE the loop because
       while the loop is running, its condition guarantees:

           j < nums.size()

       j becomes nums.size() only AFTER the loop ends.

    7. return nums[i] gives the answer immediately when we find
       an element that has no duplicate.

    8. return -1 at the end is only a safety return because the
       function must return an int. The problem guarantees that
       a single number exists, so this line normally never runs.

    IMPORTANT:
    "nums[i] != nums[j]" does NOT mean nums[i] is single.
    It only means those TWO elements are different.

    To prove that nums[i] is single, we must check ALL other
    elements and make sure none of them equals nums[i].
*/