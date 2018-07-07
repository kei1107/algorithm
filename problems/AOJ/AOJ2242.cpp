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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2242>
 問題文============================================================
 
 年号について　その名前、期間、最後の年が与えらる
 また、クエリとして　ある年が与えられる。
 
 クエリに対して、その年の年号およびその年号が始まってから何年目かどうかを述べよ
 判断できない場合は Unknown を出力せよ
 
 =================================================================
 解説=============================================================
 
 制約が小さいので愚直に調べて間に合う
 
 ================================================================
 */
int N,Q;
struct Era{
    string name;
    int from,to;
    Era(string era = "",int from = 0,int to = 0):name(era),from(from),to(to){};
    bool operator <(const Era& o) const{ return from < o.from; }
};
void solve(){
    vector<Era> Eras(N);
    for(int i = 0; i < N;i++){
        string name;int x,y; cin >> name >> x >> y;
        Eras[i] = Era(name,y-x+1,y);
    }
    sort(Eras.begin(),Eras.end());
    while(Q--){
        int year; cin >> year;
        [&]{
            for(int i = 0; i < N;i++){
                if(Eras[i].from <= year && year <= Eras[i].to){
                    cout << Eras[i].name << " " << year - Eras[i].from + 1 << endl;
                    return;
                }
            }
            cout << "Unknown" << endl;
        }();
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> Q,N){
        solve();
    }
    return 0;
}
