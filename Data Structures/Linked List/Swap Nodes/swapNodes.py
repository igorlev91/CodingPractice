class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def printNode(self):
        print
        print "Printing Linked List: "
        temp = self.head
        while temp:
            print temp.data, " ",
            temp = temp.next

    def addNode(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def swapNode(self, x, y):
        print
        print "Swapping: "+str(x)+" & "+str(y)
        temp = self.head
        while temp.next:
            if temp.next.data == x:
                p1 = temp
                n1 = temp.next
            if temp.next.data == y:
                p2 = temp
                n2 = temp.next
            temp = temp.next
        p1.next = n2
        p2.next = n1
        n1.next, n2.next = n2.next, n1.next

ll = LinkedList()
ll.addNode(10)
ll.addNode(15)
ll.addNode(12)
ll.addNode(13)
ll.addNode(20)
ll.addNode(14)
ll.printNode()
ll.swapNode(12, 20)
ll.printNode()
