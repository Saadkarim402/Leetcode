class Solution {
public:
    void solve(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int vis[n][m];
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                q.push({i,0});
            }
            if(mat[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O'){
                q.push({0,i});
            }
            if(mat[n-1][i]=='O'){
                q.push({n-1,i});
            }
        }
        int r[4]={0,1,0,-1};
        int c[4]={1,0,-1,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            vis[x][y]=1;
            for(int i=0;i<4;i++){
                int nx=x+r[i];
                int ny=y+c[i];
                if(nx<n&&nx>=0&&ny<m&&ny>=0&&!vis[nx][ny]&&mat[nx][ny]=='O'){
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    mat[i][j]='X';
                }
                else mat[i][j]='O';
            }
        }


        
    }
};