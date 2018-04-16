#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://dwacon2017-prelims.contest.atcoder.jp/tasks/dwango2017qual_d>
 問題文============================================================
 
 寿司が大好きなタカシくんは、回転寿司チェーン店のニコニコ寿司にやってきました。
 タカシくんは寿司を食べることで幸福度を得ることができます。
 しかし、タカシくんは現在糖質制限中で、
 普通に食べるよりもシャリを残してネタだけ食べる方が得られる幸福度が高くなります。
 
 タカシくんが席に着くと、N 皿の寿司が順番に流れてきて、そのうちな好きな寿司を何皿でも取ることができます。
 ただし、流れてくる順番でしか寿司を取ることができず、取った寿司を食べ終わってからしか次の寿司を取ることができません。
 ここで、寿司を食べ終わるとは、寿司を普通に食べ終わるか、シャリを残してネタだけ食べ終わることを指します。
 i(1≦i≦N) 番目に流れてきた寿司を、シャリを残してネタだけを食べた場合は幸福度を Xi 得ることができ、
 普通に食べた場合は幸福度を Yi 得ることができます。
 
 テーブルには、横に並べたときに M 皿まで置ける広さのスペースがあり、
 タカシくんは寿司を食べ終わるたびにここに皿を置いていきます。
 すでに置いてある皿の上には別の皿を何枚でも重ねることができます。
 しかし、ネタだけ食べた皿にはシャリが残っているため、その上に別の皿を重ねることはできません。
 また、すでに置いてある皿の下に皿を置くことはできません。 皿を置ける場所がなくなった時点で、
 それ以上寿司を食べることはできません。
 
 タカシくんが得ることのできる幸福度の合計の最大値を答えてください。
 
 =================================================================
 解説=============================================================
 
 N <= M であれば、Nさら全てネタだけ食べれるので　最大うれしい
 
 以降 M < N とする
 
 全て食べるのを o , ネタのみ食べるのを x とすると
 
 oooooxoooooxooxoxxoxoooooo
 
 と行ったものがあれば、　それぞれ
 
 [ooooox][ooooox][oox][ox][x][ox][oooooo]
 
 と行った風に皿が分けられる
 
 ここで　M-1個まで区分けされたものは全ての皿を食べることができ、
 M個に区分けするとは
 M-1個に区分けされたものの任意の場所に敷居をいれて M個にすればよく、
 M-1個までのネタのみを食べる皿を自由に決められる。
 
 とした場合、最適なMー1個の選択とは、　XとYの差が大きいものからM-1個選ぶのが最適だとわかる。
 
 よってMー1個のネタを食べる皿を決定すれば、最後の食べる皿のみを決めればよく、これはO(N)で計算できる
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<ll> X(N),Y(N);
    vector<pll> dif(N);
    for(int i = 0; i < N;i++){
        cin >> X[i] >> Y[i];
        dif[i] = {X[i] - Y[i],i};
    }
    if(N <= M) return res = accumulate(X.begin(), X.end(), 0LL);
    sort(dif.begin(),dif.end()); reverse(dif.begin(), dif.end());
    vector<int> f(N,false);
    for(int i = 0; i < M-1;i++){ f[dif[i].second] = true; }
    
    ll t = 0;
    ll cnt = 0;
    for(int i = 0; i < N;i++){
        if(cnt == M-1){
            res = max(res,t+X[i]);
            t += Y[i];
        }else{
            t += (f[i]?X[i]:Y[i]);
            cnt += f[i];
            if(cnt == M-1){
                for(int j = 0; j <= i;j++) if(!f[j]) res = max(res,t+(X[j]-Y[j]));
            }
        }
    }
    res = max(res,t);
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
