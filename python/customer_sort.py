# different sort using python sort function

class myclass:
    def __init__(self,x,y):
        self._first = x
        self._second = y

    def __cmp__(self,other):
        return -1*(self._first+self._second) + (other._first + other._second)


def func(a,b):
    return b-a



x = [3,1,2,5,4]
#x =  [myclass(1,5),myclass(3,4)]
print x
#x.sort(func)
x.sort(cmp)
#x.sort(lambda x,y:x._first+x._second > y._first + y._second)
print x


# more complicated condition
