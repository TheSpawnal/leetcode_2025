'''
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1

Follow up:
    A straightforward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

'''

#bitmask
class Solution:
    def setZeroes(self, matrix: List[List[int]])-> None:
      #do not return anything, modify mx in place instead
        n,m = len(matrix), len(matrix[0])
        col0, row0 = 0, 0
        for i, row in enumerate(matrix):
            for j, x in enumerate(row):
                if x == 0:
                    row0 |= (1<<i)
                    col0 |=(1<<j)
        for i in range(n):
            if(row0 >> i) &1:
                for j in range(m):
                    matrix[i][j]=0
        for j in range(m):
            if (col0 >> j) &1:
                for i in range(n):
                    matrix[i][j]=0


#hashset
class Solution:
    def setZeroes(self, matrix: List[List[int]])-> None:
      #do not return anything, modify mx in place instead
        n,m = len(matrix), len(matrix[0])
        col0, row0 =set(),set()
        for i, row in enumerate(matrix):
            for j, x in enumerate(row):
                if x == 0:
                    row0.add(i)
                    col0.add(j)
        for i in row0:
                for j in range(m):
                    matrix[i][j]=0
        for j in col0:
                for i in range(n):
                    matrix[i][j]=0

#in place solution:
class Solution:
    def setZeroes(self, matrix, List[List[int]])->None:
    n,m = len(matrix), len(matrix[0])
    row0 = any(x == 0 for x in matrix[0])
    col0 = any(x[0] == 0 for x in matrix)

    for i in range(1,n):
        for j in range (1,m):
            if matrix[i][j] =0:
                matrix[i][0]=0
                matrix[0][j]=0
    for i in range(1,n):
        if matrix[i][0] == 0:
            for j in range(m):
                matrix[i][j] = 0
    for j in range(1,m):
            if matrix[0][j] == 0:
                for i in range(n):
                    matrix[i][j] =0
    if row0:
        for j in range(m):
            matrix[0][j] = 0
    if col0:
        for i in range(n):
            matrix[i][0] = 0





