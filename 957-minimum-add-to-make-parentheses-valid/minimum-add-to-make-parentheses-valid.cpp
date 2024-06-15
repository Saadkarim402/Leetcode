class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ans++;
            }
            else {
                ans--;
            }
            if(ans<0){
                c++;
                ans++;
            }
        }
        return c+max(0,ans);
        
        
    }
};