#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF (1<<30)
#define LINF (1LL<<60)

/*
 <url:http://poj.org/problem?id=2886>
 問題文============================================================
 N人の子供が一枚ずつカードを持っていて，輪になって並んでいる．
 K番目の子供からスタートする．まず，現在選んでいる子供を輪から除外する．
 除外した子供が持っていたカードに書かれている番号だけずれた子供を選ぶ．これを繰り返す．
 i番目の操作で除外された子供は，iの約数の数だけキャンディをもらえる．
 一番多くキャンディをもらえる子供は誰か．
 =================================================================
 
 解説=============================================================
 先に、i番目にもらえるキャンディの数を計算しておく。
 問題は、i番目に誰がキャンディをもらえるか。
 
 残り人数等をBITで管理して、にぶたんを行なって次の子供を決めて行く
 ================================================================
 */

struct BIT {
    int N;
    vector<ll> bit;
    BIT(){}
    BIT(int N):N(N) {
        bit.resize(N + 1, 0);
    }
    void add(int x, int val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    int sum(int x){
        int ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
};

#define MAX_N 500010
char name[MAX_N][30];
int num[MAX_N];
int N,K;
BIT _bit(MAX_N);
bool isPrime[MAX_N];
ll F[MAX_N];

void init(){
    for(int i = 0; i < MAX_N;i++) F[i] = 1;
    for(int i = 2; i < MAX_N;i++){
        if(!isPrime[i]){
            for(int j = i; j < MAX_N; j += i){
                int cnt = 0;
                int t = j;
                while(t % i == 0){ t /= i; cnt++; }
                isPrime[j] = true;
                F[j] *= (cnt + 1);
            }
        }
    }
}

int find(int num){
    int l = -1, r = N;
    while (r - l > 1) {
        int m = (l + r) /2;
        if(_bit.sum(m+1)-1 < num){
            l = m;
        }else{
            r = m;
        }
    }
    return r;
}

int main(){
    init();
    while(cin >> N >> K){
        for(int i = 0; i < N;i++) scanf("%s %d",name[i],&num[i]);
        fill(_bit.bit.begin(),_bit.bit.end(),0);
        for(int i = 0; i < N;i++) _bit.add(i+1,1);
        
        ll ans_v = 0, ans_idx = 0; int idx = --K;
        for(int k = 0; k < N;k++){
            if(F[k+1] > ans_v){ ans_v = F[k+1]; ans_idx = idx; }
            _bit.add(idx+1,-1);
            if(k == N - 1)break;
            ll sum = N - k - 1;
            if(num[idx] > 0){
                K = (K + num[idx] - 1) % sum;
            }else{
                K = (K + num[idx]) % sum;
            }
            if(K < 0) K += sum;
            idx = find(K);
        }
        cout << name[ans_idx] << " " << ans_v << endl;
    }
    return 0;
}
