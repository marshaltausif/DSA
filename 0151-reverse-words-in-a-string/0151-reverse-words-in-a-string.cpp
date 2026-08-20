class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack <string> temp;
        string word;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{
                if(word!=""){
                    temp.push(word);
                    word="";
                }
            }
        }if(word != "") {
    temp.push(word);
}
          
        
        while(!temp.empty()){
            string top=temp.top();
            temp.pop();
            ans+=top;
            if(!temp.empty()){
                ans+=" ";
            }
            
        }

        return ans;
    }
};