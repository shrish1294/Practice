class Solution {
public:


    vector<vector<string>>gr;
    map<string, int> vis;
    bool fun(string &a ,string &b){
        if(a.length() != b.length())
            return false;
        int cnt = 0;
        for(int i =0 ; i < a.length(); i++){
            if(a[i] == b[i])
                continue;
            cnt+=1;
        }
        return cnt == 1;
           

    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vis.clear();
        gr.clear();
        if(beginWord == endWord)
            return 0; 
        int n = wordList.size();
        queue<string>st;
        st.push(beginWord);
        vis[beginWord] = 1;
        while(!st.empty()){
            auto s = st.front();
            st.pop();


            for(auto a: wordList){
                if(a == s || vis.count(a))
                    continue;
                if(!fun(a, s))
                    continue; 
                vis[a] = vis[s] + 1;
                if(a == endWord)
                    return vis[a];
                st.push(a);
            }
        }
        for(auto a: vis)
            cout<<a.first <<" "<<a.second<<" ;";
        return 0;
    }
};

