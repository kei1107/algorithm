struct nd {
    long long v;
    nd(long long v = 0) :v(v) {} // ! e
};
struct SegmentTreeFastAry {
    nd merge(nd& l, nd& r) {
        nd ret;
        ret.v = min(l.v, r.v);
        return ret;
    }
    void updatepoint(nd& node, nd& nx) { // point update
        node.v = nx.v;
    }
    void addpoint(nd& node, nd& nx) { // point add
        node.v += nx.v;
    }
    
    // -- setting -- //
    int ARY_SIZE; nd node[1 << 17]; // 131072
    void init(int n) {ARY_SIZE = 1; while (ARY_SIZE < n) ARY_SIZE <<= 1;}
    SegmentTreeFastAry(int n) : ARY_SIZE(1) { init(n); }
    inline void update(int i, nd& val) {i += ARY_SIZE;updatepoint(node[i], val);
        while (i > 1) {i >>= 1;    node[i] = merge(node[i << 1], node[(i << 1) + 1]);}}
    inline void add(int i, nd& val) {i += ARY_SIZE; addpoint(node[i], val);
        while (i > 1) {    i >>= 1;node[i] = merge(node[i << 1], node[(i << 1) + 1]);}}
    inline nd query(int l, int r) {    if (l >= r) return nd();nd vl = nd(), vr = nd();
        for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
            if (l & 1) vl = merge(vl, node[l++]);if (r & 1) vr = merge(node[--r], vr);}    return merge(vl, vr);}
    nd operator[](int i) { return node[i + ARY_SIZE]; }
    void debugShow() {for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i].v << " ";cerr << "\n";}
};
