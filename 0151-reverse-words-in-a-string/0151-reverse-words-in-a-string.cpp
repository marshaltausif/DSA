class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<string> temp;
        string word;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != ' ') {
                word += s[i];
            }
            else {
                if(word != "") {
                    temp.push(word);
                    word = "";
                }
            }
        }

        // IMPORTANT: push the last word
        if(word != "") {
            temp.push(word);
        }

        while(!temp.empty()) {

            string top = temp.top();
            temp.pop();

            ans += top;

            if(!temp.empty()) {
                ans += " ";
            }
        }

        return ans;
    }
};
/*
    REVERSE WORDS USING STACK

    1. We build one word at a time using:

           word += s[i];

    2. A space means the current word has ended.

       Example:
           "the sky"

       When we reach the space after "the",
       we push "the" into the stack and reset:

           word = "";

    3. Multiple spaces are automatically ignored.

       Example:
           "a   good"

       After pushing "a", word becomes empty.

       The next spaces are ignored because:

           word == ""

       so nothing gets pushed.

    4. We must push the LAST word after the loop.

       Why?

       The loop pushes words only when it sees a space.

       Example:
           "the sky is blue"

       "the" -> pushed at space
       "sky" -> pushed at space
       "is"  -> pushed at space

       "blue" has NO space after it.

       Therefore the loop ends with:

           word = "blue"

       still not pushed.

       So we do:

           if(word != "")
               temp.push(word);

    5. Stack stores COMPLETE WORDS, not characters.

           stack<string>

       NOT

           stack<char>

       Otherwise each word itself gets reversed.

    6. temp.top() returns the top WORD because
       the stack stores strings.

           string top = temp.top();

       NOT

           char top = temp.top();

    7. While popping:

           ans += top;

       appends the whole word to the answer.

    8. Add a space only if more words remain:

           if(!temp.empty())
               ans += " ";

       This prevents an extra trailing space.

    9. Difference between quotes:

           'a'  -> char
           ' '  -> space character
           ""   -> empty string
           " "  -> string containing one space

       Invalid:

           ''

       because a char cannot be empty.
*/