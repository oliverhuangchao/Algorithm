def simplifyPath(self, path):
    # Write your code here
    z = path.split('/')
    while(z.count('')):
        z.remove(''); # remove the '//'
    while(z.count('.')):
        z.remove('.');# remove '.'
    #print z
    
    stack = list();
    
    while len(z):
    	tmp = z[0]
    	del z[0]
    	if tmp == "..":
    	    if len(stack):
    		    stack.pop()
    	else:
    		stack.append(tmp)
    
    res = "/" 
    stack.reverse()
    while(len(stack)):
    	res += stack.pop()
    	if len(stack):
    	    res += "/"

    return res