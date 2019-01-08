#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

int memo[5001][2];
bool rec(int n,bool turn,vector<int>& a,vector<int>& b){
    if(~memo[n][turn]) return memo[n][turn];
    bool ret = false;
    if(!turn){
        for(auto v:a){
            if(n < v) continue;
            ret |= !rec(n-v,!turn,a,b);
        }
    }else{
        for(auto v:b){
            if(n < v) continue;
            ret |= !rec(n-v,!turn,a,b);
        }
    }
    return memo[n][turn] = ret;
}
void test(vector<int>& a,vector<int>& b){
    fill(*memo,*memo+5001*2,-1);
    for(int i = 0; i <= 5000;i++){
        cout << i << " : " << rec(i,false,a,b) << endl;
    }
}
class PartisanGame {
    public:
    string getWinner(int n, vector <int> a, vector <int> b) {
        fill(*memo,*memo+5001*2,-1);
        for(int i = 0; i <= 5000;i++){
            bool ret = rec(i,false,a,b);
            if(i == n){
                return ret?"Alice":"Bob";
            }
        }
        
        bool changed = false;
        for(int i = 1000; i <= 5000;i++){
            if(memo[i-1][0] != memo[i][0]) changed = true;
        }
        if(!changed){ return memo[5000][0]?"Alice":"Bob"; }
        int cycle = 0;
        for(int i = 1; i <= 2500;i++){
            bool ok = true;
            for(int j = 0; j < i;j++){
                ok &= (memo[j][0]==memo[i+j][0]);
            }
            if(ok) cycle = i;
        }
        n = cycle + (n-cycle)%cycle;
        return memo[n][0]?"Alice":"Bob";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arr1[] = {3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(0, Arg3, getWinner(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(1, Arg3, getWinner(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 104982; int Arr1[] = {2, 3, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(2, Arg3, getWinner(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 999999999; int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(3, Arg3, getWinner(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000000; int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(4, Arg3, getWinner(Arg0, Arg1, Arg2)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    PartisanGame ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
