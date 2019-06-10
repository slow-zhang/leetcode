from __future__ import print_function


class MyArray:
    """one simple array classs"""
    val = 8

    def __init__(self):
        self.__array = []

    def get_thing_len(self):
        return len(self.__array)

    @staticmethod
    def capacity():
        return 0x7fffffff

    def is_empty(self):
        return not self.__array

    def push(self, val):
        self.__array.append(val)

    def at(self, idx):
        if idx < 0 or idx > self.get_thing_len():
            return False
        else:
            return self.__array[idx]

    def insert(self, idx, val):
        if idx < 0 or idx > self.get_thing_len():
            return False
        else:
            self.__array.insert(idx, val)

    @classmethod
    def show_val(cls):
        print("val\n")
        print(cls.val)


print(MyArray.__doc__)
print (MyArray.show_val())

a = MyArray()
print (a.show_val())

print(a.get_thing_len())
print(a.is_empty())
a.push(11)
a.push(12)
print(a.at(1))
a.insert(1, 9)
print(a.at(1))

num = [1, 3, 2]

print(num)

print(3*1 + 2*2)


def cv(count=3):
    print(count)


cv(1)
