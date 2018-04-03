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
 <url:https://yukicoder.me/problems/no/29>
 問題文============================================================
 Quinは、RPGをしている。
 そのRPGでは、アイテムは10種類（それぞれ番号付けされている）あり、「同じアイテム」を2つ揃えるか、
 「任意のアイテム」を4つ揃えるとパワーアップする仕組みがある。
 そして敵を倒したら、何かアイテムを３つもらうことができる。
 （同じアイテムがもらえることもある。）
 このとき、持てるアイテムの上限はないとし、アイテムの組み合わせは自由に決められる。
 （自動的にパワーアップすることはないとする。）
 
 N回敵を倒すと考えたとき、その時のパワーアップする最大の回数を求めてください。

 =================================================================
 解説=============================================================
 
 2個でパワーアップできるならした方がいい。
 
 ここである種類のアイテムが奇数個あるならばその1個を４種類揃える方に回した方がいい
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<int> a(N),b(N),c(N);
    int mp[11] = {0};
    for(int i = 0; i < N;i++){
        cin >> a[i] >> b[i] >> c[i];
        mp[a[i]]++; mp[b[i]]++; mp[c[i]]++;
    }
    int cnt4 = 0;
    for(int i = 1; i <= 10;i++){
        if(mp[i]%2 == 1){
            cnt4++; mp[i]--;
        }
        res += mp[i]/2;
    }
    res += cnt4/4;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
