# use Queue.priority_queue
import Queue as q
import heapq

class mypq(q.PriorityQueue):
	def top(self):
		value = self.get()
		self.put(value)
		return value

class newclass:
	def __init__(self,number):
		self._value = number

	def __cmp__(self,other):
		return self._value < other._value



class job:
	def __init__(self,order,description):
		self._order = order
		self._description = description
		#print "new job is " + description

	# this is the function how to implement a priority queue
	# 
	def __cmp__(self,otherjob): 
		return self._order < otherjob._order


# basic int storage

x = q.PriorityQueue()
x.put(newclass(5))
x.put(newclass(3))
x.put(newclass(6))
print x.get()._value
print x.qsize()






#use Queue module
#x = q.PriorityQueue()
# x = mypq()
# x.put(job(1,"aaa"))
# x.put(job(3,"bbb"))
# x.put(job(2,"ccc"))
# print x.qsize()
# print x.top()._description
# x.get()
# print x.top()._description
# print x.qsize()


#use heapq module
# y = list()
# heapq.heappush(y,job(1,"aaa"))
# heapq.heappush(y,job(2,"bbb"))
# heapq.heappush(y,job(3,"ccc"))
# z = heapq.heappop(y)
# z = heapq.heappop(y)

# print z._description
# while not x.empty():
# 	tmp = x.get()
# 	print tmp._description + " - " + str(tmp._order)
