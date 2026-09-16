class Solution {
public:
    string minWindow(string s, string t) {
 

        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        
        int n=s.size();
        int count = mp.size();
        int i=0;
        int maxl=INT_MAX;
        int maxi=-1;
        int maxj=0;
        for(int j=0;j<n;j++){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
            while(count==0){
                maxl=min(maxl,j-i+1);
                if(maxl==j-i+1){
                     maxi =i;
                     maxj=j;
                }
               
                mp[s[i]]++;
                if(mp[s[i]]==1){
                    count++;
                }
                i++;
            }
        }



        if(maxi==-1){return "";}
        return s.substr(maxi,maxj-maxi+1);
    }
};
