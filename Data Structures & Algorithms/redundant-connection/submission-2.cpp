class Solution {
public:

    
    vector<int>p;

    int get_par(int i){
        if(p[i] == -1)
            return i; 
        return get_par(p[i]);
    }




    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        p.clear();
        p.resize(100, -1);

        for(auto a: edges){
            int p1 = get_par(a[0]);
            int p2 = get_par(a[1]);
            if(p1 == p2)
                return a;
            if(a[0] != p1)
                p[p2] = p1;
            else
                p[p1] = p2; 
        }
        return {};
     
    }
};
