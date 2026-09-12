class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        while(!q.empty()){
           auto front = q.front();
           q.pop();
           int r = front[0];
           int c = front[1];
           int t = front[2];

           for(int i=0;i<4;i++){
               int nr = r+dr[i];
               int nc = c+dc[i];

               if(nr<m&&nr>=0&&nc<n&&nc>=0){
                   if(grid[nr][nc]==INT_MAX){
                        grid[nr][nc]=t+1;
                        q.push({nr,nc,t+1});
                   }
               }
           }
    

        }


        
    }
};
