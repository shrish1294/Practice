class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, R = m*n - 1;

        int cnt = 0;
        while(l<=R){
            int mid = (l + R)/2;
            int r = mid / n; 
            int c = mid % n; 
            // cout<<mid<<" "<<r<<" "<<c<<"\n";
            if(matrix[r][c] == target)
                return true;
            if(matrix[r][c] > target)
                R = mid - 1;
            else
                l = mid + 1;
            // cnt++;
            // if(cnt > 10)
            //     break;
            
        }
        return false;

    }
};
