class ListNode:
	def __init__(self, key, value):
		self.key = key
		self.value = value
		self.prev = None
		self.tail = None


class LRUCache:
	def __init__(self,capacity):
		self.capacity = capacity
		self.size = 0
		self.check = dict()
		self.head = ListNode(0,0)
		self.tail = ListNode(0,0)
		self.head.next = self.tail
		self.tail.prev = self.head

	# get the value based on key
	def get(self,key):
		if self.check.has_key(key):
			tmp = self.check[key]
			self.detach(tmp)
			self.move_front(tmp)
			return tmp.value
		else:
			return -1
	# insert the {key, value} if not exist
	# or update the current pair
	def set(self,key,value):
		if self.check.has_key(key):
			tmp = self.check[key]
			tmp.value = value
			self.detach(tmp)
			self.move_front(tmp)
		else:
			if self.size == self.capacity:
				self.size -= 1
				tmp = self.tail.prev
				self.detach(tmp)
				del self.check[tmp.key]
			tmp = ListNode(key,value)
			self.move_front(tmp)
			self.check[key] = tmp
			self.size += 1

	def detach(self,node):
		node.next.prev = node.prev
		node.prev.next = node.next
		node.next = None
		node.prev = None

	def move_front(self,node):
		node.prev = self.head
		node.next = self.head.next
		self.head.next.prev = node
		self.head.next = node

