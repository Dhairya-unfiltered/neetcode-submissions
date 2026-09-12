class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>>adj;
         
        for(auto word:words){
            for(auto ch:word){
                adj[ch]={};
            }
        }


        for(int i=0;i<words.size()-1;i++){
            string &s1 = words[i];
            string &s2 = words[i+1];
              if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
                return "";
            }

            int k = 0;
            int m = 0;

            while(k<s1.size()&&m<s2.size()){
                if(s1[k]==s2[m]){
                    k++;
                    m++;
                }else{
                    adj[s1[k]].insert(s2[k]);
                    break;
                }
            }
        }
        
        string ans="";

        unordered_map <char,int> inDegree;
         

         for(auto pair:adj){
            inDegree[pair.first]=0;
        }


        for(auto pair:adj){
            for(auto ch: pair.second){
                inDegree[ch]++;
            }
        }



    queue<char>q;

    for(auto pair:inDegree){
        if(pair.second==0){
            q.push(pair.first);
        }
    }

    while(!q.empty()){
        char front = q.front();
        q.pop();
        ans+=front;
        for(auto neighbor: adj[front]){
             inDegree[neighbor]--;
             if(inDegree[neighbor]==0){
                q.push(neighbor);
             }
        }

    }

      if(ans.size()!=adj.size()){return "";}    

      return ans;
    }
};
