def solve(string):
    s = list(string)
    l = len(s)
    l = l//2 + l%2

    for i in range(0,l):
        x,y = s[i],s[-1-i]
        if x == '.' and y != '.':
            s[i] = y
        elif x != '.' and y == '.':
            s[-1-i] = x
        elif x == '.' and y == '.':
            s[i] = s[-1-i] = 'a'
        elif x != y:
            return -1

    return ''.join(s)


if __name__ == "__main__":
    T = int(input())

    for t in range(0,T):
        D = input()
        print(solve(D))
