import java.util.ArrayList;
import java.util.Queue;

class Solution {

    private static final int[][] DIRECTIONS = {{-1,0},{1,0},{0,-1},{0,1}};
    private int bfs(List<List<Integer>> forest,int sr, int sc, int tr, int tc){
        int m = forest.size();
        int n = forest.get(0).size();
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{sr,sc,0});
        visited[sr][sc] = true;

        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            int r = cur[0], c = cur[1], steps = cur[2];

            if(r == tr && c == tc) return steps;

            for(int[] dir : DIRECTIONS){
                int nr = r + dir[0], nc = c + dir[1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && forest.get(nr).get(nc) > 0){
                    queue.add(new int[]{nr, nc, steps +1});
                    visited[nr][nc] = true;
                }
            }
        }
        return -1;
    }

    public int cutOffTree(List<List<Integer>> forest) {
        int m = forest.size();
        int n = forest.get(0).size();

        List<int[]> trees = new ArrayList<>();
        for(int i = 0; i < m ; i++){
            for(int j =0; j < n; j++){
                int height = forest.get(i).get(j);
                if(height > 1){
                    trees.add(new int[]{height, i, j});
                }
            }
        }
        Collections.sort(trees, Comparator.comparingInt(a->a[0]));
        int totalSteps = 0;
        int sr = 0, sc = 0;

        for(int[] tree: trees){
            int tr = tree[1], tc = tree[2];
            int steps = bfs(forest, sr, sc, tr, tc); 
            if(steps == -1) return -1;
            totalSteps += steps;
            sr = tr;
            sc = tc;
        }
        return totalSteps;
    }
}