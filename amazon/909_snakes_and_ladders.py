

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)

        def getPosition(square: int) -> Tuple[int, int]:
            row = (square - 1) // n
            col = (square - 1) % n
            if row % 2 == 1: #reverse column index on odd rows
                col = n -1 - col
            return (n-1-row, col)

        visited = [False] * (n * n + 1)
        queue  = deque([(1,0)])
        visited[1] = True

        while queue:
            curr, moves = queue.popleft()
            
            for i in range (1,7):
                next_square = curr + i
                if next_square > n * n:
                    break

                r,c = getPosition(next_square)

                if board[r][c] != -1:
                    next_square = board[r][c]

                if next_square == n * n: 
                    return moves + 1

                if not visited[next_square]:
                    visited[next_square] = True
                    queue.append((next_square, moves + 1))

        return -1