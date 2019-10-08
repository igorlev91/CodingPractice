class Node:
    def __init__(self, val):
        self.value = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def addNode(self, val):
        node = Node(val)
        node.next = self.head
        self.head = node

    def printList(self):
        temp = self.head
        print "Printing List: "
        while temp:
            print temp.value, " ",
            temp = temp.next

def sum(l1, l2):
    l = LinkedList()
    temp1 = l1.head
    temp2 = l2.head
    while temp1 and temp2:
        if temp1.value >= temp2.value:
            l.addNode(temp1.value)
            temp1 = temp1.next
        else:
            l.addNode(temp2.value)
            temp2 = temp2.next
    while temp1:
        l.addNode(temp1.value)
        temp1 = temp1.next
    while temp2:
        l.addNode(temp2.value)
        temp2 = temp2.next
    print "Sorted ",
    l.printList()

l1 = LinkedList()
l2 = LinkedList()
l1.addNode(5)
l1.addNode(10)
l1.addNode(15)
l2.addNode(2)
l2.addNode(3)
l2.addNode(20)
sum(l1, l2)
