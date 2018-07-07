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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1282>
 問題文============================================================
 プログラムに関するガチBNFが与えられる。
 
 ここで、配列外参照 or 未定義値の代入　が発生するならばその行数を述べよ
 
 =================================================================
 解説=============================================================

 BNF通りに実装する。
 配列の処理はmapを用いればよい
 ================================================================
 */

int Getnum(int& idx,const string& str,map<char,int>& storage1,map<pair<char,int>,int>& storage2){
    int ret = 0;
    if(isdigit(str[idx])){
        while(isdigit(str[idx])){
            ret = ret*10 + (str[idx++]-'0');
        }
    }else{
        char alpha = str[idx++];
        idx++; // [
        int val = Getnum(idx,str,storage1,storage2);
        idx++; // ]
        if(storage1[alpha] <= val) return -1;
        if(storage2.count(pair<char,int>(alpha,val))==0) return -1;
        return storage2[pair<char,int>(alpha,val)];
    }
    return ret;
}
bool declaration_assignment(int& idx,const string& str,
                            map<char,int>& storage1,map<pair<char,int>,int>& storage2){
    char alpha = str[idx++];
    idx++; // [
    int val1 = Getnum(idx,str,storage1,storage2);
    if(val1 == -1) return false;
    idx++; // ]
    if(str.length() == idx){
        storage1[alpha] = val1;
        return true;
    }
    idx++; // =
    if(storage1[alpha] <= val1) return false;
    int val2 = Getnum(idx,str,storage1,storage2);
    if(val2 == -1) return false;
    storage2[pair<char,int>(alpha,val1)] = val2;
    return true;
}
int solve(const string& firstline){
    int res = 0;
    map<char,int> storage1;
    map<pair<char,int>,int> storage2;
    vector<string> Lines; Lines.push_back(firstline);
    string str;
    while(cin >> str){
        if(str == ".") break;
        Lines.push_back(str);
    }
    for(int i = 0;i < Lines.size();i++){
        int idx = 0;
        if(!declaration_assignment(idx, Lines[i], storage1, storage2)) return i + 1;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    string str;
    while(cin >> str){
        if(str == ".") break;
        cout << solve(str) << endl;
    }
    return 0;
}
