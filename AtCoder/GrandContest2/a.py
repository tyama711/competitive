a, b = (int(s) for s in input().strip().split(' '))
if a <= 0 and 0 <= b:
    print('Zero')
elif 0 < a or (b-a)%2 == 1:
    print('Positive')
else:
    print('Negative')

