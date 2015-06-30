def longestCommonPrefix(strs):
    # write your code here
    if len(strs) < 2:
        return len(strs)
    s = strs[0]
    res = 0
    for c in range(0,len(s)):
        for i in range(1,len(strs)):
            if len(strs[i]) <= c or strs[i][c] != s[c]:
                return s[:res]
        res += 1
    return s[:res]



strs = ["ABCD","ABEF","ACEF"]
print longestCommonPrefix(strs)