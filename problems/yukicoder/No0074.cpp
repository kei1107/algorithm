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
 <url:https://yukicoder.me/problems/no/74>
 問題文============================================================
 貯金箱くんはとても退屈していました。
 そこで自分が持っている硬貨で遊ぶことにしました。
 
 まず自分の持っている硬貨を床にばらまき、そこから N 枚硬貨を選び円形に並べます。
 次に N 枚の硬貨から適当に1枚選びます。
 選んだ硬貨の額面を D 円としたとき、選んだ硬貨から時計回りに D 個先の硬貨と、反時計回りに D 個先の硬貨をひっくり返します。
 ただし時計回りでも反時計回りでも同じ硬貨だった場合はその硬貨を1回だけひっくり返します。
 貯金箱くんは、この操作を繰り返しすべての硬貨を表向きにしたいです。
 
 硬貨の並び、額面、最初の裏表が与えられるのですべての硬貨を表向きにできるか判定してください。
 ただし同じ硬貨を複数回選んでもよいとします。
 =================================================================
 解説=============================================================
 
 ある硬貨を選んだ時、どの硬貨がひっくりかえるのかを明確にするために、
 x,yがひっくりかえるならば　x - y に辺を繋ぐ
 
 ここで、ある裏向きの硬貨が存在する時、裏向き硬貨が存在する状態をなくすために必要な操作を考える。
 そのために必要なのは次の2パターンである。
 
 ・裏向きの硬貨と同時にひっくり返す事ができる裏向きの硬貨の両方を裏返す
 ・裏向きの硬貨と同時にひっくり返す事ができる自身がひっくり返る硬貨を裏返し、
    自信がひっくり返る硬貨が裏向きであれば、ひっくり返して表向きにする。
 
 この時、制約の性質より、ある裏向きの硬貨は同時にひっくり返す事ができる表向きの硬貨を用いる事で
 移動可能な任意の硬貨を裏向きにする事ができる。
 ex. x := 裏向き   o:= 表向き　とすれば
    x-o-o-o-x => o-x-o-o-x => o-o-x-o-x => o-o-o-x-x
 よって、この性質より、グラフ上で互いにいきき可能な頂点群をグループとすれば、
 
 グループ内に自信がひっくり返る事ができる頂点があれば、そのグループ内の裏向き硬貨は必ず表向きにできる。
 グループ内の裏向き効果が偶数個存在すれば、そのグループ内の裏向き硬貨は全て表向きにできる。
 
 という事ができる。
 ================================================================
 */

void dfs(ll n,int group,vector<int>& check,vector<vector<ll>>&G){
    if(check[n] != 0) return;
    check[n] = group;
    for(auto next:G[n]){
        dfs(next,group,check,G);
    }
}
string solve(){
    ll N; cin >> N;
    vector<ll> D(N); for(auto& in:D) cin >> in;
    vector<int> W(N); for(auto& in:W) cin >> in;
    vector<vector<ll>> G(N);
    vector<ll> roots;
    for(int i = 0; i < N;i++){
        if((i+D[i])%N == (i-D[i]+10000*N)%N){
            roots.push_back((i+D[i])%N);
        }
        else{
            G[(i+D[i])%N].push_back((i-D[i]+10000*N)%N);
            G[(i-D[i]+10000*N)%N].push_back((i+D[i])%N);
        }
    }
    int group = 1;
    vector<int> check(N,0);
    for(int i = 0; i < N;i++){
        if(check[i] != 0) continue;
        dfs(i,group++,check,G);
    }
    map<ll,ll> mp;
    for(int i = 0; i < N;i++) if(W[i] == 0) mp[check[i]]++;
    for(auto root:roots) mp[check[root]] = 0;
    for(auto p:mp){
        if(p.second&1) return "No";
    }
    return "Yes";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
