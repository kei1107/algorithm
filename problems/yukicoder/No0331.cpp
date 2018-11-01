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
 <url:https://yukicoder.me/problems/no/331>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dfsの要領で潜っていく
 ================================================================
 */


int query(char c){
    cout << c << endl;
    string input;
    cin >> input;
    if(input == "Merry") exit(0);
    return atoi(input.c_str());
}

bool visited[50][50];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void rec(int y,int x,int d){
    visited[y][x] = true;
    for(int _ = 0; _ < 4;_++){
        int rep = query('R');
        while(rep==20151224) query('F');
        d = (d+1)%4;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if((rep > 0)&&(!visited[ny][nx])){ query('F'); rec(ny,nx,d); }
    }
    query('B');
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    string input; cin >> input;
    rec(25,25,1);
    return 0;
}
