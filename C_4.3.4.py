#!/usr/bin/env python
# -*- coding: utf-8 -*-
import random


def result3(jug3):
    jugs = []
    for k in jug3:
        jugs.append(jug3[k])
    # print(jugs)
    f1, f2, f3 = jugs
    if f1:
        return True
    elif f2:
        return True
    elif f3:
        return True
    else:
        return False


def result4(jug: dict):
    jugs = []
    for k in jug:
        jugs.append(jug[k])
    f1, f2, f3, f4 = jugs
    # print(jugs)
    if f1:
        return True
    elif f2:
        return True
    elif f3:
        return True
    elif f4:
        return True
    else:
        return False


def main():
    flag = {
        'f2': 0,
        'f3': 0,
        'f4': 0
    }
    for i in range(10000):
        x = random.randint(-500, 500)
        y = random.randint(-500, 500)
        z = random.randint(-500, 500)
        # print(x, y, z)
        jug = dict(
            f1=(x < 3) & (y > 3),
            f2=(x >= 3) & (y >= 3),
            f3=(z > 3) & (x >= 3),
            f4=(z <= 3) & (y >= 3),
        )
        test_jugs = ['f2', 'f3', 'f4']
        # print(jug)
        result = result4(jug)
        # print(result)
        for i in test_jugs:
            jug3 = jug.copy()
            jug3.pop(i)
            # print(result3(jug3))
            if result3(jug3) != result:
                flag[i] += 1
                if i == 'f4':
                    print('result:', result)
                    print(x, y, z, jug)
    print(flag)


if __name__ == "__main__":
    main()
