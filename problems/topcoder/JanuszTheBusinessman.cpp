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

class JanuszTheBusinessman {
    public:
    int makeGuestsReturn(vector <int> arrivals, vector <int> departures) {
        int res = 0;
        int n = (int)arrivals.size();
        
        vector<pii> events(n);
        for(int i = 0; i < n;i++){
            events[i] = {departures[i],arrivals[i]};
        }
        sort(events.begin(),events.end());
        vector<int> flag(n);
        for(int i = 0; i < n;i++){
            if(flag[i]) continue;
            int d = events[i].first;
            
            int target = -1;
            for(int j = 0; j < n;j++){
                if(events[j].second <= d && d <= events[j].first) target = j;
            }
            for(int j = 0; j < n;j++){
                if(events[j].first < events[target].second) continue;
                if(events[target].first < events[j].second) continue;
                
                flag[j] = true;
            }
            
            res++;
        }
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 10, 6}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 11, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 10, 23, 34, 45, 123, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, 12, 40, 50, 48, 187, 365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {8, 12, 20, 30, 54, 54, 68, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13, 31, 30, 53, 55, 70, 80, 76}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(4, Arg2, makeGuestsReturn(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    JanuszTheBusinessman ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
