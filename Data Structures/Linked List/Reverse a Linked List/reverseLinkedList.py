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

    def reverseList(self):
        print "Reversing: "
        if self.head.next == None:
            return
        cur = self.head
        pre = None
        while cur:
            nex = cur.next
            cur.next = pre
            pre = cur
            cur = nex
        self.head = pre

    def printList(self):
        temp = self.head
        print "Printing List: "
        while temp:
            print temp.value, " ",
            temp = temp.next

ll = LinkedList()
ll.addNode(7)
ll.addNode(1)
ll.addNode(3)
ll.addNode(2)
ll.addNode(8)
ll.printList()
ll.reverseList()
ll.printList()
