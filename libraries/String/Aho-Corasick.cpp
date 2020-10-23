#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*-------Aho Corasick Setting---------*/
const int Alphabets = 26;
const int AlphabetBase = 'a' ; // '0'
/*------------------------------------*/
class Aho_Corasick{
public:
    struct PMA{
        PMA *fail;
        PMA *next[Alphabets];
        vector<int> accepts; // accepts id : trieでのleaf, 現ノードが末尾となる入力文字列のindex番号が返却される．
        PMA():fail(NULL){memset(next,0,sizeof next);}
        ~PMA() { delete fail; for(int i = 0; i < Alphabets ; i++) delete next[i];}
    };
    
    PMA *Root;
    int PatternSize;
    
    // O( Σ]|p[i]| Alphabets )
    void buildMPA(vector<string>& pattern){
        PatternSize = (int)pattern.size();
        PMA *root = new PMA, *now;
        root->fail = root;
        for(int i = 0 ; i < (int)pattern.size(); i++){
            now = root;
            for(int j = 0 ; j < (int)pattern[i].size(); j++){
                int c = pattern[i][j] - AlphabetBase;
                if(now->next[c]==NULL)now->next[c] = new PMA;
                now = now->next[c];
            }
            now->accepts.push_back(i);
        }// Trie
        
        queue<PMA*> Q;
        for(int i = 0; i < Alphabets; i++){
            if(root -> next[i] == NULL){
                root -> next[i] = root;
            }else {
                root->next[i] -> fail = root;
                Q.push(root->next[i]);
            }
        }
        while(!Q.empty()){
            now = Q.front(); Q.pop();
            for(int i = 0; i < Alphabets; i++){
                if(now->next[i]){
                    PMA *nxt = now->fail;
                    while(nxt->next[i] == NULL)nxt = nxt -> fail;
                    now-> next[i]->fail = nxt -> next[i];
                    now->next[i]->accepts = mergev(now->next[i]->accepts, nxt->next[i]->accepts );
                    Q.push(now->next[i]);
                }
            }
        }
        Root = root;
    }
    
    // target S , res:include id (exist or times). O( |S| + Σ|p[i]| )
    // 探索対象文字列S中に，各入力文字列がいくつ現れるか
    // if pattern = {"bbb", "bba", "bac"}, S = "bbabbbbac"
    //    -> res = {2,2,1}
    // test3
    PMA* match(PMA* pma, string &S, vector<int> &res){
        res.resize(PatternSize,0);
        for(int i = 0; i < (int)S.size(); i++){
            int c = S[i] - AlphabetBase;
            while(pma -> next[c] == NULL){
                pma = pma -> fail;
            }
            pma = pma -> next[c];
            for(int j = 0; j < (int)pma->accepts.size(); j++ ){
                res[pma->accepts[j]] ++; //not sum if sum, vec++
            }
        }
        return pma;
    }
    
    // on not need result
    // 先頭の文字を最小限消してグラフに存在する次ノードへの移動
    // 行き先が無い場合（全ての文字が消される場合）はrootへ戻る
    PMA* NextStep(PMA* pma, char cc){
        int c = cc- AlphabetBase;
        while(pma->next[c] == NULL )pma = pma->fail;
        pma = pma-> next[c];
        return pma;
    }
    
private:
    // unique and merge
    vector<int> mergev(vector<int> &a, vector<int> &b){
        vector<int> target;
        set_union(a.begin(),a.end(),b.begin(),b.end(), back_inserter(target));
        return target;
    }
};




// TEST ================================================== //

void test1(){
    Aho_Corasick Aho;
    vector<string>vs;
    vs.push_back("a");
    vs.push_back("ab");
    vs.push_back("aca");
    vs.push_back("ba");
    vs.push_back("c");
    vs.push_back("cab");
    Aho.buildMPA(vs);
    Aho_Corasick::PMA *saveroot;
    saveroot = Aho.Root;
    vector<int>res;
    string s = "ab";
//    string s = "abab"
    Aho.match(saveroot,s,res);
    for(int i = 0; i < (int)vs.size(); i++){
        cout<<vs[i]<<", match times is "<<res[i]<<endl;
        if(res[i])cout<<vs[i]<<endl;
    }
}

void test2(){
    Aho_Corasick Aho;
    vector<string>vs;
    vs.push_back("aa");
    Aho.buildMPA(vs);
    Aho_Corasick::PMA *saveroot;
    saveroot = Aho.Root;
    vector<int>res;
    string s = "aaaa";
    Aho.match(saveroot,s,res);
    
    for(int i = 0; i < (int)vs.size(); i++){
        cout<<vs[i]<<", match times is "<<res[i]<<endl;
    }
}

void test3(){
    Aho_Corasick Aho;
    vector<string>vs;
    vs.push_back("bbb");
    vs.push_back("bba");
    vs.push_back("bac");
    Aho.buildMPA(vs);
    Aho_Corasick::PMA *saveroot;
    saveroot = Aho.Root;
    vector<int>res;
    string s = "bbabbbbac";
    Aho.match(saveroot,s,res);
    
    for(int i = 0; i < (int)vs.size(); i++){
        cout<<vs[i]<<", match times is "<<res[i]<<endl;
    }
}

void test_all(){
    Aho_Corasick Aho;
    vector<string>vs;
    vs.push_back("abb");
    vs.push_back("b");
    vs.push_back("bbb");
    Aho.buildMPA(vs);
    
    cout << "{";
    for(int i = 0; i < (int)vs.size();i++){
        cout << vs[i];
        if(i != vs.size()-1)cout << ",";
        else cout << "}" << endl;
    }
    
    Aho_Corasick::PMA *saveroot;
    Aho_Corasick::PMA *Roots;
    saveroot = Aho.Root;
    Roots = Aho.Root;
    
    vector<int>res;
    cout<<"---------------------------------"<<endl;
    char c = 'c';
    string s;s.push_back(c);
    cout<< c <<endl;
    saveroot = Aho.match(saveroot,s,res);
    for(int i = 0; i < (int)vs.size(); i++){
        cout<<vs[i]<<", match times is "<<res[i]<<endl;
    }
    cout<<"---------------------------------"<<endl;
    c = 'b';
    s.clear();
    s.push_back(c);
    cout<< c <<endl;
    saveroot = Aho.match(saveroot,s,res);
    for(int i = 0; i < (int)vs.size(); i++){
        cout<<vs[i]<<", match times is "<<res[i]<<endl;
    }
    cout<<"---------------------------------"<<endl;
    c = 'b';
    s.clear();
    s.push_back(c);
    cout<< c <<endl;
    saveroot = Aho.match(saveroot,s,res);
    
    for(int i = 0; i < (int)vs.size(); i++){
        cout<<vs[i]<<", match times is "<<res[i]<<endl;
    }
    cout<<"---------------------------------"<<endl;
    c = 'b';
    s.clear();
    s.push_back(c);
    cout<< c <<endl;
    saveroot = Aho.match(saveroot,s,res);
    
    for(int i = 0; i < (int)vs.size(); i++){
        cout<<vs[i]<<", match times is "<<res[i]<<endl;
    }
    cout<<"---------------------------------"<<endl;
    s.clear();
    res.clear();
    s = "bbb";
    Aho.match(Roots,s,res);
    for(int i = 0; i < (int)vs.size(); i++){
        cout<<vs[i]<<", match times is "<<res[i]<<endl;
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
//    test1();
//    test2();
//    test3();
    test_all();
    return 0;
}
