# find the balance point in an array
# balance point: sum on the left = sum on the right
def find_balance(nums):
    left = list()
    right = list()
    size = len(nums)
    left.append(nums[0])
    for i in range(1,size):
        left.append(nums[i] + left[i-1])
    print left
    right.append(nums[size-1])
    for i in range(1,size):
        right.append(nums[size-1-i] + right[i-1])
    right.reverse()
    print right

    #res = zip(left,right)
    res = map(lambda x:x[0]-x[1],zip(left,right))
    print res.index(0)


x = [3,2,1,5,3,2,1]

find_balance(x)