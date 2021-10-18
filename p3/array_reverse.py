#Print all elems in reverse for array Minus the edge elems
#
#!/usr/bin/python3

from typing import List

class Solution:
    def reverseList(self, nums: List[int]) -> List[int]:
        #index = len(nums) - 1
        for i in range(len(nums) - 2, 0, -1):
            print(nums[i])
        return nums
        
        
A = Solution()
print(A.reverseList([4,2,6,9,11]))