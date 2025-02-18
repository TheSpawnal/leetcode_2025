# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val= 0, next = None):
#         self.val = val
#         self.next = next

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
