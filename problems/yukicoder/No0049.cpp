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
 <url:https://yukicoder.me/problems/no/49>
 問題文============================================================
 太郎君は算数がとても苦手で、算数の宿題が出て困っています。
 今日出た宿題は足し算と掛け算の問題で、明日までに解いていかなければならないので、
 困っている太郎君の代わりに解いてあげてください。
 
 太郎君の国では、足し算は'*'の記号で、また、掛け算は'+'の記号で表されます。
 また、足し算と掛け算に優先度はなく、左から順番に計算します。
 =================================================================
 解説=============================================================
 ================================================================
 */

ll get(const string& S,int& i){
    ll ret = S[i++] - '0';
    while(isdigit(S[i])){
        ret = ret*10 + S[i++] - '0';
    }
    return ret;
}
void expr(const string& S,int& i,ll &res){
    res = get(S,i);
    while(i < S.length()){
        if(S[i] == '+'){
            i++;
            res *= get(S,i);
        }else{
            i++;
            res += get(S,i);
        }
    }
}
ll solve(){
    ll res = 0;
    string S; cin >> S;
    int i = 0;
    expr(S,i,res);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
