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
 <url:https://yukicoder.me/problems/no/295>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 >> https://yukicoder.me/problems/no/295/editorial
 ================================================================
 */

ostream &operator<<(ostream &os, __int128_t value) {
    if (ostream::sentry(os)) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[64];
        char *d = end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len) {
            os.setstate(ios_base::badbit);
        }
    }
    return os;
}
__int128_t Lim = 1LL<<62;
istream &operator>>(istream &is, __int128_t &value) {
    string in;
    is >> in;
    value = 0;
    for (const char &c : in) {
        if ('0' <= c && c <= '9') value = 10 * value + (c - '0');
    }
    if (in[0] == '-') value *= -1;
    return is;
}

using Items = tuple<ll,ll,ll,ll>;
struct comp{
    bool operator()(const Items& a,const Items& b) const{
        return get<0>(a)*get<1>(b) < get<1>(a)*get<0>(b);
    }
};
__int128_t calc(ll S,vector<ll> ness){
    if(ness.empty()) return 1;
    __int128_t ret = S;
    if(S > 1e7){
        if(ness.size()==1){
            if(ness[0]==1) return ret;
            if(ness[0]==2) return ret*(ret-1)/2;
        }
        if(ness.size()==2 && ness[0]==1 && ness[1]==1) return (ret/2)*(ret-ret/2);
        return Lim;
    }
    ret = 1;
    priority_queue<Items,vector<Items>,comp> pq;
    for(auto s:ness){
        S -= s;
        pq.push(Items(s+1,1,s,s));
    }
    while(S--){
        ll a,b,c,d;
        tie(a,b,c,d) = pq.top(); pq.pop();
        
        ret = ret*a/b;
        if(ret>=Lim) return ret;
        c++;
        pq.push(Items(c+1,c+1-d,c,d));
    }
    return ret;
}
string solve(){
    string res;
    vector<ll> S(26); for(auto& in:S){ cin >> in;}
    string T; cin >> T;

    vector<vector<ll>> ness(26);
    pll target = {T.front()-'a',1};
    for(int i = 1; i < T.length();i++){
        if(target.first==T[i]-'a') target.second++;
        else { ness[target.first].push_back(target.second); target = {T[i]-'a',1};}
    } ness[target.first].push_back(target.second);
    for(int i = 0; i < 26;i++){
        if(S[i] < accumulate(ness[i].begin(),ness[i].end(),0LL)) return to_string(0);
        sort(ness[i].begin(),ness[i].end());
    }
    
    __int128_t mul = 1;
    for(int i = 0; i < 26;i++){
        __int128_t ret = calc(S[i],ness[i]);
        if(ret >= Lim) return "hel";
        mul *= ret;
        if(mul >= Lim) return "hel";
    }
    return to_string((ll)mul);
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
