class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        rows, cols = len(grid), len(grid[0])
        for row in range(rows):
            for col in range(cols):
                if row == col or row + col == rows - 1:
                    if grid[row][col] == 0:
                        return False
                elif grid[row][col] != 0:
                    return False
        return True
                    
        