# load balancer first part
# given each sever a poblility
# return each sever randomly with that value
# (a,1)(b,1)(c,8), so each time return 'c' with properbility of 0.8

import random

def getit(values):
	a = random.uniform(0,1)
	#sum_value = sum(map(lambda x:x[1],values))
	each_value = map(lambda x:x[1],values)
	sum_value = sum(each_value)
	check = dict(values)
