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
 <url:https://arc069.contest.atcoder.jp/tasks/arc069_c>
 問題文============================================================
 すぬけくんは数列を作るのが好きです。
 
 1 から N までの番号がついた石の山があります。 i 番の石の山は ai 個の石からなります。
 
 すぬけくんは以下の手順により長さ Σai の数列 s を構成することにしました。
 
 1. 石の数が最大である山のうち、最も番号が小さい山の番号を x として、s の末尾に x を追加する
 2. 石が 1 個以上存在する山を 1 つ選んで、選んだ山から石を 1 つ取り除く
 3. 石が 1 個以上存在する山が存在するなら 1. へ、そうでなければ数列の構成を終了する
 
 s が辞書順で最小の数列となるようにしたとき、s に 1,2,3,…,N という数がそれぞれいくつ含まれるか求めなさい。
 =================================================================
 解説=============================================================
 
 全部の山の石の数が0の状態から与えられた山の状態へ復元するイメージで考える。
 
 辞書順最小という条件がある為、できるだけ番号の小さい山から復元していきたい
 
 ここで、復元時に注目する山の最適な選択とは
 与えられた山の状態の個数において、山1を始点として山の数について単調増加していくような選択でいいことが分かる。
 
 すなわち、
 山の状態が以下のような場合(サンプル2)であれば
 i 1 2 3 4 5 6 7 7 8 9
 a 1 2 1 3 2 4 2 5 8 1
 
 順番に見ていくべきiは 1->2->4->6->8->9
 とすればいい（これはサンプル出力の0以外のインデックスの番号と一致する)
 
 ここで、出力の値について、
 今注目している山の番号を x ,次に注目する山の番号を yとすれば
 (a_x,a_y]の各値 z ( a_x < z <= a_y) に関して、
 z <= a_i となるような山の数の総和
 が山yに加算によって得られる値の個数となる。
 
 a <= 10^9だが、
 N <= 10^5であるので、座圧すれば見るべき値は高々10^5個に抑えられる。
 ================================================================
 */

void solve(){
    ll N; cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N;i++){ cin >> a[i]; }
    vector<ll> xa = a;
    sort(xa.begin(),xa.end()); xa.erase(unique(xa.begin(),xa.end()),xa.end());
    for(int i = 0; i < N;i++){
        a[i] = (ll)(lower_bound(xa.begin(), xa.end(), a[i]) - xa.begin());
    }

    vector<ll> imos(xa.size()+1);
    for(int i = 0; i < N;i++){ imos[0]++; imos[a[i]+1]--; }
    for(int i = 0; i < xa.size();i++) imos[i+1] += imos[i];
    vector<ll> ans(N);
    vector<pll> p;
    for(int i = 0; i < N;i++){
        if(p.empty()) p.push_back({a[0],i});
        if(p[p.size()-1].first < a[i]) p.push_back({a[i],i});
    }
    
    ll sum = 0;
    ll idx = 0;
    for(int i = 0; i < xa.size();i++){
        if(i==0){ sum += xa[i]*imos[i];
        }else{ sum += (xa[i]-xa[i-1])*imos[i]; }
        
        if(p[idx].first == i){
            ans[p[idx].second] = sum;
            sum = 0;
            idx++;
        }
    }
    for(int i = 0; i < N;i++){
        cout << ans[i] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
