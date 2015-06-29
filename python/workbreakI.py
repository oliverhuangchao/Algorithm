# @param s, a string
# @param wordDict, a set<string>
# @return a boolean
def wordBreak(s, wordDict):
	size = len(s)
	z = [True for x in range(size+1)]
	for i in range(1,size+1):
		for j in range(0,i):
			z[i] = z[j] and (s[j:i] in wordDict)
			if z[i]:
				break;

	print z
	return z[size]


s = "abcd"
print s
wordDict = ["a","abc","b","cd"]
print wordDict
print wordBreak(s,wordDict)