nums = [-7, 1, 5, 2, -4, 3, 0]
left = list()
left.append(nums[0])
for i in range(1,len(nums)):
	left.append(left[i-1]+nums[i])
#left = map(lambda x:left[len(left)-1]+x,nums)
right = list()
right.append(nums[len(nums)-1])
for i in range(1,len(nums)):
	right.append(right[i-1]+nums[len(nums)-i-1])
right.reverse()
print left
print right

# return left + right
res = list(map(lambda x: x[0]-x[1],zip(left,right)))
print res.index(0)
