import random


def rand():
    return random.uniform(0, 1)


def foo(mydict):
    total = float(sum(mydict.values()))
    mylist = [(x, y / total) for (x, y) in mydict.items()]
    r = rand()
    i = 0
    while r > 0:
        r -= mylist[i][1]
        i += 1
    return mylist[i - 1][0]