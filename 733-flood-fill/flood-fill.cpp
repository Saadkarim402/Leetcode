class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=image[i][j];
            }
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int ini=image[sr][sc];
        int r[4]={1,0,-1,0};
        int c[4]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            mat[row][col]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r[i]+row;
                int ncol=c[i]+col;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==ini&&image[nrow][ncol]!=color){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                }
            }
        }
        return mat;
    }
};