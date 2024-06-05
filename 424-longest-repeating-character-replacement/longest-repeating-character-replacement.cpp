class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<26;i++){
            char c='A'+i;
           // cout<<c<<endl;
            int r=0,l=0,k1=k;
            while(r<n){
                if(s[r]!=c){
                    k1--;
                }
                if(k1<0){
                    if(s[l]!=c){
                        k1++;
                    }
                    l++;
                }
                r++;
            }
            ans=max(ans,r-l);
        }
        return ans;
        
    }
};