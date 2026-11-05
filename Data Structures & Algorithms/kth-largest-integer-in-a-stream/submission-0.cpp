class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>p1;
    int K ;

    KthLargest(int k, vector<int>& nums) {
        while(!p1.empty())
            p1.pop();
        K = k ;
       
        for(auto a: nums){
            if(p1.empty() || p1.size() < k)
                p1.push(a);
            else if(a > p1.top()){
                p1.pop();
                p1.push(a);
            }
        }
    }
    
    int add(int val) {
        if(p1.size() < K)
            p1.push(val);
        else if(val > p1.top()){
                p1.pop();
                p1.push(val);
            }
        return p1.top();
    }
};
