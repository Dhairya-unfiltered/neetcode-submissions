class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
         
        int i =0;
        int j=0;
        int n=s.size();
        int count = 0;
    
        unordered_map<char,int>mp;

        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]==1){count++;}

            while(count!=j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0){count--;}
                i++;
            }
           
           ans=max(ans,j-i+1);
           j++;
        }






        return ans;
    }
};
