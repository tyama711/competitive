def main():
    n, l = (int(s) for s in input().strip().split(' '))
    an = [int (s) for s in input().strip().split(' ')]
    for i in range(1, n):
        if an[i-1] + an[i] >= l:
            print('Possible')
            index = i
            break
    else:
        print('Impossible')
        return
    for i in range(1, index):
        print(i)
    for i in range(n-1, index, -1):
        print(i)
    print(index)

main()
