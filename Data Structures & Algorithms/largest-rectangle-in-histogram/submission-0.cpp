class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<int>st;
        vector<int>left(n), right(n);
        left[0] = 0;
        right[n-1] = n-1;
        st.push(0);
        for(int i = 1 ; i < n; i++){
            left[i] = i;
            while(!st.empty() && heights[st.top()] >= heights[i])
                left[i] = left[st.top()], st.pop();
            
            
            // if(!st.empty())
            //     left[i] = left[st.top()];
            st.push(i);
           
        }
        while(!st.empty())
            st.pop();
        st.push(n-1);
        right[n-1] = n-1;
        for(int i = n-2 ; i >=0; i--){
            
            right[i] = i; 
            while(!st.empty() && heights[st.top()] > heights[i])
                right[i] = right[st.top()], st.pop();
            
            
            // if(!st.empty())
            //     right[i] = right[st.top()];
            st.push(i);
       
        }

        int ans = 0;

        for(auto a: left)
            cout<<a<<" ";
        cout<<"\n";
        for(auto b: right)
            cout<<b<<" ";

        for(int i =0 ;i < n; i++){
            int val = heights[i] * (abs(left[i] - right[i]) + 1);
            ans = max(ans, val);
        }
        return ans; 




    }
};
