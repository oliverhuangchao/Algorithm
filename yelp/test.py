# longest common subsequence
# longest common subsequence
# how to get the transform equation

def longestCommonSubstring(a, b):
    # write your code here
    # pay attention the order of a and b
    check = [[0 for i in range(len(b)+1)] for j in range(len(a)+1)]
    res = 0
    
    for i in range(1,len(a)+1):
        for j in range(1,len(b)+1):
            if a[i-1] == b[j-1]:
                check[i][j] = check[i-1][j-1] + 1
            else:
                check[i][j] = 0
            
            res = max(res,check[i][j])
    
    return res

def longestCommonSubsequence(a, b):
    # write your code here
    check = [[0 for i in range(len(b)+1)] for j in range(len(a)+1)]
    res = 0
    for i in range(1,len(a)+1):
        for j in range(1,len(b)+1):
            if a[i-1] == b[j-1]:
                check[i][j] = check[i-1][j-1] + 1
            else:
                check[i][j] = max(check[i-1][j],check[i][j-1])
            
            res = max(check[i][j], res)
    
    return res

a = ""
b = ""

print longestCommonSubstring(a,b)