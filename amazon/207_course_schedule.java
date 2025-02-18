
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.List;
//dfs/ cycle detection

import java.util.ArrayList;

class Solution{
    public boolean canFinish(int numCourses, int[][] prerequisites){

        List<List<Integer>>adj = new ArrayList<>();
        for(int i =0; i < numCourses; i++){
            adj.add(new ArrayList<>());
        }
        for (int[] pair: prerequisites){
            adj.get(pair[1]).add(pair[0]);
        }
        int[] visited = new int[numCourses];

        for(int i =0; i < numCourses; i++){
            if(visited[i] == 0){
                if(hasCycle(i, adj, visited)){
                    return false;
                }
            }
        }
        return true;
    }

    private boolean hasCycle(int v, List<List<Integer>> adj, int[] visited){
        if(visited[v] == 1){
            return true;
        }
        if(visited[v] == 2){
            return false;
        }
        visited[v] = 1;

        for(int neighbor: adj.get(v)){
            if(hasCycle(neighbor, adj, visited)){
                return true;
            }
        }
        visited[v] = 2;
        return false;
    }
}


//Kahn's algorithm
class Solution{
    public boolean canFinish(int numCourses, int[][] prerequisites){
        List<List<Integer>> adj = new ArrayList<>();
        int[] inDegree = new int[numCourses];
        for(int i =0;i < numCourses;i++){
            adj.add(new ArrayList<>());
        }
        for(int[] pair : prerequisites){
            adj.get(pair[1]).add(pair[0]);
            inDegree[pair[0]]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        for(int i =0; i < numCourses; i++){
            if(inDegree[i] == 0){
                queue.add(i);
            }
        }

        int coursesProcessed = 0; 
        while(!queue.isEmpty()){
            int course = queue.poll();
            coursesProcessed++;

            for(int neighbor: adj.get(course)){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0){
                    queue.add(neighbor);
                }
            }
        }
        return coursesProcessed == numCourses;
    }
}