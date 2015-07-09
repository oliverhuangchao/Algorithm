import sys
class min_stack:
	def __init__(self):
		#self.minvalue = -1*sys.maxint-1
		self.data = list()
		self.min_data = list()

	def push(self,number):
		if len(self.data) == 0:
			self.min_data.append(number)
		else:
			self.min_data.append(min(number,self.min_data[len(self.data)-1]))

		self.data.append(number)

	def pop(self):
		self.min_data.pop()
		return self.data.pop()

	def getmin(self):
		return self.min_data[len(self.min_data)-1]



min_stack x()
x.push(1)
x.pop()
x.push(2)
