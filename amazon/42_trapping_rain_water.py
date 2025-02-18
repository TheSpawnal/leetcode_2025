
#two pointers approach.
class Solution:
    def trap(self, height: List[int]) -> int:

        if len(height) <= 2:
            return 0

        ans = 0
        #using two pointers i and j on indices 1 and n - 1
        i = 1
        j = len(height)-1
        #intialising leftmax to the leftmost bar and rightmax to the rightmost bar
        left_max = height[0]
        right_max = height[-1]

        while i <= j:
            #check lmax and rmax for current i, j positions
            if height[i] > left_max:
                left_max = height[i]
            if height[j] > right_max:
                right_max = height[j]
            #fll water up to lmax level for index i and move i to the right
            if left_max <= right_max:
                ans += left_max - height[i]
                i += 1
#fill water up to rightmax level for index j and move j to the left
            else:
                ans += right_max - height[j]
                j -= 1

        return ans

            
