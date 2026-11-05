class Solution {
public:
    int uniquePaths(int m, int n) {
        
       if(m < n)
        return uniquePaths(n, m);

        int ans = 1;
        int j =1;
        for(int i = m; i < m + n - 1; i++){
            ans *= i;
            ans /= j;
            j++;
        }
        return ans; 
      

    }
};
