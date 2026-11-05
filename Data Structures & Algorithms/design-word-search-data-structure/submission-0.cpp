class WordDictionary {
public:
    WordDictionary* ptr[26];
    bool eof = false;
    WordDictionary() {
        for(int i = 0; i < 26; i++)
            ptr[i] = NULL;

    }
    
    void addWord(string word) {
        WordDictionary* t = this;
        int n = word.length();
        for(int i = 0; i < n; i++){
            int c = int(word[i] - 'a');
            if(t->ptr[c]==NULL)
                t->ptr[c] = new WordDictionary();
            t = t->ptr[c];
        }
        t->eof = true;
        return ;
    }
    bool fun(WordDictionary* t, string &word, int i){
        if(t==NULL)
            return false;
        if(i >= word.length())
            return t->eof;
        int c = (word[i] == '.')?-1: int(word[i] - 'a');
        bool ans = false;
        if(c == -1){
            for(int j = 0; j < 26; j++){
                if(t->ptr[j])
                    ans|=fun(t->ptr[j], word, i+1);
                if(ans)
                    return ans;
            }
            return ans;
        }
        else if(t->ptr[c] != NULL)
            return fun(t->ptr[c], word, i+1);
        return false;
    }
    bool search(string word) {

        WordDictionary* t = this; 
        return fun(t, word, 0);
        
    }
};
