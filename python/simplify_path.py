def simply(path):
	z = path.split("/")
	while z.count(""):
		z.remove("")
	while z.count("."):
		z.remove(".")
	stack = list()
	for i in z:
		if i == "..":
			stack.pop()
		else:
			stack.append(i)
	res = "/"
	for i in stack:
		res += i
		res += "/"
	if len(res) > 1:
		return res[:len(res)-1]
	else:
		return res


path = ""
print simply(path)

