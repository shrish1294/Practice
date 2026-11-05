class Solution {
public:
    
    class Comp{
        public:
        bool operator()(vector<int>&a, vector<int>&b){
            
            if(a[0] > b[0])
                return true; 
            if(a[0] == b[0])
                return a[1] < b[1];
            return false;
        }
    };


    int leastInterval(vector<char>& tasks, int n) {


        priority_queue<vector<int>>pq;
        vector<int>v(26, 0);
        for(auto a: tasks)
            v[a-'A']+=1;

        // for(auto a: v)
        //     cout<<a<<" ";
        for(int i = 0; i < 26; i++){
            auto a = v[i];
            if(a==0)continue;
            pq.push({a, 0, i});
        }
        int t = 0;
        int c = 0;
        queue<vector<int>>q;

        while(!pq.empty()){

           

            auto it = pq.top();
            
            pq.pop();
            t = max(t, it[1]);
           
            
            t+=1;
            it[1] = t + n;
            it[0]-=1;
            // cout<<it[0] << " "<<it[1] <<" "<<it[2]<<"\n";
            if(it[0]>0){
                q.push(it);
            }
             if(pq.empty() && !q.empty()){
                t = max(t, q.front()[1]);
            }
            while(!q.empty() && q.front()[1] <= t)
            {
                pq.push(q.front());
                cout<<"gefe";
                q.pop();
            }
            // cout<<t<<" ";
          
        }



        return t;
        
        
    }
};
