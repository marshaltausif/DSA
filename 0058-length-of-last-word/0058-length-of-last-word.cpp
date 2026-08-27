class Solution {
public:
    int lengthOfLastWord(string s) {

        string word;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != ' ') {
                word += s[i];
            }
            else {// else matlab space hai

                if(i == s.size() - 1) { 
                    // Agar ye string ka bilkul last character hai,
                    // toh word mein jo last word pada hai uski length return karo.
                    return word.size();
                }

                if(s[i + 1] != ' ') { // ITS FOR MORE THAN ONE SPACE
                    // agar next wala space nahi hai
                    // Matlab current space ke baad naya word start hone wala hai,
                    // isliye purana word hata do aur next word ko store karna start karo.
                    word = "";
                }

                // Agar s[i + 1] bhi space hai,
                // matlab ek se zyada spaces hain, jaise "moon  ".
                // Is case mein word ko clear nahi karna hai,
                // kyunki ye trailing spaces hain aur "moon" ko preserve karna hai.
            }
        }

        return word.size();
    }
};