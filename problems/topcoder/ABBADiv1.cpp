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

map<string,bool> mp;

void rec(string target,const string& initial){
    if(target.length() < initial.length()) return;
    if(mp[target]) return;
    mp[target] = true;
    if(target.back()=='A'){
        target.pop_back();
        rec(target,initial);
        target.push_back('A');
    }
    
    if(target.front()=='B'){
        reverse(target.begin(), target.end());
        target.pop_back();
        rec(target,initial);
    }
}
class ABBADiv1 {
    public:
    string canObtain(string initial, string target) {
        mp.clear();
        rec(target,initial);
        if(mp[initial]) return "Possible";
        else return "Impossible";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; string Arg1 = "BABA"; string Arg2 = "Possible"; verify_case(0, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BAAAAABAA"; string Arg1 = "BAABAAAAAB"; string Arg2 = "Possible"; verify_case(1, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "A"; string Arg1 = "ABBA"; string Arg2 = "Impossible"; verify_case(2, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AAABBAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Possible"; verify_case(3, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "AAABAAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Impossible"; verify_case(4, Arg2, canObtain(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    ABBADiv1 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
