x = {"a":["p1","p2","p3"],"b":["p2","p4"],"c":["p1","p3"]}
print x
y = dict()

for i in x:
    for j in x[i]:
        #print j
        if j in y:
            y[j].append(i)
        else:
            y[j] = list()
            y[j].append(i)

for i in y:
    print i + str(y[i])