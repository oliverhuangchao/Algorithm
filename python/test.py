
def check(num,pre):
    if pre == []:
        return False
    z = dict()
    degree = list()
    for i in range(0,num):
        degree.append(0)
        z[i] = list()

    for i in pre:
        z[i[0]].append(i[1])
        degree[i[1]] += 1

    #print z

    for i in range(0,num):
        k = 0
        while k<num:
            if degree[k] == 0:
                break;
            k += 1
        #print k
        if k == num: 
            return False  
        #if degree[k] == 0:
        degree[k] = -1
        for it in z[k]:
            degree[it] -= 1

        print degree

    return True



if __name__ == "__main__":
    num = 2
    pre = list()
    #pre.append([1,0])
    pre.append([0,1])
    print pre
    print check(num,pre)