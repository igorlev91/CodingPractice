class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def addNode(self, val):
        new_node = Node(val)
        new_node.next = self.head
        self.head = new_node

    def printNodes(self):
        temp = self.head
        while temp:
            print temp.data, " ",
            temp = temp.next

def findIntersection(l1, l2):
    temp = l1.head
    h = {}
    while temp:
        h[temp.data] = 1
        temp = temp.next
    temp = l2.head
    while temp:
        if temp.data in h.keys():
            print "Intersection Point: ", temp.data
            return
        temp = temp.next
    print "No Intersection Found."

l1 = LinkedList()
l2 = LinkedList()
l1.addNode(30)
l1.addNode(15)
l1.addNode(9)
l1.addNode(6)
l1.addNode(3)
l2.addNode(10)
l2.head.next = l1.head.next.next.next
findIntersection(l1, l2)
