class Solution {
    private:
    bool check(string &s,int i){
        for(int k=i;k>=0;k--){
            if(s[k]!='*')return false;
        }
        return true;
    }


    bool solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        //base cases
        if(i<0&&j<0)return true;
        if(i<0&&j>=0)return false;
        if(j<0&&i>=0)return check(s,i);

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==t[j]||s[i]=='?'){
            return dp[i][j]=solve(i-1,j-1,s,t,dp);
        }
        else{
            if(s[i]=='*'){
                //check for both cases ie
                //if * rep empty subs
                //or * rep some subs
                return dp[i][j]=solve(i-1,j,s,t,dp)||solve(i,j-1,s,t,dp);
            }
            return dp[i][j]=false;
        }

    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(p.size(),vector<int>(s.size(),-1));
        return solve(p.size()-1,s.size()-1,p,s,dp);
    }
};