class Solution {
    int dp[1001][1001];
    int solve(string &s,int i,int j){
        if(i>=j)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]){
           return dp[i][j]=solve(s,i+1,j-1);
        }
        return dp[i][j]=0;

    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int st=0,en=0,max_len=-1;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)){
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        st=i;
                        en=j;
                    }
                }
            }
        }
        return s.substr(st,max_len);

        
    }
};