class Solution {
public:
    bool isPalindrome(int x) {
        long long  orignal =x;
        long long reverse =0;
        if (x<0){
            return false;
        }
        while(x!=0){
            int last_digit=x%10;
            reverse=reverse*10+last_digit;
            x=x/10;
        }cout<<"reversed number is "<<reverse;
        if(reverse==orignal){
            return true;
        }
        return false;

    }
};