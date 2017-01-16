
def solve(data):
    cands = [[set(range(1,10)) for _ in range(1,10)] for _ in range(1,10)]
    solved = False
    may_solve = True
    while (not solved) and may_solve:
        # for i in range(0,3):
        #     for j in range(0,3):
        #         print(cands[i][j])
        for i in range(0,9):
            for j in range(0,9):
                if data[i][j] != 0:
                    for k in range(0,9):
                        cands[i][k].discard(data[i][j])
                        cands[k][j].discard(data[i][j])
                        cands[3*(i//3) + k//3][3*(j//3) + k%3].discard(data[i][j])
                    cands[i][j] = {data[i][j]}

        for i in range(0,9):
            for j in range(0,9):
                if len(cands[i][j]) == 1:
                    data[i][j] = list(cands[i][j])[0]

        for i in range(1,10):
            for j in range(0,9):
                count_a = 0
                count_b = 0
                count_c = 0
                for k in range(0,9):
                    if i in cands[j][k]:
                        count_a += 1
                        index_a = k
                    if i in cands[k][j]:
                        count_b += 1
                        index_b = k
                    if i in cands[3*(j//3) + k//3][3*(j%3) + k%3]:
                        count_c += 1
                        index_c = k
                        # if i == 4 and j == 0:
                        #     print(str(count_c) + ',' + str(index_c))
                if count_a == 1:
                    data[j][index_a] = i
                    cands[j][index_a] = {data[j][index_a]}
                if count_b == 1:
                    data[index_b][j] = i
                    cands[index_b][j] = {data[index_b][j]}
                if count_c == 1:
                    data[3*(j//3) + index_c//3][3*(j%3) + index_c%3] = i
                    cands[3*(j//3) + index_c//3][3*(j%3) + index_c%3] = {data[3*(j//3) + index_c//3][3*(j%3) + index_c%3]}

        # for i in range(0,9):
        #     print(data[i])
        # print('')
        solved = True
        for i in range(0,9):
            for j in range(0,9):
                if data[i][j] == 0:
                    solved = False
    if solved:
        return data
    return []

for j in range(1,51):
    print(j)
    s = input()
    data = []
    for i in range(0,9):
        s = input()
        data.append(list(map(int, s)))
    ans = solve(data)
    for i in range(0,9):
        print(data[i])
    print('')
