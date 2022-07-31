#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

struct INIT{
    INIT(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
}INIT;

template<typename T>struct segment_tree {
    using F = function<T(T, T)>;

    int n;
    vector<T> node;
    F combine; // 区間の演算
    T identify; // 単位元

    //扱う配列がすでにできている場合
    segment_tree(vector<T> v, F _combine, T _identity) : combine(_combine),  identify(_identity) {
        int sz = (int)v.size();
        n = 1;
        while(n < sz)n *= 2;
        node.resize(2 * n - 1, identify);

        for(int i = 0;i < sz;i++)node[i + n - 1] = v[i];
        for(int i = n - 2;i >= 0;i--)node[i] = combine(node[2 * i + 1], node[2 * i + 2]);
    }

    //空のものからやっていく場合
    segment_tree(int _n, F _combine, T _identify) : combine(_combine), identify(_identify){
        int sz = _n;
        n = 1;
        while(n < sz)n *= 2;
        node.resize(2 * n - 1, identify);
    }

    T operator[](int x) {return node[x + n - 1]; }

    void set(int x, T val){
        x += (n - 1);

        node[x] = val;
        while(x > 0){
            x = (x - 1) / 2;
            node[x] = combine(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    T fold(int a, int b, int k = 0, int l = 0, int r = -1){
        //最初に呼び出された時の対象区間は [0, n)
        if(r < 0) r = n;

        //要求区間と対象区間が交わらない -> 適当に（単位元を）返す
        if(r <= a || b <= l)return identify;
        
        //要求区間が対象区間と完全被覆 -> 対象区間を答えの計算に使う
        if(a <= l && r <= b)return node[k];

        //要求区間が対象区間の一部を被覆 -> 子についての探索を行う
        T vl = fold(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = fold(a, b, 2 * k + 2, (l + r) / 2, r);
        return combine(vl, vr);
    }
};

int n;

map<int, int> ca, cb;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
}

int main(){
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> va, vb;
    REP(i, n)cin >> v[i].first;
    REP(i, n)cin >> v[i].second;
    REP(i, n){
        va.emplace_back(v[i].first);
        vb.emplace_back(v[i].second);
    }
    UNIQUE(va);
    UNIQUE(vb);
    REP(i, (int)va.size())ca[va[i]] = i;
    REP(i, (int)vb.size())cb[vb[i]] = i;
    REP(i, n){
        v[i].first = ca[v[i].first];
        v[i].second = cb[v[i].second];
    }
    
    sort(ALL(v), cmp);
    
    LL ans = 0;

    vector<pair<pair<int, int>, int>> vp;
    REP(i, n){
        if(i && vp.back().first == v[i]){
            vp.back().second++;
        }else{
            vp.emplace_back(make_pair(v[i], 1));
        }
    }

    auto combine_sum = [](LL a, LL b){return a + b;};
    segment_tree<LL> seg(n, combine_sum, 0);

    REP(i, (int)vp.size()){
        int a = vp[i].first.first, b = vp[i].first.second;
        int num = vp[i].second;
        seg.set(b, seg[b] + num);
        ans += seg.fold(b, n) * num;
    }

    cout << ans << endl;

}