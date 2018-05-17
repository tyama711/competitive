class Box:
    def __init__(self, num=1, mayred=False):
        self.num = num
        self.mayred = mayred

n, m = (int(s) for s in input().strip().split(' '))
boxes = [Box() for _ in range(n)]
boxes[0].mayred = True
for _ in range(m):
    x, y = (int(s) for s in input().strip().split(' '))
    boxes[x-1].num -= 1
    boxes[y-1].num += 1
    if boxes[x-1].mayred == True:
        boxes[y-1].mayred = True
        if boxes[x-1].num == 0:
            boxes[x-1].mayred = False
print(len(list(filter(lambda b: b.mayred, boxes))))
