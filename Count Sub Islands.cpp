class Solution {
public:
    bool bfs(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int &x,int &y,vector<vector<int>> &visited){
        bool flag=true;
        int m=grid1.size();
        int n=grid1[0].size();

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        queue<pair<int,int>> q;
        visited[x][y]=1;
        if(grid1[x][y]!=1){
            flag=false;
        }
        q.push({x,y});
        while(!q.empty()){
            int xCol=q.front().first;
            int yCol=q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int newX=dx[k]+xCol;
                int newY=dy[k]+yCol;
                if(newX>=0 and newX<m and newY>=0 and newY<n and !visited[newX][newY] and grid2[newX][newY]){
                    visited[newX][newY]=1;
                    q.push({newX,newY});
                    if(grid1[newX][newY]!=1){
                        flag=false;
                    }
                }
            }
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int islands=0;
        int m=grid1.size();
        int n=grid1[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                bool flag=true;
                if(grid2[i][j] and !visited[i][j]){
                    flag = bfs(grid1,grid2,i,j,visited);
                    if(flag){
                        islands++;
                    }
                }
            }
        }
        return islands;
    }
};