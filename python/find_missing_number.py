# find the missing number
# N = 3
# nums = [0,1,3]
# so we should return 2 for this array



def swap(nums,i):
	tmp = nums[i]
	nums[i] = nums[tmp]
	nums[tmp] = tmp

def findmissing(nums):
	size = len(nums)
	nums.append(-1)
	i = 0
	# better use while loop to control i
	while i<= size:
		if nums[i] == i or nums[i] == -1:
			i += 1
			continue
		else:
			swap(nums,i)# swap but do not move i forward
#			print nums

	for i in range(size):
		if nums[i] == -1:
			return i
	return -1


nums = [0,1,2,3,5,6,7]
print findmissing(nums)