#!/usr/bin/env python

from operator import itemgetter
import sys

current_word = None
current_count = 0
word = None

# input comes from STDIN
for line in sys.stdin:
    # remove leading and trailing whitespace
    line = line.strip()

    # parse the input we got from mapper.py
    # x is uesless or we can use x as the total number of samples in each machine
    together, count = line.split('\t', 1)

    together = float(together)
    count = float(count)

    print "PI is aproximate to: "+ str(count/together*4) 




    # convert count (currently a string) to int
#     try:
#         count = int(count)
#     except ValueError:
#         # count was not a number, so silently
#         # ignore/discard this line
#         continue

#     # this IF-switch only works because Hadoop sorts map output
#     # by key (here: word) before it is passed to the reducer
#     if current_word == word:
#         current_count += count
#     else:
#         if current_word:
#             # write result to STDOUT
#             print '%s\t%s' % (current_word, current_count)
#         current_count = count
#         current_word = word

# # do not forget to output the last word if needed!
# if current_word == word:
#     print '%s\t%s' % (current_word, current_count)