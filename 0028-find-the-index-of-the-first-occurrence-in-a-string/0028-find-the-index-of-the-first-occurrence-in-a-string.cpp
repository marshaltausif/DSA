class Solution {
public:
    int strStr(string haystack, string needle) {
        string ans ;
        for(int i=0;i<haystack.size();i++){
            ans="";
            for (int j=0;j<needle.size();j++){
                
                if(needle[j]==haystack[i+j]){
                    ans+=needle[j];
                    if(needle==ans){
                        return i;
                    }
                }
                else{
                    break;
                }
            }
        }
        return -1;
    }
};