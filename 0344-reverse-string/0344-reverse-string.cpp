class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>box;
        vector<char>rev;
        for(int i=0;i<s.size();i++){
            char curr=s[i];
            box. push(curr);}
            
        
        while(!box.empty()){
            
       
       rev. push_back( box.top());
       box. pop();
       
       }
       s= rev;
    }
};