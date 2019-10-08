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

    def deleteNode(self, pos):
        count = 0
        if pos == count:
            self.head = None
        temp = self.head
        while temp:
            if count+1 == pos:
                prev = temp
                curr = temp.next
                break
            count += 1
        if prev:
            print
            print "Deleting."
            prev.next = curr.next
            curr = None
        else:
            print "Element not Found."


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
ll.deleteNode(1)
ll.printList()
