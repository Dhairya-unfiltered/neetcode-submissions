class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
         //are we given that component will be connected only?
         //agar more than 1 connceted comp hai then resturn false
         //agar cycle hai then also false
         if(edges.size()!=n-1) return false;

         vector<vector<int>>adj(n);

         for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
         }

         vector<int>vis(n,0);

         queue<pair<int,int>>q;
         q.push({0,-1});
         vis[0]=1;

         while(!q.empty()){
            auto front = q.front();
            int c = front.first;
            int p = front.second;
            q.pop();
            for(auto ad:adj[c]){
                if(vis[ad]==1&&ad!=p){
                   return false;
                }else if(vis[ad]==0){
                    vis[ad]=1;
                    q.push({ad,c});
                }
            }
         }





        //  for(int i=0;i<n;i++){
        //     if(vis[i]!=1) {return false;}
        //  }



         return true;
    }
};
