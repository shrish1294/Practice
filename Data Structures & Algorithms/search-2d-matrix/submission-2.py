class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        m, n = len(matrix), len(matrix[0])
        
        l = 0
        r = m*n - 1

        while l <= r:
            mid = (l + r) // 2
            j = mid % n
            i = (mid - j) // n 
            if matrix[i][j] == target:
                return True
            if matrix[i][j] > target:
                r = mid - 1
            else:
                l = mid + 1
        
        return False