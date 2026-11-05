class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec(n, 0);
        int p = 1;
        queue<int>q;
        int ans = INT_MIN;  
        for(int i = 0; i < n; i++){
            ans = max(ans, nums[i]);
            if(nums[i] == 0){
                p = 1;
                while(!q.empty())
                    q.pop();
            }
            else
            {    p*=nums[i]; ans = max(ans, p);}
            if(p < 0){
                if(!q.empty()){
                    auto it = q.front();
                   
                    ans = max(ans, p/vec[it]);
                }
                
            }
            if(nums[i]  < 0)
                q.push(i);
            vec[i] = p;
            
        }
       
        return ans;

        
    }
};
