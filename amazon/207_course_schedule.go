
//dfs
func canFinish(numCourses int, prerequisites [][]int) bool{
	//building adjency list
	adj := make([][]int, numCourses)
	for _, pair:= range prerequisites{
		adj[pair[1]] = append(adj[pair[1]], pair[0])
	}

	//create a visited array
	visited := make([]int, numCourses)
	//defin DFS function for cycle detection
	var hasCycle func(int) bool
	hasCycle = func(v int) bool{
		if visited[v] ==1 {
			return true
		}
		if visited[v]==2{
			return false
		}
		visited[v] =1

		for _, neighbor:= range adj[v]{
			if hasCycle(neighbor){
				return true
			}
		}
		visited[v] = 2
		return false
	}
	//chech each coruse for cycles
	for i := 0; i < numCourses; i++{
		if visited[i] == 0{
			if hasCycle(i){
				return false
			}
		}
	}
	return true
}


//bfs via Kahn's ALgorithm

import "container/list"

func canFinish(numCourses int, prerequisites [][]int) bool{
	//build adjacency list and in-degree array
	adj := make([][]int, numCourses)
	inDegree := make([]int, numCourses)

	for _, pair:= range prerequisites{
		adj[pair[1]] = append(adj[pair[1]], pair[0])
		inDegree[pair[0]]++
	}
	//initialise the queue with courses that have in-degree of 0
	queue:= list.New()
	for i:= 0 ; i < numCourses; i++{
		if inDegree[i] == 0{
		queue.PushBack(i)
		}
	}

	processedCourses := 0
	for queue.Len() > 0{
		course := queue.Remove(queue.Front()).(int)
		processedCourses++

		for _, neighbor := range adj[course]{
			inDegree[neighbor]--
			if inDegree[neighbor] == 0 {
				queue.PushBack(neighbor)
			}
		}
	}
	return processedCourses == numCourses
}