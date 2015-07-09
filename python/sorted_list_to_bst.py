# sorted link list to bst


def sortedListToBST(self, head):
    current, length = head, 0
    # get length of list
    while current:
        current = current.next
        length += 1
    # use class variable to store head so that it can be modified by sortedListToBSTHelper
    self.node = head
    return self.sortedListToBSTHelper(0, length-1)

def sortedListToBSTHelper(self, start, end):
    if start > end:
        return None
    middle = (start + end) / 2
    left = self.sortedListToBSTHelper(start, middle-1)
    parent = TreeNode(self.node.val)
    parent.left = left
    self.node = self.node.next
    parent.right = self.sortedListToBSTHelper(middle+1, end)
    return parent
