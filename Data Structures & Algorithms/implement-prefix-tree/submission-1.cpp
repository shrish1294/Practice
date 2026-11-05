class PrefixTree {
public:

    PrefixTree* v[26];
    bool eof = false;
    PrefixTree() {
        
        for(int i = 0; i < 26; i++)
            v[i] = NULL; 
            eof = false;
    }
    
    void insert(string word) {
        
        PrefixTree* tmp = this;
        for(int i = 0; i < word.size(); i++){
            if(tmp->v[word[i]-'a'])
                tmp = tmp->v[word[i]-'a'];
            else{
                tmp->v[word[i]-'a'] = new PrefixTree();
                tmp = tmp->v[word[i]-'a'];
            }
        }
        tmp->eof = true;
    }
    
    bool search(string word) {

         PrefixTree* tmp = this;
          for(int i = 0; i < word.size(); i++){
            if(tmp->v[word[i]-'a'])
                tmp = tmp->v[word[i]-'a'];
            else
                return false;
        }
        return tmp->eof;
    }
    
    bool startsWith(string word) {
        PrefixTree* tmp = this;
          for(int i = 0; i < word.size(); i++){
            if(tmp->v[word[i]-'a'])
                tmp = tmp->v[word[i]-'a'];
            else
                return false;
        }
        return true;
    }
};
