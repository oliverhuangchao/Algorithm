# sprial matrix leetcode

# print matrix in 2D direction

def printMatrix(matrix):
	for row in matrix:
		print row

# transform a matrix to its sprial order
def Matrix2Array(matrix):
	res = []
	while matrix:
		res += matrix[0]
		del matrix[0]
		while matrix and matrix[0]:
			for row in matrix:
				res.append(row.pop())
		if matrix:
			res += matrix.pop()[::-1]
		while matrix and matrix[0]:
			for row in matrix[::-1]:
				res.append(row[0])
				del row[0]
				# equal to res.append(row.pop(0))
	return res


def Array2Matrix(k):
	if k == 0:
		return []
	res = [[0 for i in range(k)] for j in range(k)]
	up, down, left, right = 0, k-1,0,k-1
	count, direction = 0, 0
	while True:
		if direction == 0:
			for i in range(left,right+1):
				count += 1
				res[up][i] = count
			up += 1
		if direction == 1:
			for i in range(up,down+1):
				count += 1
				res[i][right] = count
			right -= 1
		if direction == 2:
			for i in range(right,left-1,-1):
				count += 1
				res[down][i] = count
			down -= 1
		if direction == 3:
			for i in range(down,up-1,-1):
				count += 1
				res[i][left] = count
			left += 1
		if count == k**2:
			return res
		direction = (direction+1) % 4



# for the Matrix2Array part function
print("----------- Matrix -> Array ---------")
x = [[1,2,3],[4,5,6],[7,8,9]]
printMatrix(x)
print Matrix2Array(x)

# for the Array2Matrix part
print("----------- Array -> Matrix ---------")
printMatrix(Array2Matrix(3))