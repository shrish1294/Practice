class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pair<int, float>>v(n); 
        for(int i = 0 ; i < n; i++){
            v[i] = {position[i], float(target - position[i])/float(speed[i])};
        }
        sort(v.begin(), v.end());

        stack<float>last;
        last.push(v.back().second);
        for(int i = n-2; i >=0; i--){
            if(last.top() < v[i].second)
                last.push(v[i].second);
        }
        return last.size();


    }
};
