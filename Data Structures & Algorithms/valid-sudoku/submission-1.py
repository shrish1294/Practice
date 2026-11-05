class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        col_dict = defaultdict(dict)
        row_dict = defaultdict(dict)
        box_dict = defaultdict(dict)

        m = len(board)
        n = len(board[0])

        for i in range(0, m):
            for j in range(0, n):
                val = board[i][j]
                if val == ".":
                    continue
                if row_dict[i].get(val):
                    return False
                if col_dict[j].get(val): 
                    return False
                r1 = i // 3
                c1 = j // 3
                box_no = r1 * 3 + c1
                # print(box_no)
                if box_dict[box_no].get(val):
                    return False
                row_dict[i][val] = True
                col_dict[j][val] = True
                box_dict[box_no][val] = True

        return True
