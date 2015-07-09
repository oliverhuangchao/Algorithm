# find duplicate subarray give two 2D array list

# transform a list to a string with '-'
def list2string(x):
	y = map(lambda x:str(x),x)
	return '-'.join(y)

def string2list(x):
	res = list()
	for i in x:
		a = i.split("-") # something wrong with it
		b = map(lambda x:int(x),a)
		res.append(b)
	return res


def find_duplicate(a,b):
	x_a = map(lambda x:list2string(x),a)
	x_b = map(lambda x:list2string(x),b)
	check = set(x_a)
	res = list()
	for i in x_b:
		if i in check:
			res.append(i)

	return res

a = [[1,2,3],[4,5,6]]
b = [[3,2,1],[1,2,3]]


res = find_duplicate(a,b)
print res
z = string2list(res)
print z

