class Solution {
public:
    int maxArea(vector<int>& heights) {

     int ans = 0;
     int n =heights.size();
     int i = 0;
     int j = n-1;
     while(i < j){
        int val = (j-i)*min(heights[i], heights[j]);
        ans = max(ans, val);
        if(heights[i] < heights[j])
            i++;
        else
            j--;
     }
     return ans;

    }
};
