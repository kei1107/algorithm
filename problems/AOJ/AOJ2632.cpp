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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2632>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 なにも横棒が取り除かれていないとき、あみだくじは2w周期で一致する。
 よって 最大でも高さ2w分しか見なくても良い
 
 また、ある位置から右端or左端への移動および降下分は計算できるので
 実際にその棒の位置から下に降りて言ったときにどこにたどり着くかというのは計算できる。
 
 さらに、ある横棒を取り除くということはその横棒の左側、右側から入る結果が入れ替わるという
 ことであるため、上から順に見て行くことによってシミュレーションできる
 ================================================================
 */

int h,w,n;
int get(int i,int j){
    i %= 2*w;
    while(i){
        int T;
        if((i+j)%2 == 0){ T = -min(i,j);
        }else{ T = min(i,w-j-1); }
        j += T; i -= abs(T);
        if(i) i--;
    }
    return j;
}
void solve(){
    cin >> h >> w >> n;
    vector<pii> ab(n); for(auto& in:ab){ cin >> in.first >> in.second; in.first--; in.second--; }
    
    vector<int> amida(w); iota(amida.begin(),amida.end(),0);
    sort(ab.begin(),ab.end());
    for(auto& p:ab){
        int H = p.first, l = p.second, r = p.second+1;
        int getlv = get(H,l), getrv = get(H,r);
        swap(amida[getlv],amida[getrv]);
    }
    
    vector<int> ans(w);
    for(int i = 0; i < w;i++) ans[amida[get(h,i)]] = i + 1;
    for(int i = 0; i < w;i++){
        cout << ans[i] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
