

#DFS- based solution(cycle detection) 
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #create adjacency list for the graph 
        adj = [[] for _ in range(numCourses)]
        for dest, src in prerequisites:
            adj[src].append(dest)

        #stages 0 = unvisited, 1 = visiting, 2= visited
        visited = [0] * numCourses

        def hasCycle(v):
            if visited[v] == 1: #found a cycle       
                return True
            if visited[v] == 2:
                return False

            visited[v] = 1

            for neighbor in adj[v]:
                if hasCycle(neighbor):
                    return True

            visited[v] = 1

            for neighbor in adj[v]:
                if hasCycle(neighbor):
                    return True

            visited[v] =2
            return False

        for i in range(numCourses):
            if visited[i] == 0:
                if hasCycle(i):
                    return False

        return True

#DFS (Kahn's Algorithm) efficiency++ for the case.
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]])->bool:
        #create an adjacency list and calculate in-degrees
        adj = [[] for _ in range(numCourses)]
        inDegree = [0] * numCourses

        for dest, src in prerequisites:
            adj[src].append(dest)
            inDegree[dest] += 1

        #initilize the queue with all courses that have in degree of 0
        queue = deque()
        for i in range(numCourses):
            if inDegree[i] == 0:
                queue.append(i)

        #process the queue
        coursesProcessed = 0
        while queue:
            course = queue.popleft()
            coursesProcessed +=1

            for neighbor in adj[course]:
                inDegree[neighbor] -=1
                if inDegree[neighbor] == 0:
                    queue.append(neighbor)

        #rcheck if we were able to process all courses
        return coursesProcessed == numCourses