'''
<url:https://yukicoder.me/problems/no/217>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 参考サイトや既存の魔法陣のテンプレ貼り付けてほい
 ================================================================
'''
import numpy as np
def magic(n):
    n = int(n)
    if n % 2 == 1:
        p = np.arange(1, n+1)
        return n*np.mod(p[:, None] + p - (n+3)//2, n) + np.mod(p[:, None] + 2*p-2, n) + 1
    elif n % 4 == 0:
        J = np.mod(np.arange(1, n+1), 4) // 2
        K = J[:, None] == J
        M = np.arange(1, n*n+1, n)[:, None] + np.arange(n)
        M[K] = n*n + 1 - M[K]
    else:
        p = n//2
        M = magic(p)
        M = np.block([[M, M+2*p*p], [M+3*p*p, M+p*p]])
        i = np.arange(p)
        k = (n-2)//4
        j = np.concatenate((np.arange(k), np.arange(n-k+1, n)))
        M[np.ix_(np.concatenate((i, i+p)), j)] = M[np.ix_(np.concatenate((i+p, i)), j)]
        M[np.ix_([k, k+p], [0, k])] = M[np.ix_([k+p, k], [0, k])]
    return M

n = int(input())
ret = magic(n);

for i in range(n):
    for j in range(n):
        print(ret[i][j],end=" ")
    print("")

