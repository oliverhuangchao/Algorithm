#design a data structure 
# insert, delete, get a random value in O(1) time
import random
class container:
	def __init__(self):
		self._data = list()
		self._check = dict()
		#self._size = 0

	def insert(self,number):
		self._data.append(number)
		self._check[number] = self._size
		#self._size += 1

	def delete(self):
		data = random.choice(self._data)
		index = self._check[data]
		#self._data[size-1],self._data[index] = self._data[index],self._data[size-1]
		self._data[-1],self._data[index] = self._data[index],self._data[-1]
		#del(self._data[size-1])
                del self._data[-1]
		#size -= 1
		del self._check[data]

	def get(self):
		return random.choice(self._data)



x = container()
for i in range (5):
	x.insert(i)
	print x.get()
