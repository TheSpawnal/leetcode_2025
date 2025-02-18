

class Solution:
    def bfs(self, forest: List[List[int]], sr: int, sc: int, tr: int, tc: int) -> int :
        if sr == tr and sc == tc:
            return 0
        m,n = len(forest),len(forest[0])
        queue = deque([(sr, sc, 0)]) # (row,col,steps)
        visited = set((sr, sc))
        directions=[(-1, 0),(1,0),(0,-1),(0,1)] #up, down, left, right

        while queue:
            r,c, steps = queue.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and (nr,nc) not in visited and forest[nr][nc] > 0:
                    if nr == tr and nc == tc:
                        return steps + 1
                    queue.append((nr,nc,steps+1))
                    visited.add((nr, nc))

        return -1

    def cutOffTree(self, forest: List[List[int]]) -> int:
        m,n = len(forest),len(forest[0])
        #collect all trees with their heights and positions
        trees = sorted((h,r,c) for r, row in enumerate(forest) for c, h in enumerate(row) if h > 1)
        # start from(0, 0)
        sr, sc = 0, 0
        total_steps = 0

        for _, tr, tc in trees:
            steps = self.bfs(forest, sr, sc, tr, tc)
            if steps == -1:
                return -1
            total_steps += steps
            #move the starting point to the current tree;s position
            sr, sc = tr, tc

        return total_steps
        