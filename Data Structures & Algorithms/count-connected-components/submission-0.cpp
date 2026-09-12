class Solution {
   void dfs(int start,vector<vector<int>>& adj,vector<int>&vis){
       vis[start]=1;
       
       for(auto ad:adj[start]){
           if(vis[ad]==0){
                dfs(ad,adj,vis);
           }
       }

   }


public:
    int countComponents(int n, vector<vector<int>>& edges) {
            vector<int>vis(n,0);
            vector<vector<int>>adj(n);
            int count =0;
            for(auto edge:edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    count++;
                    dfs(i,adj,vis);
                }
            }
      


      return count;
    }
};
