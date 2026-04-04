class Solution {
public:
    int values(char c){
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        return 1000; // M
    }
    int romanToInt(string s) {
        int sum =0;
        for(int i=0;i<s.length();i++){
            int curr=values(s[i]);
            if(i+1<s.length() && curr<values(s[i+1])){
                sum=sum-curr;
            }
            else{
                sum+=curr;
            }
            
        }
        return sum;
    }
};