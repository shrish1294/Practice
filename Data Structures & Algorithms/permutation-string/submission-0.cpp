class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2)
            return false;

        vector<int>v1(26, 0), v2(26, 0);

        for(int i = 0; i < len1; i++){
            v1[s1[i]-'a']+=1;
            v2[s2[i]-'a']+=1;
        }
        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(v1[i] == v2[i])
                matches+=1;
        }
        if(matches == 26)
            return true; 
        
        int l = 0, r = len1; 

        while(r < len2){
            if(matches == 26)
                return true;

            int c1 = s2[l]-'a';
            int c2 = s2[r] -'a'; 
            if(v1[c1]  == v2[c1])
                matches-=1;
            if(v1[c2] == v2[c2])
                matches-=1; 
            v2[c1]-=1;
            
            v2[c2]+=1;
            if(v2[c2] == v1[c2])
                matches+=1;
            if(v1[c1] == v2[c1])
                matches+=1; 
            l++;
            r++; 
        }
        return matches == 26;


        
    }
};
