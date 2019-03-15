#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://codeforces.com/contest/1087/problem/A>
 問題文============================================================
 s=s1s2s3...snとなる文字列がある
 暗号化処理として、
 
 s1
 s1s2
 s3s1s2
 s3s1s2s4
 .
 .
 .
 と左右に文字を挿入していく
 
 入力として暗号後の文字列が与えられるので、元の文字列を復元せよ
 =================================================================
 解説=============================================================
 deque使って復元すればいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    string s; cin >> s;
    deque<char> deq;
    for(int i = 0; i < s.length();i++){
        deq.push_back(s[i]);
    }
    int turn = s.length()%2==0;
    for(int i = 0; i < s.length();i++){
        if(turn != 0){
            res += string(1,deq.back());  deq.pop_back();
        }else{
            res += string(1,deq.front()); deq.pop_front();
        }
        turn = !turn;
    }
    reverse(res.begin(),res.end());

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}
