import java.util.*;

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        
        // Call BFS to find the minimum number of moves
        return bfs(board, n);
    }

    private int bfs(int[][] board, int n) {
        boolean[] visited = new boolean[n * n + 1];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{1, 0});  // Start at square 1 with 0 moves
        visited[1] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currSquare = current[0];
            int moves = current[1];

            for (int i = 1; i <= 6; i++) {
                int nextSquare = currSquare + i;
                if (nextSquare > n * n) break;

                int[] pos = getPosition(nextSquare, n);
                int r = pos[0];
                int c = pos[1];

                if (board[r][c] != -1) {
                    nextSquare = board[r][c];  // Move to the destination of the snake/ladder
                }

                if (nextSquare == n * n) return moves + 1;  // Reached the last square

                if (!visited[nextSquare]) {
                    visited[nextSquare] = true;
                    queue.offer(new int[]{nextSquare, moves + 1});
                }
            }
        }

        return -1;  // If the last square is unreachable
    }

    private int[] getPosition(int square, int n) {
        int row = (square - 1) / n;
        int col = (square - 1) % n;
        if (row % 2 == 1) {
            col = n - 1 - col;  // Reverse column index on odd rows
        }
        return new int[]{n - 1 - row, col};  // Return (row, col) in terms of board indices
    }
}
