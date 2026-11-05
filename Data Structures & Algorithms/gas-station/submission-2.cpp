class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int s1 = 0, s2 = 0;
        for(auto a: gas)
            s1 += a;
        for(auto a: cost)
            s2 += a; 
        
        if(s2 > s1)
            return -1;
        
        int t = 0;
        int n = gas.size();
        int i =0, j = 0;
        int curr = 0;
        while(j < n){
            curr+=gas[j] - cost[j];
            
            while(curr < 0 && i <= j){
                curr -= (gas[i] - cost[i]);
                i++;
            }
            j++;
        }
        return i ; 


        
    }
};
