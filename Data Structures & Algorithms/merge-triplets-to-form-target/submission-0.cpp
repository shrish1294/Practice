class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        

        int n = triplets.size();
        vector<int>t1 = {}; 
        for(int i = 0; i < n; i++){
            if(triplets[i][0] == target[0] && triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2])
                    t1 = triplets[i];

        }
        if(t1.size() == 0)
            return false;
        t1 = {};
        for(int i = 0; i < n; i++){
            if(triplets[i][0] <= target[0] && triplets[i][1] == target[1] &&
                triplets[i][2] <= target[2])
                    t1 = triplets[i];

        }
        if(t1.size() == 0)
            return false;
        t1 = {};
        for(int i = 0; i < n; i++){
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] &&
                triplets[i][2] == target[2])
                    t1 = triplets[i];

        }
        if(t1.size() == 0)
            return false;
        return true; 


    }
};
