class Solution {
public:
    int lengthOfLastWord(string s) {

        string word;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != ' ') {
                word += s[i];
            }
            else {// else matlab space hai 
                if(i==s.size()-1){ //last wala check
                return word.size();
                }
                if(s[i+1]!=' '){
                word = "";// agar last wala space nahi hai toh
                }
            }
            
        }

        return word.size();
    }
};