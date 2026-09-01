class Solution {
public:
    bool isPalindromic(string s) {
        string final = "";

        for(int i=0; i<s.size(); i++){
            int num = int(s[i]);

            for(int j=7; j>=0; j--){
                if(num & (1 << j)){
                    final += '1';
                }
                else{
                    final += '0';
                }
            }
        }

        int i = 0;
        int j = final.size() - 1;

        while(i <j){
            if(final[i] != final[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};