// You are asked to cut off all the trees in a forest for a golf event.
// The forest is represented as an m x n matrix. 
// In this matrix:
// 0 means the cell cannot be walked through.
// 1 represents an empty cell that can be walked through.
// A number greater than 1 represents a tree in a cell that can be 
// walked through, and this number is the tree's height.
// In one step, you can walk in any of the four directions: 
// north, east, south, and west. 
// If you are standing in a cell with a tree, you can choose 
// whether to cut it off.

// You must cut off the trees in order from shortest to tallest. 
// When you cut off a tree, the value at its cell becomes 1 
// (an empty cell).

// Starting from the point (0, 0), return the minimum steps you need
// to walk to cut off all the trees. 
// If you cannot cut off all the trees, return -1.

// Note: The input is generated such that no two trees have the same 
// height, and there is at least one tree needs to be cut off.

// ex1:
// Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
// Output: 6
// Explanation: Following the path above allows you to cut off 
// the trees from shortest to tallest in 6 steps.

// ex2:
// Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
// Output: -1
// Explanation: The trees in the bottom row cannot 
// be accessed as the middle row is blocked.

// Example3:
// Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
// Output: 6
// Explanation: You can follow the same path as Example 1 
// to cut off all the trees.
// Note that you can cut off the first tree at (0, 0) 
// before making any steps.




class Solution {
    static constexpr int DIR[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    struct Cell {
        short r : 8;
        short c : 8;
    };
    int doit(const vector<vector<int>>& forest, Cell start, vector<int> &curr, vector<int> &prev, vector<Cell> &bfs) {
        const int M = forest.size(), N = forest[0].size();
        int steps = 0;
        swap(curr, prev);
        fill(begin(curr), end(curr), -1);
        curr[start.r * N + start.c] = steps;
        if (prev[start.r * N + start.c] != -1) {
            return prev[start.r * N + start.c];
        }
        bfs.clear();
        bfs.push_back(start);
        while (!bfs.empty()) {
            int size = bfs.size();
            steps++;
            while (size--) {
                auto [r0, c0] = bfs[size];
                swap(bfs[size], bfs.back());
                bfs.pop_back();
                for (auto [dr, dc] : DIR) {
                    short r1 = r0 + dr, c1 = c0 + dc;
                    int pos = r1 * N + c1;
                    if (r1 >= 0 && r1 < M && c1 >= 0 && c1 < N && forest[r1][c1] > 0 && curr[pos] == -1) {
                        if (prev[pos] != -1) {
                            return steps + prev[pos];
                        }
                        curr[pos] = steps;
                        bfs.push_back({r1, c1});
                    }
                }
            }
        }
        return -1;
    }
    int manhattan_distance(vector<Cell> &cells) {
        int result = 0;
        Cell prev{0, 0};
        for (auto &cell : cells) {
            result += abs(prev.r - cell.r) + abs(prev.c - cell.c);
            prev = cell;
        }
        return result;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        const int M = forest.size(), N = forest[0].size();
        if (forest[0][0] == 0) {
            return -1;
        }
        int obstacles = 0;
        vector<Cell> cells;
        cells.reserve(8);

        for (short r = 0; r < M; r++) {
            for (short c = 0; c < N; c++) {
                if (forest[r][c] > 1) {
                    cells.push_back({r, c});
                } else if (forest[r][c] == 0) {
                    obstacles++;
                }
            }
        }
        sort(begin(cells), end(cells), [&forest](const Cell &a, const Cell &b){
            return forest[a.r][a.c] < forest[b.r][b.c];
        });
        if (obstacles == 0) {
            return manhattan_distance(cells);
        }
        vector<int> curr(M * N, -1), prev = curr;
        curr[0] = 0;

        vector<Cell> bfs;
        bfs.reserve(8);

        int steps = 0;

        for (auto &cell : cells) {
            int result = doit(forest, cell, curr, prev, bfs);

            if (result != -1) {
                steps += result;
            } else {
                return -1;
            }
        }
        return steps;
    }
};



// use a Breadth-First Search (BFS) approach, which will be efficient 
// for finding the shortest path in an unweighted grid (forest). 
// Instead of using Manhattan distances (which may not account 
// for obstacles), BFS guarantees finding the shortest path 
// in the grid considering obstacles.


class Solution {
public:
    vector<pair<int,int>> directions = {{-1,0},(0,1),{1,0},{0,-1}};
    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc){
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        int steps = 0;

        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ; i < sz; i++){
                auto[r,c] =q.front();
                q.pop();

                if(r == tr && c == tc) return steps;

                for(auto& dir : directions){
                    int nr = r + dir.first, nc = c + dir.second;
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && forest[nr][nc] > 0 && !visited[nr][nc]){
                        q.pus({nr,nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forst[0].size();
        vector<pair<int, pair<int,int>>> trees;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(forest[i][j] > 1){
                    trees.push_back({forest[i][j], {i, j}});
                }
            }
        }
        sort(trees.begin(), trees.end());
        int total_steps = 0;
        int sr = 0, sc = 0;

        for(auto& tree: trees){
            int tr = tree.second.first, tc = tree.second.second;
            int steps = bfs(forest, sr, sc, tr, tc);
            if(steps == -1) return -1;
            total_steps += steps;
            sr = tr;
            sc = tc;
        }
        return total_steps;
    }
};

