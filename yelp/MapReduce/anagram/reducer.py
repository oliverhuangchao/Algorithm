# anagram Mapreduce edition

# we can use print edition
# or we can juse list edition


import sys

current_word = None
current_count = 0
res = list()
for line in sys.stdin:
	line = line.strip()
	word,number = line.split('\t',1)
	#print number
	try:
		number = int(number)
	except:
		continue
	if current_word == word:
		# mapbe the mapper has already do the local sort and group
		current_count += number
	else:
		if current_word:
			#res[current_word] = current_count
			res.append((current_word,current_count))
			#print str(current_count) + "\t" + current_word

		current_word = word
		current_count = number

if current_word:
	#res[current_word] = current_count
	res.append((current_word,current_count))
	#print  str(current_count) + "\t" +  current_word
res.sort(key = lambda x:x[1])
res.reverse()
print res