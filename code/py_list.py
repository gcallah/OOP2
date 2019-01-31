"""
A test of how a python iterator passes back items
"""

l = [1, 2, 3, 5, 8, 13, 21]

for num in l:
    num += 1
    print("num inside first iterator = " + str(num))

for num in l:
    print("num after first iterator = " + str(num))
