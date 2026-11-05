class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int s1 = 0;
        int s2 = 0;
        for(auto a: gas)
            s1+=a;
        for(auto a: cost)
            s2+=a;
        if(s1 < s2)
            return -1;
       
        int curr = 0;
        int st = 0;
        for(int i = 0; i < n; i++){
            curr += (gas[i] - cost[i]);
            if(curr < 0)
            st = i + 1, curr = 0; 
        }
        return st; 
        
        
    }
};
