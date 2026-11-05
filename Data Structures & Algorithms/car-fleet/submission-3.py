class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        
        n = len(position)
        arr = [0]*n
        for i, j in enumerate(position):
            arr[i] = (j, (target - j) /speed[i])
        
        arr = sorted(arr, key= lambda x: x[0])

        st = deque()

        for i in arr: 
            if len(st) == 0:
                st.append(i[1])
            else:
                while len(st) and st[-1] <= i[1]:
                    st.pop()
                st.append(i[1])
        
        return len(st)