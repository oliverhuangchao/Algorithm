# achieve two number add with different base
# N should <= 10, then use str() is ok
# if N > 10:
# there should be a new function to achieve, or use hex()
# suppose len(a) >= len(b)


def transfer(tmp):
	if tmp < 10:
		return str(tmp)
	else:
		return list(hex(tmp))[2].upper()


def addTwo(a,b,N):
	if len(a) < len(b):
		return addTwo(b,a,N)
	list_x = list(a)
	list_x.reverse()
	list_y = list(b)
	list_y.reverse()
	flag = 0
	res = list()
	#size = len(list_y)
	for i in range(len(list_x)):
		if i < len(list_y):
			tmp  = int(list_x[i]) + int(list_y[i]) + flag
		else:
			tmp = int(list_x[i]) + flag
		if tmp >= N:
			flag = 1

		tmp %= N
		res.append(transfer(tmp))

	if flag == 1:
		res.append(transfer(flag))
	res.reverse()
	res = "".join(res)
	return res


a = "111"
b = "999"
N = 16
print a
print b
print addTwo(a,b,N)
