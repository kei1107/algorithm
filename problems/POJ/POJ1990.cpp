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
<url:http://poj.org/problem?id=1990>
問題文============================================================
 N 匹の牛が一直線上に並んでおり、各牛について、その聴力と x 座標が与えられる。
 異なる二頭の牛同士は、座標の差（の絶対値）に大きい方の聴力を乗じた音量で会話をする。
 全ての牛が会話をした場合の音量の総和を求めよ。
=================================================================

解説=============================================================
BIT
 
 vの値でソートしてやれば、掛けなければならない方の大きさが一意
 
 ある牛Cに注目した時、
 その牛より左にある牛との位置の差の総和は 牛の数 * Cのv - ΣCより左のいる牛のvの総和
 
 右の場合は式が逆になる
 
 よってBITで計算できて、NlogN
================================================================
*/

struct BIT {
    int N;
    vector<pll> bit;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, make_pair(0LL,0LL));
    }
    void add(ll x, ll val,ll v)
    {
        while (x <= N) {
            bit[x].first += val;
            bit[x].second += v;
            x += x & -x;
        }
    }
    pll sum(ll x)
    {
        pll ret = make_pair(0LL,0LL);
        while (x) {
            ret.first += bit[x].first;
            ret.second += bit[x].second;
            x &= (x - 1);
        }
        
        return (ret);
    }
};

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<pll> vx(N);
    for(int i = 0; i < N;i++) cin >> vx[i].first >> vx[i].second;
    sort(vx.begin(),vx.end());
    BIT _bit(20000);
    ll ans = 0;
    for(int i = 0; i < N;i++){
        pll l = _bit.sum(vx[i].second - 1);
        pll r = _bit.sum(20000);
        r.first -= l.first; r.second -= l.second;
        
        ans += vx[i].first *( vx[i].second * l.first - l.second);
        ans += vx[i].first *(r.second - vx[i].second * r.first);
        
        _bit.add(vx[i].second,1,vx[i].second);
    }
    cout << ans << endl;
	return 0;
}
