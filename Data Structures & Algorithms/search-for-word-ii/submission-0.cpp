class trie{
public:
    trie* ptr[26];
    bool eof = false;
    trie(){
        for(int i = 0; i < 26; i++)
            ptr[i] = NULL;
    }
    void insert(string word){
        trie* t = this;
        int n = word.length();
        for(int i =0 ; i < n; i++){
            int c = int(word[i] - 'a');
            if(t->ptr[c] == NULL)
                t->ptr[c] = new trie();
            t = t->ptr[c];
        }
        t->eof = true;
    }
};

class Solution {
public:
    vector<vector<bool>>vis; 
    set<string>ans;
    int m, n;
    void fun(vector<vector<char>>& v, trie* t, int x, int y, 
    string &curr){
        if(t == NULL)
            return ;
        if(t->eof)
            ans.insert(curr);
        
        vector<pair<int, int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

       
        for(auto a: dir){
            int X = x + a.first;
            int Y = y + a.second;
            if(X < 0 || X >= m || Y < 0 || Y >= n  || vis[X][Y])
                continue;

            int c = int(v[X][Y] - 'a');
            if(!t->ptr[c])
                continue;
            vis[X][Y] = true;
            curr.push_back(v[X][Y]);
            fun(v, t->ptr[c], X, Y, curr);
            curr.pop_back();
            vis[X][Y] = false;
        }
        

    }

    vector<string> findWords(vector<vector<char>>& board, 
    vector<string>& words) {
        m = board.size();
        n = board[0].size();
        trie* root = new trie();
        for(auto a: words)
            root->insert(a);

        ans.clear();
        vis.clear();
        vis.resize(m, vector<bool>(n, false));
        string s = "";
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int c = int(board[i][j] - 'a');
                if(!root->ptr[c])
                    continue;
                vis[i][j] = true;
                s.push_back(board[i][j]);
                fun(board, root->ptr[c], i, j, s);
                vis[i][j] = false;
                s.pop_back();
            }
        }

        vector<string>v;
        for(auto a: ans)
            v.push_back(a);
        return v;
        
    }
};
