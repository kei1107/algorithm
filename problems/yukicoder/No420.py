import math
def nCr(n,r):
    return math.factorial(n) // (math.factorial(n-r) * math.factorial(r));

x = int(input());

if x > 31:
    print("0 0")
elif x == 0:
    print("1 0")
else:
    print(nCr(31,x),2147483647*nCr(30,x-1))

