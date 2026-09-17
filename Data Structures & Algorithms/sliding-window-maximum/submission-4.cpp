class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       
         int n = nums.size();
         vector<int>ans;
         int i=0;
         deque<int>dq;

         for(int j=0;j<n;j++){
            
            while(!dq.empty()&&nums[j]>dq.back()){
                   dq.pop_back();
            }
            dq.push_back(nums[j]);


            if(j-i+1!=k){
                continue;
            } 
            
            ans.push_back(dq.front());
            if(dq.front()==nums[i]){
                dq.pop_front();
            }
            i++;
         }


         return ans;
    }
};
