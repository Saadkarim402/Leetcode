class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[n-1][m-1]==1||grid[0][0]==1)return -1;
        if(n==1&&m==1&&grid[0][0]==0)return 1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        int r[]={1,0,-1,0,1,1,-1,-1};
        int c[]={0,1,0,-1,1,-1 ,1,-1};
        while(!q.empty()){
            int d=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=r[i]+x;
                int ny=c[i]+y;
                if(nx<n&&nx>=0&&ny<m&&ny>=0&&grid[nx][ny]==0){
                    if(d+1<dist[nx][ny]){
                        dist[nx][ny]=d+1;
                        if(nx==n-1&&ny==m-1)return d+1;
                        q.push({d+1,{nx,ny}});
                    }
                }
            }
        }
            return -1;
    }
};