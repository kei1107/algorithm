'''
< url: https: // yukicoder.me / problems / no / 62 >
問題文 == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
2人の魔法少女MamiとHomuraは幅Wメートル、奥行きHメートルの密室で銃撃戦を繰り広げていた。

Homuraは時間を止め、同時に最後の一発を発射した。
時間停止した世界ではHomuraと弾丸しか動くことができず、
弾丸は壁にあたると入射角と同じ角度で反射し速度を落とすことなく無限に飛び続ける。

Mamiがいる位置を(Mx, My)、Homuraが発砲した位置を(Hx, Hy)、
弾丸の発射時の速度ベクトルを(Vx, Vy)
としD秒間時間を止めるとき、D秒以内に弾丸がMamiに当たることはあるか判定せよ。

ただしMamiと弾丸の大きさは無視できるものとし、Homuraが弾丸に当たることはないとする。
== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == =
解説 == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == =

参照: <http://kmjp.hatenablog.jp/entry/2014/11/11/0900>

== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
'''

import math

W = 0
H = 0
D = 0
Mx = 0
My = 0
Hx = 0
Hy = 0
Vx = 0
Vy = 0


def ext_gcd(a, b):
    g = a
    x = 1
    y = 0
    if b != 0:
        g, y, x = ext_gcd(b, a % b)
        y -= (a // b) * x
    return g, x, y


def calc(tx, ty):
    A = 2 * W * Vy
    B = -2 * H * Vx
    C = Vx * ty - Vy * tx + Vy * Hx - Vx * Hy

    g = math.gcd(A, -B)
    if C % g > 0:
        return False

    A //= g
    B //= g
    C //= g

    g, y, x, = ext_gcd(B, A)
    m = C * y % A
    tv = ((ty + 2 * H * m - Hy) // Vy) % (2 * H * A // Vy)
    if tv < 0:
        tv += 2 * H * A // Vy
    return tv <= D


Q = int(input())
while Q != 0:
    Q -= 1
    W, H, D, Mx, My, Hx, Hy, Vx, Vy = map(int, input().split())
    if Vx < 0:
        Mx = W - Mx
        Hx = W - Hx
        Vx = -Vx
    if Vy < 0:
        My = H - My
        Hy = H - Hy
        Vy = -Vy

    if Vx == 0:
        if Mx == Hx and ((My > Hy and (My - Hy) <= D * Vy) or (My < Hy and (2 * H - My - Hy) <= D * Vy)):
            print('Hit')
        else:
            print('Miss')
        continue

    if Vy == 0:
        if My == Hy and ((Mx > Hx and (Mx - Hx) <= D * Vx) or (Mx < Hx and (2 * W - Mx - Hx) <= D * Vx)):
            print('Hit')
        else:
            print('Miss')
        continue

    g = math.gcd(Vx, Vy)
    D *= g
    Vx = Vx // g
    Vy = Vy // g

    if calc(Mx, My) or calc(2 * W - Mx, My) or calc(Mx, 2 * H - My) or calc(2 * W - Mx, 2 * H - My):
        print('Hit')
    else:
        print('Miss')
