# -*- coding: UTF-8 -*-


class Node:
    """Node struct for Linked list"""
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next

    def get_next(self):
        return self.next

    def get_val(self):
        return self.val

    def set_val(self, val):
        self.val = val

    def set_next(self, nxt):
        self.next = nxt

    def __str__(self):
        return str(self.val) + ' ' + str(self.next)


class LList:
    """simple Linked List"""
    def __init__(self):
        self.head = Node(-1)
        self.tail = self.head
        self.size = 0

    def head_insert(self, node):
        node.set_next(self.head.get_next())
        self.head.set_next(node)
        if self.head == self.tail:
            self.tail = node
        self.size += 1

    def tail_insert(self, node):
        self.tail.set_next(node)
        node.set_next(Node)
        self.size += 1

    def size(self):
        return self.size

    def is_empty(self):
        return not self.size

    def __str__(self):
        return str(self.head.get_next())


if __name__ == "__main__":
    a = Node(1)
    b = Node(2)
    c = Node(3)
    a.set_next(b)
    b.set_next(c)
    print (a)


    print ("LList testing")

    L = LList()
    print (L.is_empty())
    L.head_insert(a)
    print (L.is_empty())
    L.head_insert(b)
    L.tail_insert(c)
    print (L)
