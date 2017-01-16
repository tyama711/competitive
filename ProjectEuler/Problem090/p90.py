import itertools as it

count = 0
for dice1 in it.combinations(range(0,10),6):
    s_dice1 = set(dice1)
    if 6 in s_dice1:
        s_dice1.add(9)
    elif 9 in s_dice1:
        s_dice1.add(6)
    for dice2 in it.combinations(range(0,10),6):
        s_dice2 = set(dice2)
        if 6 in s_dice2:
            s_dice2.add(9)
        elif 9 in s_dice2:
            s_dice2.add(6)

        if not {0,1,2,3,4,5,6,8,9}.issubset(s_dice1.union(s_dice2)):
            continue

        a_set = set(map(lambda a:a[0]*10 + a[1], it.product(s_dice1,s_dice2))) \
            .union(set(map(lambda a:a[0]*10 + a[1], it.product(s_dice2,s_dice1))))

        if set(map(lambda a:a*a, range(1,10))).issubset(a_set):
            count += 1

print(count // 2)
