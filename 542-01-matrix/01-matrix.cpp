class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else vis[i][j]=0;
            }
        }
        int r[4]={0,1,0,-1};
        int co[4]={1,0,-1,0};
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int c=q.front().second;
            dist[x][y]=c;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+r[i];
                 int ny=y+co[i];
                if(nx<n&&nx>=0&&ny<m&&ny>=0&&vis[nx][ny]==0){
                q.push({{nx,ny},c+1});
                vis[nx][ny]=1;
            }
            }
            
        }
        return dist; 
    }
};