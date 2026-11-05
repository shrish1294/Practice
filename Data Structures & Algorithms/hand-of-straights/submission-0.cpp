class Solution {
public:
    
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if(n % groupSize)
            return false;
        multiset<int>st;
        for(auto a: hand)
            st.insert(a);

        while(st.size()){
            auto it = *st.begin();
            for(int i = it;  i < it + groupSize ; i++){
                if(st.find(i) != st.end())
                    st.erase(st.find(i));
                else
                    return false;
            }
        }
        return true; 
    }

};
