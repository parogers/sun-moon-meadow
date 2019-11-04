#!/usr/bin/env python3

points = (
    (0, 0),
    (10, 1),
    (20, 0.5),
    (30, 0),
    (30, 0.25),
    (40, 1),
    (50, 0),
)

def find_index(x):
    # Wrap around the point list
    last_x = points[-1][0]
    base_x = (x // last_x) * last_x
    x %= last_x

    # Find the next interpoltation point
    n = next(
        n for n in range(len(points))
        if points[n][0] <= x and points[n+1][0] >= x
    )
    return n, base_x

def calc_pt(x):
    n, base_x = find_index(x)

    x1, y1 = points[n]
    x2, y2 = points[n+1]
    x1 += base_x
    x2 += base_x

    dx = x2 - x1
    dy = y2 - y1

    p = (x - x1) / dx
    return x1 + p*p*dx, y1 + p*dy

for x in range(75):
    pt = calc_pt(x)
    print(pt[0], pt[1])

