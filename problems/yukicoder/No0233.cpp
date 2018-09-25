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
 <url:https://yukicoder.me/problems/no/233>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 名前を全探索して、使ってない名前を発見したら終了
 ================================================================
 */

set<string> names;
void make_test(){
    vector<char> vowel = {'a','a','i','e','u','u'},long_vowel = {'n','b','m','g','r'};
    vector<int> order(5); iota(order.begin(),order.end(),0);
    do{
        vector<int> order2(5); iota(order2.begin(),order2.end(),0);
        do{
            string name;
            for(int i = 0; i < 5;i++){
                name += long_vowel[order[i]];
                name += vowel[order2[i]];
            }
            for(int i = 0; i <= name.length();i++){
                string maked_name = name.substr(0,i) + vowel[5] + name.substr(i);
                names.insert(maked_name);
            }
        }while(next_permutation(order2.begin(),order2.end()));
    }while(next_permutation(order.begin(),order.end()));
}
string solve(){
    make_test();
    string res;
    int N; cin >> N;
    vector<string> S(N);
    for(auto& in:S){
        cin >> in;
        names.erase(in);
    }
    if(names.empty()) return "NO";
    res = *names.begin();
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
