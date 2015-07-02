class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# @param {integer[]} inorder
# @param {integer[]} postorder
# @return {TreeNode}
def buildTree(inorder, postorder):
    if not inorder or not postorder:
        return None

    root = TreeNode(postorder.pop())
    inorderIndex = inorder.index(root.val)
    
    #right branch goes first will be ok
    root.right = self.buildTree(inorder[inorderIndex+1:], postorder)
    root.left = self.buildTree(inorder[:inorderIndex], postorder)

    return root


inorder = []
postorder = []
#print inorder.index(1)
root = buildTree(inorder,postorder)
