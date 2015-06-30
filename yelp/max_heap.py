import heapq
class Interval:
	def __init__(self,start,end):
		self.start = start
		self.end = end


def printx(intervals):
	x = map(lambda x:x[0],intervals)
	print x


class airplane_heap(object):
	def __init__(self,key=lambda x:x):
		self._data = []
		self.key = key

	def push(self,element):
		heapq.heappush(self._data,(self.key(element),element))

	def pop(self):
		return heapq.heappop(self._data)

	def top(self):
		return self._data[0]

	def size(self):
		return len(self._data)



x = [1,3]
y = [2,4]
z = zip(x,y)
#a = Interval(1,2);
#print a.start
intervals = map(lambda x:Interval(x[0],x[1]),z);
intervals.sort(key=lambda x:x.start);
z = airplane_heap(key = lambda x:x.end)
z.push(intervals[0])
z.push(intervals[1])
print(z.pop())
print(z.pop())

#res = len(z)
#for i in intervals[1:]:

