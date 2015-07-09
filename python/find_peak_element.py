# find the peak element using log(N) time


def rec(nums,start,end):
    mid = (start+end)/2
    #print mid
    if (mid == start or nums[mid] > nums[mid-1]) and (mid == end or nums[mid] > nums[mid+1]):
        return mid
    if nums[mid-1] > nums[mid]:
        return rec(nums,start,mid-1)
    else:
        return rec(nums,mid+1,end)
    
def findPeak(nums):
    # write your code here
    return rec(nums,0,len(nums)-1)


x = [1,2,4,5,6,7,8,6]
print range(len(x))
print x
print findPeak(x)