# reverse word in a string
# both iterative and recursive solution

# recursive solution goes here
def func(str):
	if len(str) == 0:
		return str
	a = 0
	while a < len(str) and  str[a] != " ":
		a += 1
 
	str = str[:a][::-1] + " " + func(str[a+1:])
	return str

str = "hello world chaoh"
str = str[::-1]
print str
str = func(str)
print(str)