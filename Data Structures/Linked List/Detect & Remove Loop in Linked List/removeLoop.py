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

    def detectLoop(self):
        print "Checking for Loop: "
        slowptr = fastptr = self.head
        while slowptr and fastptr and fastptr.next:
            slowptr = slowptr.next
            fastptr = fastptr.next.next
            if slowptr == fastptr:
                self.removeLoop(slowptr)
                print "Loop Detected."
                return
        print "No Loop."

    def removeLoop(self, slowptr):
        ptr1 = ptr2 = slowptr
        count = 1
        while ptr1.next != ptr2:
            ptr1 = ptr1.next
            count += 1
        ptr1 = self.head
        ptr2 = self.head
        for i in range(count):
            ptr2 = ptr2.next
        while ptr1 != ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        ptr2 = ptr2.next
        while(ptr2.next != ptr1):
            ptr2 = ptr2.next
        ptr2.next = None
    def printList(self):
        temp = self.head
        print "Printing List: "
        while temp:
            print temp.value, " ",
            temp = temp.next

ll = LinkedList()
ll.addNode(10)
ll.addNode(4)
ll.addNode(15)
ll.addNode(20)
ll.addNode(4)
ll.head.next.next.next.next.next = ll.head.next.next
ll.detectLoop()
ll.printList()
