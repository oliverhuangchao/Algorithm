#design a iterator
#each time return k different elements
import random
class container:
	def __init__(self):
		self._data = list()

	def insert(self,number):
		self._data.append(number)


	def get(self, k):
		value = random.sample(self._data,k)
		return value

