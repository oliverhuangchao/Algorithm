# return next permutation

# 2153->2315->2351

def reorder(nums,start):
	right = nums[start:]
	right.sort()
	return nums[:start]+right
	#return res

def next(nums):
	i = len(nums)-1
	while i >= 0:
		j = i-1
		while j>=0:
			if nums[i] > nums[j]:
				nums[i],nums[j] = nums[j],nums[i]
				right = nums[j+1:]
				right.sort()
				nums[j+1:] = right
				return
			j -= 1
		i -= 1
	nums.reverse()


nums = [2,3,5,1]
print nums
next(nums)
print nums
for i in range(5):
	next(nums)
	print nums
