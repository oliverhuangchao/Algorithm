# reverse list

class listnode():
    def __init__(self,x):
        self._value = x
        self._next = None

def revereList(head):
    return rev(head,None)


def rev(head,newhead):
    if head is None:
        return newhead
    else:
        next = head._next
        head._next = newhead
        return rev(next,head)


def printlist(head):
    while head is not None:
        print head._value
        head = head._next


x = map(lambda x:listnode(x),range(5))
head = x[0]
start = head
for i in range(1,len(x)):
    x[i-1]._next = x[i]
    #i = head

printlist(head)
head = revereList(head)
printlist(head)