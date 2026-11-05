class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        int cnt = 0;
        for(int j =0; j<=n; j++){
            int a = j;
            cnt = 0;
            for(int i = 0; i < 32; i++)
            if(a & (1<<i))
                cnt++;
            v.push_back(cnt);

        }
        return v;
        
    }
};
