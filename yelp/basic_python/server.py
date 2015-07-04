import socket
s = socket.socket()
host = socket.gethostname()
port = 12345
s.bind((host,port))
s.listen(5)
while True:
	c,addr = s.accept()
	print "get connection from ", addr
	c.send("thanks for your connecting")
	c.close()