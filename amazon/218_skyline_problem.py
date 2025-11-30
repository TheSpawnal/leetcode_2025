

'''
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where 
buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form 
[[x1,y1],[x2,y2],...]. 
Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, 
which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. 
Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. 
For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; 
the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

 

Example 1:
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.

Example 2:
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]
 
Constraints:
1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings is sorted by lefti in non-decreasing order.
'''


#divide and conque Time: O(n log n) | Space: O(n)
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        if not buildings:
            return []
        if len(buildings) == 1:
            left, right, height = buildings[0]
            return [[left, height], [right, 0]]
        
        mid = len(buildings) // 2
        left_skyline = self.getSkyline(buildings[:mid])
        right_skyline = self.getSkyline(buildings[mid:])
        
        return self.merge(left_skyline, right_skyline)
    
    def merge(self, left: List[List[int]], right: List[List[int]]) -> List[List[int]]:
        result = []
        i = j = 0
        h1 = h2 = 0
        
        while i < len(left) and j < len(right):
            if left[i][0] < right[j][0]:
                x, h1 = left[i]
                i += 1
            elif left[i][0] > right[j][0]:
                x, h2 = right[j]
                j += 1
            else:
                x = left[i][0]
                h1, h2 = left[i][1], right[j][1]
                i += 1
                j += 1
            
            max_h = max(h1, h2)
            if not result or result[-1][1] != max_h:
                result.append([x, max_h])
        
        result.extend(left[i:])
        result.extend(right[j:])
        
        return result

#Strategy 3: Segment Tree / Multiset (Balanced BST)
#Time: O(n log n) | Space: O(n)
from sortedcontainers import SortedList
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for left, right, height in buildings:
            events.append((left, 's', height))
            events.append((right, 'e', height))
        
        events.sort(key=lambda x: (x[0], x[1] == 's', -x[2] if x[1] == 's' else x[2]))
        
        result = []
        active_heights = SortedList([0])
        
        i = 0
        while i < len(events):
            curr_x = events[i][0]
            
            # Process all events at same x-coordinate
            while i < len(events) and events[i][0] == curr_x:
                x, typ, h = events[i]
                if typ == 's':
                    active_heights.add(h)
                else:
                    active_heights.remove(h)
                i += 1
            
            max_h = active_heights[-1]
            
            if not result or result[-1][1] != max_h:
                result.append([curr_x, max_h])
        
        return result


#wrong answer:
from heapq import heappush, heappop
from typing import List

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for left, right, height in buildings:
            events.append((left, -height, 0))  
            events.append((right, height, 1))   
        
        events.sort()
        
        result = []
        max_heap = [(0, float('inf'))]  # (negative_height, end_position)
        
        for x, h, typ in events:
            if typ == 0:  # building starts
                heappush(max_heap, (h, x))
            else:  # building ends at position x
                heappush(max_heap, (0, x))
            
            # Remove expired buildings
            while max_heap[0][1] <= x:
                heappop(max_heap)
            
            curr_max = -max_heap[0][0]
            
            if not result or result[-1][1] != curr_max:
                result.append([x, curr_max])
        
        return result


#correction of the heap:
from heapq import heappush, heappop
from typing import List

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for left, right, height in buildings:
            events.append((left, -height, right))   # start: store RIGHT edge
            events.append((right, 0, 0))            # end: trigger cleanup
        
        events.sort()
        
        result = []
        max_heap = [(0, float('inf'))]
        
        for x, neg_h, right_edge in events:
            if neg_h != 0:  # building starts
                heappush(max_heap, (neg_h, right_edge))
            
            # Remove buildings that ended at or before x
            while max_heap[0][1] <= x:
                heappop(max_heap)
            
            curr_max = -max_heap[0][0]
            
            if not result or result[-1][1] != curr_max:
                result.append([x, curr_max])
        
        return result

'''
### Key Fixes:
1. **Store right edge with start events**: `(left, -height, right)`
2. **Push to heap**: `(neg_h, right_edge)` not `(neg_h, x)`
3. **End events become cleanup triggers**: `(right, 0, 0)`

### Trace with Fix (first few events):
```
Event (2, -10, 9): Push (-10, 9), max=10, output [2, 10] ✓
Event (3, -15, 7): Push (-15, 7), max=15, output [3, 15] ✓
Event (5, -12, 12): Push (-12, 12), max=15 (no change)
Event (7, 0, 0): Cleanup, remove (-15, 7), max=12, output [7, 12] ✓
'''

