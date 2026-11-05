class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int l = 0, r = n1;
        int med = (n1 + n2 - 1) / 2; 

        while(l<=r){

            int elements_from_first_arr = (l + r) / 2;
            int elements_from_second_arr = med - elements_from_first_arr;
             
            int left1 = (elements_from_first_arr - 1 < 0)?INT_MIN:
                             nums1[elements_from_first_arr - 1];
            
            int right1 = (elements_from_first_arr + 1 >=n1)?INT_MAX:
                             nums1[elements_from_first_arr + 1];
            
            int left2 = (elements_from_second_arr - 1 < 0)? INT_MIN:
                             nums2[elements_from_second_arr - 1];
            int right2 = (elements_from_second_arr + 1 >=n2)? INT_MAX:
                             nums2[elements_from_second_arr + 1];
            
            if(elements_from_first_arr >= n1){
                if((n1 + n2)&1)
                    return nums2[elements_from_second_arr];
                else
                    return double(nums2[elements_from_second_arr] + right2) / 2.0; 
            } 
            if(elements_from_second_arr >= n2){
                 if((n1 + n2)&1)
                    return nums1[elements_from_second_arr];
                else
                    return double(nums1[elements_from_second_arr] + right1) / 2.0; 
            }
            if(left1 > nums2[elements_from_second_arr])
                r = elements_from_first_arr - 1;
            else if(left2 > nums1[elements_from_first_arr])
                l = elements_from_first_arr + 1;
            else{
                multiset<int>st;
                st.insert(nums1[elements_from_first_arr]);
                st.insert(right1);
                st.insert(nums2[elements_from_second_arr]);
                st.insert(right2);

                if((n1 + n2) & 1)
                    return *st.begin();
                double a = *st.begin();
                st.erase(st.begin());
                a  = a + *st.begin();
                return double(a)/2.0;
            }
        }
        return -1;




    }
};


