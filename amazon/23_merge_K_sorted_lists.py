'''
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.


Definition for singly-linked list.
class ListNode:
    def __init__(self, val= 0, next = None):
        self.val = val
        self.next = next
'''
#using heap
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]])->Optional[ListNode]:
        heap = []

        def push_node(heap, node):
            if node:
                heapq.heappush(heap, (node.val, id(node), node))
        
        for l in lists:
            push_node(heap,l)
        
        dummy = ListNode()
        current = dummy

        while heap: 
            _, _, node = heapq.heappop(heap)
            current.next = node
            current = current.next
            if node.next:
                heapq.heappush(heap, (node.next.val, id(node.next),node.next))

        return dummy.next

# Solution 2: Min-Heap (Priority Queue)
# Time: O(N log k), Space: O(k)

import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists):
        heap = []
        
        for i, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val, i, node))
        
        dummy = ListNode(0)
        curr = dummy
        
        while heap:
            val, i, node = heapq.heappop(heap)
            curr.next = node
            curr = curr.next
            
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))
        
        return dummy.next



# Solution 3: Divide and Conquer
# Time: O(N log k), Space: O(log k) recursion
class Solution:
    def mergeKLists(self, lists):
        if not lists:
            return None
        
        while len(lists) > 1:
            merged = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i + 1] if i + 1 < len(lists) else None
                merged.append(self.merge2Lists(l1, l2))
            lists = merged
        
        return lists[0]
    
    def merge2Lists(self, l1, l2):
        dummy = ListNode(0)
        curr = dummy
        
        while l1 and l2:
            if l1.val <= l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next
        
        curr.next = l1 if l1 else l2
        return dummy.next


'''
Comparison
Metric    Heap        Divide & Conquer
Time    O(N log k)    O(N log k)
Space    O(k)        O(log k)
Cache    Poor        Better
Code    Simpler    More intuitive
Bestfor Large k    Small k
