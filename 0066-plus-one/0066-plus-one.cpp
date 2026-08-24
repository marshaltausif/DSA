class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i = digits.size()-1; i >= 0; i--){
            
            if(digits[i] == 9){
                digits[i] = 0;
            }
            else{
                digits[i] = digits[i] + 1;
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};

/*
WHAT WE DISCUSSED:

1. We start from the LAST digit because addition starts from the right.

2. if(digits[i] == 9)
   → if the current digit is 9, make it 0.
   Example:
   [1,2,9]
        ↓
   [1,2,0]
   The carry now moves to the left.

3. else means:
   → the current digit is NOT 9.
   So increase that current digit by 1 and STOP.
   
   Example:
   [8,9,9,9]
        ↓
   9 → 0
   9 → 0
   9 → 0
   8 → 9
   
   Result:
   [9,0,0,0]

4. We use digits[i], NOT digits[digits.size()-1].
   Why?
   Because i is moving from right to left.
   We need to change the CURRENT digit where the carry has reached.

5. return digits inside else:
   Once we find a digit that is NOT 9, we increase it.
   The job is finished, so we return immediately.

6. Why is insert() OUTSIDE the for loop?
   We only need to insert 1 at the front when the loop finishes completely.
   If the loop finishes, it means EVERY digit was 9.

   Example:
   [9,9,9]
      ↓
   [0,0,0]
      ↓
   loop finishes
      ↓
   insert 1 at front
      ↓
   [1,0,0,0]

7. Why can't else be outside the for loop?
   Because else belongs to its matching if.
   It must come immediately after:
   
   if(condition) {
       ...
   }
   else {
       ...
   }

   The else here means:
   "The current digit is NOT 9."

8. Why not use:
   digits.insert(digits.begin(), 1)
   inside the loop?
   Because we do NOT want to insert 1 every time.
   We only insert 1 when ALL digits were 9.

9. Important examples:

   [1,2,3]   → [1,2,4]
   [1,2,9]   → [1,3,0]
   [1,9]     → [2,0]
   [8,9,9,9] → [9,0,0,0]
   [9,9]     → [1,0,0]

MAIN LOGIC TO REMEMBER:

   9     → make it 0 and continue
   NOT 9 → add 1 and stop
   ALL 9 → after loop, put 1 at front
*/