/*
 PalindromicTree
 文字列に含まれるユニークな回文を求める
 */
struct PalindromicTree{
    struct Node{
        int start,end; // s[start,end] = 回文となる部分文字列
        int length; // 部分列長さ
        map<char,int> insertEdge; // 自身のち両端に1段階拡張したノード番号へのパス
        int suffixEdge; // SuffixLinkの為のノード番号
        Node(){
            start = end = suffixEdge = -1;
            insertEdge.clear();
        }
    };
    
    Node root1; // root 0 : string:imaginary string ,length = -1
    Node root2; // root 1 : string:null             ,length = 0
    vector<Node> tree;
    
    string s;
    int ptr; // 末尾ノード番号
    int currentNode; // 現在のノード番号
    
    PalindromicTree(){}
    // str:対象となる文字列
    PalindromicTree(string& str){
        init(str);
    }
    void init(string& str){
        s = str;
        
        root1 = Node();
        root1.length = -1;
        root1.suffixEdge = 0;
        
        root2 = Node();
        root2.length = 0;
        root2.suffixEdge = 0;
        
        
        tree.clear();
        tree.resize(str.length()+10);
        tree[0] = root1;
        tree[1] = root2;
        ptr = 1;
        
        currentNode = 0;
    }
    
    // str[0] 〜 str[idx]まででPalindromic Treeを構築
    void insert(int idx){
        // STEP1
        // Search pattern : s[idx] X s[idx]
        int now = currentNode;
        while(true){
            int currentLength = tree[now].length;
            if((idx - currentLength >= 1)&&(s[idx] == s[idx-currentLength-1])) break;
            now = tree[now].suffixEdge;
        }
        // もし s[idx] X s[idx] となる Xを見つけたら
        // s[idx] X s[idx] がすでにノードに存在するかどうかを確認
        if(tree[now].insertEdge.count(s[idx])){
            // ノードが存在
            currentNode = tree[now].insertEdge[s[idx]];
            return;
        }
        // ノードが存在しないので新しいノードを作成
        ptr++;
        tree[now].insertEdge[s[idx]] = ptr;
        Node newNode;
        newNode.length = tree[now].length + 2;
        newNode.end = idx;
        newNode.start = idx - newNode.length + 1;
        tree[ptr] = newNode;
        
        // STEP2
        //newNodeに対する suffixlinkを作成
        now = tree[now].suffixEdge;
        
        //newNodeをcurrentNodeとして設定
        currentNode = ptr;
        if(tree[currentNode].length == 1){
            // もし回文の長さが1であれば, null文字へsuffixlinkをつなげる
            tree[currentNode].suffixEdge = 1;
            return;
        }
        while(true){
            int currentLength = tree[now].length;
            if((idx-currentLength >= 1) && (s[idx] == s[idx-currentLength-1])) break;
            now = tree[now].suffixEdge;
        }
        // s[idx] Y s[idx] となる Yを発見
        // suffixlinkを張る
        tree[currentNode].suffixEdge = tree[now].insertEdge[s[idx]];
    }
    
    // 文全ての文字に対してPalindromic_Treeを適用
    void fix(){
        for(int i = 0; i < s.length();i++) insert(i);
    }
    
    void datainfo(int n){
        cout << string(10,'=') << endl;
        cout << "node idx : " << n << endl;
        if(n == 0){
            cout << "palindrome : [imaginary string]" << endl;
        }else if(n==1){
            cout << "palindrome : [null]" << endl;
        }else{
            cout << "palindrome : " << s.substr(tree[n].start,tree[n].length) << endl;
        }
        cout << "(l,r) : (" << tree[n].start << "," << tree[n].end << ")" << endl;
        cout << "insert Edge idx :";
        for(auto next:tree[n].insertEdge){
            cout << next.second << " ";
        }cout << endl;
        cout << "suffix Edge idx :" << tree[n].suffixEdge << endl;
    }
    void alldatainfo(){
        cout << "input string : " << s << endl;
        for(int i = 0; i <= ptr;i++) datainfo(i);
    }
};


vector<ll> dp[2];
ll solve(){
    ll res = 0;
    string S,T; cin >> S >> T;
    transform(S.begin(),S.end(),S.begin(),::tolower);
    transform(T.begin(),T.end(),T.begin(),::tolower);
    
    string V = S + "{|" + T;
    PalindromicTree PT(V);
    dp[0].resize(V.size()+5);
    dp[1].resize(V.size()+5);
    for(int i = 0; i < V.size();i++){
        //    cout << "in" << endl;
        PT.insert(i);
        //  cout << PT.currentNode << endl;
        if(i < S.length()) dp[0][PT.currentNode]++;
        if(i >= S.length()+1) dp[1][PT.currentNode]++;
    }
    for(int i = PT.ptr; i >= 2;i--){
        res += dp[0][i]*dp[1][i];
        dp[0][PT.tree[i].suffixEdge] += dp[0][i];
        dp[1][PT.tree[i].suffixEdge] += dp[1][i];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}


//

// test
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    
    string str = "bcbaabaa";
    PalindromicTree PT(str);
    PT.fix();
    PT.alldatainfo();
    
    return 0;
}



// Verified : https://yukicoder.me/problems/399
vector<ll> dp[2];
ll solve(){
    ll res = 0;
    string S,T; cin >> S >> T;
    transform(S.begin(),S.end(),S.begin(),::tolower);
    transform(T.begin(),T.end(),T.begin(),::tolower);
    
    string V = S + "{|" + T;
    PalindromicTree PT(V);
    dp[0].resize(V.size()+5);
    dp[1].resize(V.size()+5);
    for(int i = 0; i < V.size();i++){
        PT.insert(i);
        if(i < S.length()) dp[0][PT.currentNode]++;
        if(i >= S.length()+1) dp[1][PT.currentNode]++;
    }
    for(int i = PT.ptr; i >= 2;i--){
        res += dp[0][i]*dp[1][i];
        dp[0][PT.tree[i].suffixEdge] += dp[0][i];
        dp[1][PT.tree[i].suffixEdge] += dp[1][i];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
