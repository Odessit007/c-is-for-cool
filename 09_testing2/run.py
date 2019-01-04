SYMS = 'xa!7$'

with open('x.txt', 'w') as f:
    for s in SYMS:
        for t in SYMS:
            a = 5*s
            b = 5*t
            print('{} {}'.format(a, b), file = f)

with open('y.txt', 'w') as f:
    print('xxxxx', file=f)
