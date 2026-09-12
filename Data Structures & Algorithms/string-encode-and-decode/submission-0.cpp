class Solution {
public:

    string encode(vector<string>& strs) {
        string ans ="";
     
        for(auto str:strs){
            ans = ans+to_string(str.size())+'#'+str;
        }

        return ans;
    }

    vector<string> decode(string s) {
       vector<string> ans;
       if(s=="") return ans;

       int i = 0;
       int n = s.size();

       while(i<n){
            int j = i;
            while(s[j]!='#')j++;
            int len = stoi(s.substr(i,j-i));
            j++;
            ans.push_back(s.substr(j,len));
            i = j+len;
       }


       
       return ans;
    }
};
