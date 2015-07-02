# find k-th lowest element in an unsorted array
# partition + binary search


def partition(nums,start,end):
	pivot = nums[start]
	while start < end:
		while start < end and nums[end] > pivot:
			end -= 1
		nums[start] = nums[end]
		while start < end and nums[start] <= pivot:
			start += 1
		nums[end] = nums[start]
	nums[start] = pivot
	return start

def k_th_lowest(nums,k,start,end):
	#if start == k:
	#	return nums[k]
	mid = partition(nums,start,end)
	#print mid
	if mid == k:
		return nums[k]
	if mid > k:
		return k_th_lowest(nums,k,start,mid-1)
	else:
		return k_th_lowest(nums,k,mid+1,end)
	



x = [3,1,5,2,4,6]
print x
#print partition(x,0,len(x)-1)
for i in range(len(x)):
	print k_th_lowest(x,i,0,len(x)-1)