# trap rain water problem
# coding=utf-8
import pdb

# @param heights: a list of integers
# @return: a integer
def trapRainWater(heights):
    #对于任何一个坐标，检查其左右的最大坐标，然后相减就是容积
    size = len(heights)
    left = [heights[0] for i in range(size)]
    right = [heights[-1] for i in range(size)]
    max_value = 0
    for i in range(size):
        max_value = max(max_value,heights[i])
        left[i] = max_value
    max_value = heights[-1]
    for i in range(2,size+1):
        max_value = max(max_value,heights[size-i])
        right[size-i] = max_value
    res = 0
    for i in range(size):
        res += min(left[i],right[i])-heights[i]

    print heights
    print left
    print right
    return res

heights = [0,1,0,2,1,0,1,3,2,1,2,1]
print trapRainWater(heights)