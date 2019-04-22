"""
A test of how a python iterator passes back items
"""

l = []
for i in range(8):
    l.append(i)

for num in l:
    num += 10
    print("num inside first iterator = " + str(num))

for num in l:
    print("num after first iterator = " + str(num))
