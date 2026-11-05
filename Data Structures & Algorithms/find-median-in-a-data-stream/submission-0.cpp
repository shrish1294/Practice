class MedianFinder {
public:
    priority_queue<int>q1;
    priority_queue<int, vector<int>, greater<int>>q2;
    MedianFinder() {
        while(!q1.empty())
            q1.pop();

        while(!q2.empty())
            q2.pop();
    }
    
    void addNum(int num) {
        if(q1.empty()){
           q1.push(num);
            return ;
        }
        if(q1.top() >= num)
            q1.push(num);
        else
            q2.push(num);
        
        while(int(q1.size()) - int(q2.size()) > 1){
            auto it = q1.top();
            q1.pop();
            q2.push(it);
        }
        while(int(q2.size()) - int(q1.size()) > 1){
            auto it = q2.top();
            q2.pop();
            q1.push(it);
        }
        return ;

        
    }
    
    double findMedian() {
        int f1 = 0;
        int f2 = 0;
        if(!q1.empty())
            f1 = q1.top();
        if(!q2.empty())
            f2 = q2.top();
        if(q1.size() == q2.size())
            return double(f1 + f2)/2.0;
        else
            return (q1.size() > q2.size())? f1: f2;  
    }
};
