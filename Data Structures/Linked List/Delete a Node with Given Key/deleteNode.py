class Node:
    def __init__(self, val = None):
        self.value = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def addNode(self, val):
        node = Node(val)
        node.next = self.head
        self.head = node

    def deleteNodeKey(self, key):
        print "Deleting ", key
        temp = self.head
        if temp is not None and temp.value == key:
            self.head = temp.next
            temp = None
            return
        while temp.next:
            if temp.next.value == key:
                prev = temp
                curr = temp.next
            temp = temp.next
        if temp == None:
            print "Key Not Found."
            return
        prev.next = curr.next
        curr = None


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
ll.addNode(5)
ll.printList()
ll.deleteNodeKey(7)
ll.printList()
