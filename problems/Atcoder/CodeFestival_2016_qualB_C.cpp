#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://code-festival-2016-qualb.contest.atcoder.jp/tasks/codefestival_2016_qualB_c>
問題文============================================================
 xy平面上の0≦x≦W,0≦y≦Hをみたす領域にあるx,yともに整数である点すべてに、ひとつずつ家があります。
 
 x座標が等しくy座標の差が1であるか、y座標が等しくx座標の差が1であるような2点の組のうち、
 両方の点に家が存在するような全てのものに対し、その2点の間には舗装されていない道路があります。
 
 座標(i,j)と(i+1,j)にある家の間の道路を舗装するのにはjの値にかかわらずコストがpi、
 座標(i,j)と(i,j+1)にある家の間の道路を舗装するのにはiの値にかかわらずコストがqjかかります。
 
 高橋君は、このうちいくつかの道路を舗装し、
 舗装された道路のみを通って任意の2つの家の間を行き来できるようにしたいです。
 かかるコストの総和の最小値を求めてください。
 
 1≦W,H≦10^5
 1≦pi≦10^8(0≦i≦W−1)
 1≦qj≦10^8(0≦j≦H−1)
 pi(0≦i≦W−1)は整数である
 qj(0≦j≦H−1)は整数である
=================================================================

解説=============================================================

 最小全域木の要領でコストの小さいものから辺を追加して行くことを考える。
 一辺づつ考えると　O(H*W) で　TLEするので　いくつかまとめて辺を追加できないかを考える
 
 そこで次のような考え方ができる
 
 最初、 縦、横　共に　あるコストに関してそれぞれ 最大 h = H+1本、w = W+1本の辺を追加できる
 
 ここで 横に関して最小のコストを見た時 cost * h を用いて辺を引くことができ、
 その後 横に関しては　一本辺を引かなくてもよくなるので　w = w-1 とできる
 
 逆に　縦に関して最小のコストを見た時 cost * w を用いて辺を引くことができ、
 その後　縦に関しては　一本辺を引かなくてもよくなるので h = h-1 とできる
 
 これを繰り返すことによって最小全域木のコストを作れる
================================================================
*/
ll solve(){
    ll ret = 0;
    ll W,H; cin >> W >> H;
    vector<ll> p(W),q(H);
    for(auto &in:p) cin >> in;
    for(auto &in:q) cin >> in;
    vector<pll> event(W+H);
    for(int i = 0; i < W;i++) event[i] = {p[i],0};
    for(int i = 0; i < H;i++) event[i+W] = {q[i],1};
    sort(event.begin(),event.end());
    
    W++; H++;
    for(const pll& e:event){
        if(e.second == 0){ ret += e.first*H; W--;
        }else{ ret += e.first*W; H--; }
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
