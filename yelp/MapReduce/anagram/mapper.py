# anagram mapreduce program
# 
import sys

for line in sys.stdin:
	line = line.strip()
	words = line.split(" ")
	for word in words:
		word = "".join(sorted(word))
		print word + '\t' + str(1)
