class Solution {
public:
    int bfs(queue<pair<pair<int,int>,int>> &q,vector<vector<int>> &grid,   vector<vector<int>> &visited){
        int m=grid.size();
        int n=grid[0].size();
     
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        int maxtime=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newX=dx[k]+x;
                int newY=dy[k]+y;
                if(newX>=0 and newX<m and newY>=0 and newY<n and !visited[newX][newY] and grid[newX][newY]==1){
                    maxtime=max(maxtime,time);
                    q.push({{newX,newY},time+1});
                    visited[newX][newY]=1;
                }
            }

        }
        return maxtime;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},1});
                }
            }
        }
        int time=bfs(q,grid,visited);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and !visited[i][j]){
                    return -1;
                }
            }
        }
        return time;
    }
};