import collections
def majorityNumber(nums):
    # write your code here
    c = nums[0]
    t = 0
    for n in nums:
        if t == 0:
            c = n
            t += 1
        else:
            if n == c:
                t += 1
            else:
                t -= 1
        #print t
    return c


def majority_TwoNumber(nums):
    ctr = collections.Counter()
    print ctr
    for n in nums:
        ctr[n] += 1
        #print ctr
        if len(ctr) == 3:
            ctr -= collections.Counter(set(ctr))
    res = [n for n in ctr if nums.count(n) > len(nums)/3]
    return res



nums = [1,2,3,1,1,2,2]
print majority_TwoNumber(nums)