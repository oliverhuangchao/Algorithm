# possible password
# dfs problem
# Given an input N that tells you also how many digits are in the password, print all possible passwords

import string
import pdb
def possblePassword(N):
	result = list()
	path = list()
	abc = list(string.ascii_lowercase)
	dfs(0,N,result,path,abc,0)
	print result
	print len(result)

# recursive dfs solution
def dfs(step,N,result,path,abc,pos):
	if step == N:
		result.append("".join(path))
	else:
		for i in range(pos,26):
			path.append(abc[i])
			dfs(step+1,N,result,path,abc,i+1)
			path.pop()
			path.append(abc[i].upper())
			dfs(step+1,N,result,path,abc,i+1)
			path.pop()
	return


possblePassword(2)
