class PrefixTree {
public:
    PrefixTree* vec[26];
    bool eof = false;
    PrefixTree() {
        for(int i = 0 ; i < 26; i++)
            vec[i] = NULL;

    }
    
    void insert(string word) {
        PrefixTree* t = this; 
        int n = word.length();
        for(int i = 0; i < n; i++){
            int c = int(word[i] - 'a');
            if(t->vec[c]==NULL)
                t->vec[c] = new PrefixTree();
            t = t->vec[c];
        }
        t->eof = true;
        return ;
    }
    
    bool search(string word) {
        PrefixTree* t = this; 
        int n = word.length();
        for(int i = 0; i < n; i++){
            int c = int(word[i] - 'a');
            if(t->vec[c]==NULL)
                return false;
            t = t->vec[c];
        }
        return t->eof;
    }
    
    bool startsWith(string word) {
        PrefixTree* t = this; 
        int n = word.length();
        for(int i = 0; i < n; i++){
            int c = int(word[i] - 'a');
            if(t->vec[c]==NULL)
                return false;
            t = t->vec[c];
        }
        return true;
    }
};
