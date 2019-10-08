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

    def findNode(self, n):
        print "Finding "+str(n)+"th Node from the end."
        temp1 = temp2 = self.head
        i = 0
        while i < n:
            if not temp2:
                print "n is smaller than List Size."
                return
            i += 1
            temp2 = temp2.next
        while temp2:
            temp1 = temp1.next
            temp2 = temp2.next
        print temp1.value

    def printList(self):
        temp = self.head
        print "Printing List: "
        while temp:
            print temp.value, " ",
            temp = temp.next

ll = LinkedList()
ll.addNode(20)
ll.addNode(4)
ll.addNode(15)
ll.addNode(35)
ll.findNode(3)
