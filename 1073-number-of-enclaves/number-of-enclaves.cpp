class Solution {
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int vis[n][m];
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(mat[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]==1){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(mat[n-1][i]==1){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        int r[4]={0,1,0,-1};
        int c[4]={1,0,-1,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+r[i];
                int ny=y+c[i];
                if(nx<n&&nx>=0&&ny<m&&ny>=0&&!vis[nx][ny]&&mat[nx][ny]==1){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1&&!vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;   
    }
};