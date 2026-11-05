class Solution {
public:
    vector<string>ans; 
    void fun(int l , int r, string &s){
        if(l == r && l == 0){
            ans.push_back(s);
            return ; 
        }
        if(r < l)
            return ; 

        if(l > 0){
            s.push_back('(');
            fun(l - 1, r, s);
            s.pop_back();
        }
        if(r > 0){
            s.push_back(')');
            fun(l, r - 1, s);
            s.pop_back(); 
        }
            
    
    }



    vector<string> generateParenthesis(int n) {
        
        // vector<vector<string>>ans(n+1);
        // ans[0] = {""};

        // for(int i = 1; i <=n; i++){


        //     for(int j = 0; j < i; j++){

        //         for(auto a: ans[j]){
        //             for(auto b: ans[i - j - 1])
        //                 ans[i].push_back("(" + a + ")" + b);
        //         }
        //     }
        // }
        ans.clear();
        string s = "";
        fun(n, n, s);
        return ans;

        // return ans[n];



    }
};
