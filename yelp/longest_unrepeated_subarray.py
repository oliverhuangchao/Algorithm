def longest_unrepeated_subarry(s):
    a = 0
    max_length = 0
    start = 0
    check = dict()
    while a < len(s):
        if s[a] in check:
            max_length = max(max_length,a-start)
            start = max(check[s[a]]+1,start)
        check[s[a]] = a
        a += 1
    
    max_length = max(max_length,a-start)
    return max_length



s = "abcba"
print longest_unrepeated_subarry(s) 