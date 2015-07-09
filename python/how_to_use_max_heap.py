# how to sort with own sort algorithm
# default is accending order

import heapq

########## first part ############
# default heapq to build a min-heap
# x = list()
# heapq.heappush(x,1)
# heapq.heappush(x,3)
# heapq.heappush(x,2)

# print heapq.heappop(x)
# print heapq.heappop(x)
# print heapq.heappop(x)

########## second part ############
# self-define class for min-heap
x = list()
class myclass:
    def __init__(self,x,y):
        self._first = x
        self._second = y

    # < means max-heap
    def __cmp__(self,other):
       return -self._first + other._first

#heapq.heappush(x,myclass(1,10))
#heapq.heappush(x,myclass(3,9))
#heapq.heappush(x,myclass(2,8))

#print heapq.heappop(x)._second
#print heapq.heappop(x)._second
#print heapq.heappop(x)._second

########### third part ############
# for normal part of integer
# if we need to obtain a max_heap
# the best way for us is 



# list order
x.append(myclass(1,10))
x.append(myclass(3,9))
x.append(myclass(2,8))

def myfunc(x,y):
    return x-y

x.sort(lambda x,y:-x._first+y._first)
for i in x:
    print str(i._first) + " - " + str(i._second)