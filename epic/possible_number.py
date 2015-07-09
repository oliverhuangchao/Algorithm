#Desirable Number 
#A number is called 'desirable' if all the digits are strictly ascending eg: 159 as 1<5<9. You know that your rivalhas a strictly numeric password that is 'desirable'. Your close ally has given you the number of digits (N) in your rival's password. Takes in'N' as input and prints out all possible 'desirable' numbers that can be formed with N digits. 


# suppose that there will no duplicate number in the string

# dfs solution
def possible_number(N):
	nums = range(10)
	result = list()
	path = list()
	dfs(nums,0,0,N,result,path)
	print result


def dfs(nums,pos,step,N,result,path):
	if step == N:
		result.append(int("".join(map(lambda a:str(a),path))))
	else:
		for i in range(pos,10):
			path.append(i)
			# if is i+1, then there will be no duplicate
			# else if is i then there will be duplicate number
			dfs(nums,i+1,step+1,N,result,path)
			path.pop()

	return

possible_number(3)
