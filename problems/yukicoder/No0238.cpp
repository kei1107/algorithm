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
 <url:https://yukicoder.me/problems/no/238>
 問題文============================================================
 =================================================================
 解説=============================================================
 回文ととなるには、
 （文字列）と（逆順にした文字列）にしたものが一致するかをみればいい。
 
 （文字列）を基準とした場合
    （逆順にした文字列）と違う単語となる場所があれば、その見ている（文字列）の単語を
    適切な場所に追加すればいい
    （ここで２回以上追加する必要があればNA）
 （逆順にした文字列）を基準とした場合
    上記操作と同様のことをすればいい
 
 よって、それぞれ基準とした場合でひ文字を順に見ていけばいい
 一回も文字が追加されていなければ中心に適する文字を追加すいかすればいい
 ================================================================
 */

string solve(){
    string res = "NA";
    string S; cin >> S;
    auto check = [](string T){
        string revT = T;
        reverse(revT.begin(),revT.end());
        bool add = false;
        for(int i = 0; i < T.length();i++){
            if(T[i] == revT[i]) continue;
            if(add) return make_pair(false,T);
            add = true;
            T.insert(T.length()-i, string(1,T[i]));
            revT.insert(i, string(1,T[i]));
        }
        return make_pair(true,T);
    };
    auto ret1 = check(S);
    if(ret1.first){
        res = ret1.second;
    }
    reverse(S.begin(),S.end());
    auto ret2 = check(S);
    if(ret2.first){
        res = ret2.second;
        reverse(res.begin(),res.end());
    }
    if(ret1.first || ret2.first){
        if(res.length() == S.length()){
            res.insert(res.length()/2, string(1,res[res.length()/2]));
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
