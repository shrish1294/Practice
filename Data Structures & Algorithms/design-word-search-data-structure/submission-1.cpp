class WordDictionary {
public:

    WordDictionary* v[26];
    bool eof = false;

    WordDictionary() {
        for(int i = 0; i < 26; i++)
            v[i] = NULL; 
        eof = false;
    }
    
    void addWord(string word) {
         WordDictionary* t = this;
        for(int i = 0; i < word.size(); i++){
                if(!t->v[word[i]-'a'])
                    t->v[word[i]-'a'] = new WordDictionary();
                t = t->v[word[i]-'a'];
        }
        t->eof = true; 
    }
    
    bool check(int i, string &s,  WordDictionary* t){
            if(i >=s.length())
                return t->eof; 
            if(s[i]!='.' && !t->v[s[i] -'a'] )
                return false;
            if(s[i]!='.' && t->v[s[i]-'a'])
                return check(i + 1, s, t->v[s[i]-'a']);
            bool ans = false;
            for(int j = 0; j < 26 && s[i] == '.'; j++){
                if(t->v[j])
                    ans |= check(i + 1, s, t->v[j]);
                if(ans)
                    return ans;
            }   
            return ans;          
    }

    bool search(string word) {
        WordDictionary* t = this;
        return check(0, word, t);
        
    }
};
