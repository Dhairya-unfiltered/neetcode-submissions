class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int>mp;

        for(auto ch: s1){
            mp[ch]++;
        }
        int k = s1.size();
        int count = mp.size();
        int n = s2.size();
         int i =0;
         for(int j=0;j<n;j++){
            mp[s2[j]]--;
            if(mp[s2[j]]==0){
                count--;
            }
            if(j-i+1!=k){
                continue;
            }
            if(count==0){return true;}
            mp[s2[i]]++;
            if(mp[s2[i]]==1){
                count++;
            }
            i++;
         }


      
          return false;
    }
};
