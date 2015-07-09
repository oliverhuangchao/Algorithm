class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# @param {integer[]} inorder
# @param {integer[]} postorder
# @return {TreeNode}
def buildTree(self, preorder, inorder):
    if not preorder or not inorder:
        return None
    rootvalue = preorder[0]
    index = inorder.index(rootvalue)
    del preorder[0]
    root = TreeNode(rootvalue)
    #left order should go first
    root.left = self.buildTree(preorder, inorder[:index])
    root.right = self.buildTree(preorder,inorder[index+1:])
    return root


inorder = []
postorder = []
#print inorder.index(1)
root = buildTree(inorder,postorder)
