#merge two unsorted array into a sorted array recursively
# like a merge sort

def func(list_a):
	size = len(list_a)
	if size == 1:
		return list_a
	if size == 2:
		if list_a[0]>list_a[1]:
			list_a.reverse()
			return list_a
		else:
			return list_a
	first = func(list_a[:size/2])
	second = func(list_a[size/2:])
	return merge_sorted(first,second)


def merge_sorted(list_a,list_b):
	res = list()
	while list_a and list_b:
		if list_a[0] <= list_b[0]:
			res.append(list_a[0])
			del list_a[0]
		else:
			res.append(list_b[0])
			del list_b[0]
	res.extend(list_a)
	res.extend(list_b)
	return res

def merge(list_a,list_b):
	return merge_sorted(func(list_a),func(list_b))

x = [3,1,5,9,7]
y = [6,2,4,10,8]
print merge(x,y)

