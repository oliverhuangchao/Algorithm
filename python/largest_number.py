# laregest number
import pdb
x = [100,12,10,1]
print x
x.sort(reverse=True,cmp = lambda a,b:str(a)+str(b)>str(b)+str(a))
print x
res = "".join(map(lambda x:str(x),x))
while res[0] == "0" and len(res)>1:
	res = res[1:]

print cmp("ab","bc")

