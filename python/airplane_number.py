# air plane schedule
# find the largest number of airplanes in the sky

import pdb
import heapq
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
    def __cmp__(self,other):
    	return self.end-other.end

def printdetail(nums):
	for i in nums:
		print str(i.start) + "-" + str(i.end)


def countOfAirplanes(airplanes):
    # write your code here
    #pdb.set_trace()
    airplanes.sort(cmp = lambda x,y:x.start-y.start)
    z = list() #use z as a stack
    res = 0
    for i in airplanes:
        while z and i.start >= z[0].end:
            heapq.heappop(z)
        heapq.heappush(z,i)
        res = max(res,len(z))
    return res


a = [[1,10],[2,3],[5,8],[4,7]]
#a = [[10,14],[10,15],[10,16],[1,10],[2,10],[3,10],[4,10]]
#a = [[52,61],[54,59],[34,35],[28,37],[94,97],[96,100],[76,85],[77,87],[77,87],[21,24],[9,15],[45,55],[99,103],[58,66],[35,43],[23,27],[40,49],[45,49],[13,19],[37,42],[31,32],[5,11],[83,89],[90,97],[36,41],[90,97],[91,98],[98,101],[93,102],[80,85],[60,62],[72,79],[85,87],[77,86],[93,103],[64,74],[62,69],[77,78],[71,74],[47,53],[21,29],[43,50],[30,34],[68,75],[53,61],[3,10],[8,9],[14,21],[32,40],[10,15],[91,96],[6,11],[16,23],[27,31],[51,58],[73,74],[98,106],[51,58],[10,17],[24,34]]
airplanes = map(lambda x:Interval(x[0],x[1]),a)
print countOfAirplanes(airplanes)