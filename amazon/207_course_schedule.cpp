
// There are a total of numCourses courses you have to take, 
// labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites
// [i] = [ai, bi] indicates that you must take course bi first 
// if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you 
// have to first take course 1.
// Return true if you can finish all courses. 
// Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you 
// should also have finished course 1. So it is impossible.
 

// Constraints:
// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

#include <vector>
using namespace std;

//Depth-first-search
// Implementation Using DFS and Color Marking:
// We'll use three colors to mark nodes during DFS:

// White (0): The node has not been visited.
// Gray (1): The node is currently being visited (part of the current DFS path).
// Black (2): The node and all its descendants have been fully processed.
// If during DFS we encounter a node that is already marked Gray, 
// it means we have found a cycle.
class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        //create an adjency list for the graph
        vector<vector<int>> adj(numCourses);
        for(const auto& pair: prerequisites){
            adj[pair[1]].push_back(pair[0]);
        }
        //VECTOR to keep track of visited nodes(0-white, 1-gray, 2-black)
        vector<int> visited(numCourses, 0);
        //dfs function to detect the cycle
        function<bool(int)> hasCycle = [&](int node){
            if(visited[node] == 1) return true;
            if(visited[node] == 2) return false;

            visited[node] = 1;
            for(int neighbor : adj[node]){
                if(hasCycle(neighbor)){
                    return true;
                }
            }
            visited[node] = 2;//mark as black (fully visited)
            return false;
        };

        //check each course for cycles
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(hasCycle(i)){
                    return false; // cycle detected.
                }
            }
        }
        return true;

    }
};

//using kahn's Algorithm

// Kahn's Algorithm is a BFS-based approach for topological sorting of 
// a Directed Acyclic Graph (DAG). If we can complete a topological sort 
// of all the courses (i.e., visit all nodes), then it’s possible to finish 
// all courses; otherwise, there’s a cycle, and it’s not possible.

// Kahn’s Algorithm:
// 1:In-Degree Calculation: For each course, count the number of prerequisites (in-degrees).
// 2:Queue Initialization: Initialize a queue with all nodes that have an in-degree of 0 
// (courses with no prerequisites).
// 3:Process the Queue: Repeatedly remove nodes from the queue, reduce the in-degree of their 
// neighbors, and add any neighbors with an in-degree of 0 to the queue.
// 4:Check Completion: If the number of nodes processed equals the total number of courses, 
// it’s possible to complete all courses; otherwise, it’s not.

class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(const auto& pair: prerequisites){
            adj[pair[1]].push_back(pair[0]);
            inDegree[pair[0]]++;//increment indegree of course pair[0]
        }

        //step2;initialize the queue with all courses that have in-degree of 0
        queue<int> q;
        for(int i =0; i < numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int coursesProcessed = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop(); 
            coursesProcessed++;

            //for each course that depends in this course.
            for(int neighbor: adj[course]){
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        // sstep4 checf if the we are able to process all courses;
        return coursesProcessed = numCourses;
    }
};