class Solution {
    private:
    int solve(int a[],int n) {
        stack<int>st;
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||a[st.top()]>=a[i])){
                int h=a[st.top()];
                st.pop();
                int w=i;
                if(!st.empty()) w=i-st.top()-1;
                ans=max(ans,w*h);
            }
            st.push(i);
        }
        return ans; 
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int ht[m];
        for(int i=0;i<m;i++)ht[i]=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0')ht[j]=0;
                else ht[j]+=1;
            }
        ans=max(ans,solve(ht,m));
        }
        return ans;  
    }
};