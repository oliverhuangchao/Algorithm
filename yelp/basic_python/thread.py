import thread
import time


def func(threadname,delay):
	count = 0
	while count<5:
		time.sleep(delay)
		count += 1
		print  "%s: %s" %(threadname, time.ctime(time.time()))


try:
	thread.start_new_thread(func,("thread-1",1))
	thread.start_new_thread(func,("thread-2",2))
except:
	print "error to make thread"


while True:
	pass