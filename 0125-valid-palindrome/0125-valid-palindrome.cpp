class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";

        for(char c : s){
            if(isalnum(c)){
                clean += tolower(c);
            }
        }

        string r = "";
        for(int i = clean.size() - 1; i >= 0; i--){
            r += clean[i];
        }

        return r == clean;
    }
};