def solve(string):
    z, o = 0, 0
    for c in string:
        if c == '0':
            z+=1
        else:
            o+=1

    if z == 1 or o == 1:
        return "Yes"
    else:
        return "No"

if __name__ == "__main__":
    T = int(input())

    for t in range(0,T):
        D = input()
        print(solve(D))
