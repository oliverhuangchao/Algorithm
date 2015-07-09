# check whether a number is a colorful number or not
# suppose input is a string

# return product in nums from position i to j
def getProduct(nums,i,j):
	z = map(lambda x:int(x),list(nums))
	return reduce(lambda x,y:x*y,z)


# maybe a dp solution
# each time, add a new digit and make a product this new digit with all the elements in check hashtable
def dp(nums):
	if not nums:
		return True
	nums = map(lambda x:int(x),list(str(nums)))
	check = set()
	newadd = list()
	check.add(nums[0])
	for each in nums[1:]:
		if each in check:
			return False
		else:
			check.add(each)
			newadd = list(check)
			for i in range(len(newadd)):
				if newadd[i]*each in check:
					return False
				else:
					check.add(newadd[i]*each)
	return True


nums = 23
print dp(nums)




