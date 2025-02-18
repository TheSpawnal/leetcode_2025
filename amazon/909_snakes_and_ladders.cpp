
// You are given an n x n integer matrix board where the cells are labeled from 
// 1 to n2 in a Boustrophedon style starting from the bottom left of the 
// board (i.e. board[n - 1][0]) and alternating direction each row.

// You start on square 1 of the board. In each move, starting from square 
// curr, do the following:

// Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
// This choice simulates the result of a standard 6-sided die roll: i.e., there are always 
// at most 6 destinations, regardless of the size of the board.
// If next has a snake or ladder, you must move to the destination of that snake or ladder. 
// Otherwise, you move to next.
// The game ends when you reach the square n2.
// A board square on row r and column c has a snake or ladder if board[r][c] != -1. 
// The destination of that snake or ladder is board[r][c]. 
// Squares 1 and n2 are not the starting points of any snake or ladder.

// Note that you only take a snake or ladder at most once per move. 
// If the destination to a snake or ladder is the start of another snake or ladder, 
// you do not follow the subsequent snake or ladder.

// For example, suppose the board is [[-1,4],[-1,3]], and on the first move, 
// your destination square is 2. You follow the ladder to square 3, 
// but do not follow the subsequent ladder to 4.
// Return the least number of moves required to reach the square n2. 
// If it is not possible to reach the square, return -1.

 

// Example 1:


// Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
// Output: 4
// Explanation: 
// In the beginning, you start at square 1 (at row 5, column 0).
// You decide to move to square 2 and must take the ladder to square 15.
// You then decide to move to square 17 and must take the snake to square 13.
// You then decide to move to square 14 and must take the ladder to square 35.
// You then decide to move to square 36, ending the game.
// This is the lowest possible number of moves to reach the last square, so return 4.
// Example 2:

// Input: board = [[-1,-1],[-1,3]]
// Output: 1

using namespace std;

class Solution{
public:
    int snakesAndLadders(vector<vector<int>>& board){
        int n = board.size();
    //lambda pattern to convert square number to (row, col) considering Boustrophedon pattern
        auto getPosition = [&](int square) -> pair<int, int> {
            int row = (square - 1) / n;
            int col = (square - 1) % n;
            if(row % 2 == 1){
                col = n - 1 - col; 
            }
            return {n-1-row, col};
        };
        vector<int> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1,0}); //start at square 1 with 0 moves
        visited.at(1) = true;

        while(!q.empty()){
            int curr = q.front().first;
            int moves = q.front().second;
            q.pop();

            for(int i = 1; i <= 6; i++){
                int next = curr +i;
                if(next > n * n) break;
                auto[r, c] = getPosition(next);
                if(board.at(r).at(c) != -1){
                    next = board.at(r).at(c); //move to the destination of the snake/ladder
                }
                if(next == n * n ) return moves + 1;
                if(!visited.at(next)){
                    visited.at(next) = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1; //if the last square is unreachable
    }
};


//whitout using auto


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        // Define the lambda function with explicit types
        function<pair<int, int>(int)> getPosition = [&](int square) -> pair<int, int> {
            int row = (square - 1) / n;
            int col = (square - 1) % n;
            if (row % 2 == 1) {
                col = n - 1 - col;  // Reverse column index on odd rows
            }
            return make_pair(n - 1 - row, col);  // Return (row, col) in terms of board indices
        };

        vector<int> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});  // Start at square 1 with 0 moves
        visited.at(1) = true;

        while (!q.empty()) {
            int curr = q.front().first;
            int moves = q.front().second;
            q.pop();

            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n) break;
                pair<int, int> pos = getPosition(next); // Explicitly call the lambda
                int r = pos.first;
                int c = pos.second;

                if (board.at(r).at(c) != -1) {
                    next = board.at(r).at(c);  // Move to the destination of the snake/ladder
                }

                if (next == n * n) return moves + 1;  // Reached the last square

                if (!visited.at(next)) {
                    visited.at(next) = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;  // If the last square is unreachable
    }