class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({0,{i,j}});
            }
        }
        int nx[4]={1,0,-1,0};
        int ny[4]={0,1,0,-1};
        int time=0;
        while(!q.empty()){
            int t=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            int row,col;
            for(int i=0;i<4;i++){
                row=x+nx[i];
                col=y+ny[i];
                if(row>=0&&row<n&&col>=0&&col<m&&grid[row][col]==1) q.push({t+1,{row,col}}),grid[row][col]=2;
            }
            time=max(t,time); 
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;


        
    }
};