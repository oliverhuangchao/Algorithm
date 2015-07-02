# tre implementation

class node:
    def __init__(self):
        self._data = dict()
        self._exist = False


class trie:
    def __init__(self):
        self._root = node()
        #print "construct a new trie"

    def insert(self,str):
        if not str:
            return 
        tmp = self._root
        for x in range(len(str)):
            value = str[x]
            if value not in tmp._data:
                newnode = node()
                tmp._data[value] = newnode
            if x != len(str)-1:    
                tmp = tmp._data[value]

        tmp._data[value]._exist = True


    def search(self,str):
        if not str:
            return True
        tmp = self._root
        for i in range(len(str)):
            value = str[i]
            if value not in tmp._data:
                return False
            if i != len(str)-1:    
                tmp = tmp._data[value]

        return tmp._data[value]._exist



x = trie()
x.insert("huang")
x.insert("chaoh")
print x.search("a")




