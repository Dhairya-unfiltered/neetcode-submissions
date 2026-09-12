class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //tasks = ['Y','y','y','B']   n =1
        //Y B Y idle 

        // mp[] 
        int ans = 0;
        priority_queue<int>pq; 
        unordered_map<char,int>mp;


        for(int i=0;i<tasks.size();i++){
               mp[tasks[i]]++;
        }

        for(auto p:mp){
            pq.push(p.second);
        }

        queue<pair<int,int>>q; //{availableTime,remainingFrequency}

        while(!pq.empty()||!q.empty()){
             
             while(!q.empty()){
                if(q.front().first<=ans){
                   int top = q.front().second;
                   q.pop();
                   pq.push(top);
                }else{
                    break;
                }
             }
             
             if(pq.empty()){
                ans=q.front().first;
                continue;
             }

             int top = pq.top();
             pq.pop();
             if(top - 1 > 0){
                q.push({ans + n + 1, top - 1});
             }
             ans++;



        }
         


        
         
         return ans;

     }
};
