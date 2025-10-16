# Given an array of points where points[i] = [xi, yi] 
# represents a point on the X-Y plane and an integer k, 
# return the k closest points to the origin (0, 0).

# The distance between two points on the X-Y plane is the 
# Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).
# You may return the answer in any order. 
# The answer is guaranteed to be unique (except for the order that it is in).

# Input: points = [[1,3],[-2,2]], k = 1
# Output: [[-2,2]]
# Explanation:
# The distance between (1, 3) and the origin is sqrt(10).
# The distance between (-2, 2) and the origin is sqrt(8).
# Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
# We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
# Example 2:

# Input: points = [[3,3],[5,-1],[-2,4]], k = 2
# Output: [[3,3],[-2,4]]
# Explanation: The answer [[-2,4],[3,3]] would also be accepted.

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for (x, y) in points:
            dist = -(x*x + y*y)
            if len(heap) == k:
                heapq.heappushpop(heap, (dist, x, y))
            else:
                heapq.heappush(heap,(dist,x,y))

        return [(x,y) for (dist,x,y) in heap]
        
# The time complexity of the provided code is O(n log k), 
# where n is the number of points and k is the value of the parameter k.

# Let's break down the time complexity:

# Iterating through the points list takes O(n) time, where n is the
#  number of points.
# For each point, calculating the distance dist takes constant time.
# If the heap has already k elements, heapq.heappushpop() is called, which 
# takes O(log k) time to push the new element and pop the smallest element
#  from the heap.
# If the heap has less than k elements, heapq.heappush() is called,
#  which takes O(log k) time to push the new element into the heap.
# Finally, constructing the result list takes O(k) time.
# Since steps 3 and 4 are performed for each point, the overall time complexity
#  is O(n log k).

# The space complexity of the code is O(k), where k is the
#  value of the parameter k. This is because the code uses a heap of size k
#   to store the closest points. The result list also has a
# maximum size of k. 
# Therefore, the space complexity is proportional to the value of k.


#extreme memory friendly alternative solution: 
import math
import heapq

class Solution:
    def chooseIndex(self, left: int, right: int) -> List[int]:
        return left + (right - left) // 2

    def getDistance(self, coords):
        x, y = coords
        return math.sqrt(x**2 + y**2)
        
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def partition(left, right):
            pivot_i = self.chooseIndex(left, right)
            pivot = self.getDistance(points[pivot_i])
            swap_i = left

            points[right], points[pivot_i] = points[pivot_i], points[right]

            for i in range(left, right):
                if self.getDistance(points[i]) < pivot:

                    points[i], points[swap_i] = points[swap_i], points[i]
                    swap_i+=1

            points[right], points[swap_i] = points[swap_i], points[right]
            return swap_i

        left = 0
        right = len(points) - 1


        while left < right:
            pivot_i = partition(left, right)

            if pivot_i == k:
                return points[:k]

            if pivot_i < k:
                left = pivot_i + 1
            else:
                right = pivot_i - 1


        return points[:k]
