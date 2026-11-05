class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<vector<string>>ans(n+1);
        ans[0] = {""};

        for(int i = 1; i <=n; i++){


            for(int j = 0; j < i; j++){

                for(auto a: ans[j]){
                    for(auto b: ans[i - j - 1])
                        ans[i].push_back("(" + a + ")" + b);
                }
            }
        }
        return ans[n];



    }
};
