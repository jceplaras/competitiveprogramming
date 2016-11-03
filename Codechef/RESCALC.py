

if __name__ == "__main__":
    TC = int(input())

    for t in range(0,TC):
        N = int(input())
        max_score = -1
        tie = False
        win = 0

        for n in range(0,N):
            T = [0] * 6
            C = list(map(int, input().split()))

            for c in range(1,len(C)):
                T[C[c]-1]+=1

            T.sort()

            score = C[0]
            score += T[0]*4
            T[1] -= T[0];
            T[2] -= T[0];
            score += T[1]*2
            T[2] -= T[1];
            score += T[2];

            #print(T)
            #print(score)

            if score > max_score:
                tie = False
                max_score = score
                win = n
            elif score == max_score:
                tie = True
                max_score = score
                win = n

        if tie:
            print("tie")
        elif win == 0:
            print("chef")
        else:
            print(win+1)

