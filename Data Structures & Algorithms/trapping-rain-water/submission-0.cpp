class Solution {
public:
    int trap(vector<int>& height) {
        
        int len = height.size();
        vector<int>left(len+1, 0);

        for(int i = 0; i < len; i++){
            left[i + 1] = max(left[i], height[i]);
        }
        int ans = 0;
        int ryt = height[len - 1];
        for(int i = len - 2; i>=0 ; i--){
            ryt = max(ryt, height[i]);
            ans += min(ryt, left[i+1]) - height[i];
        }
        return ans; 
    }
};
