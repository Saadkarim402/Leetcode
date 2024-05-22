class Solution {
public:
    int minInsertions(string s) {
        int n=s.size(),m=s.size();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        int k=dp[0][0];
        return n-k; 
        
    }
};