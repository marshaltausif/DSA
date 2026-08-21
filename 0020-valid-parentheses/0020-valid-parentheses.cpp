class Solution {
public:
    bool isValid(string s) {
        stack<char> Box;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '[') {
                Box.push(ch);
            }
            else {
                if(Box.empty())
                    return false;

                char top = Box.top();

                if((top == '(' && ch == ')') ||
                   (top == '[' && ch == ']') ||
                   (top == '{' && ch == '}')) {
                    Box.pop();
                }
                else {
                    return false;
                }
            }
        }

        return Box.empty();
    }
};