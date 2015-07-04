# thread practice
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
        return self._second > other._second

heapq.heappush(x,myclass(1,10))
heapq.heappush(x,myclass(3,9))
heapq.heappush(x,myclass(2,8))

print heapq.heappop(x)._second
print heapq.heappop(x)._second
print heapq.heappop(x)._second

########### third part ############
# for normal part of integer
# if we need to obtain a max_heap
# the best way for us is 
