class Interval:
	def __init__(self,start,end):
		self.start = start
		self.end = end


def printx(intervals):
	x = map(lambda x:x.start,intervals)
	print x


x = [1]
y = [3]
z = zip(x,y)
#a = Interval(1,2);
#print a.start
intervals = map(lambda x:Interval(x[0],x[1]),z);
intervals.sort(key=lambda x:x.start);
res = list()
res.append(intervals[0])
start = intervals[0].start;
end = intervals[0].end;
for i in intervals[1:]:
	if i.start > end:
		tmp = Interval(start,end)
		res.append(tmp)
		start = i.start
		end = i.end
	else:
		end = max(end,i.end)
tmp = Interval(start,end)
res.append(tmp)
printx(res)

