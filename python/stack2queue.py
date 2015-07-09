# construct a queue just using stack
# use two stack to achieve this goal
class myqueue:
	def __init__(self):
		self.first = list()
		self.second = list()

	def push(self, number):
		self.first.append(number)

	def pop(self):
		if not self.second:
			while self.first:
				self.second.append(self.first.pop())
		if self.second:
			return self.second.pop()
		else:
			print "empty queue"
			return -1



x = myqueue()
x.push(1)
x.push(2)
x.push(3)
print x.pop()
x.push(4)
x.push(5)
print x.pop()
print x.pop()
print x.pop()
print x.pop()
print x.pop()