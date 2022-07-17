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

int n, m;
int a[202020], b[202020];


int ans[202020];
vector<int> nuke[202020];

int main(){
    cin >> n >> m;
    int maxa = -1, minb = 202020;
    REP(i, n){
        cin >> a[i] >> b[i];
        nuke[a[i]].push_back(i);
        chmax(maxa, a[i]);
        chmin(minb, b[i]);
    }

    int maxb = -1;

    for(int i = 1;i <= minb;i++){
        ans[max(maxa, maxb) - i + 1]++;
        ans[min(m + 1, m - i + 2)]--;

        // i が抜けた後の処理
        REP(j, (int)nuke[i].size()){
            chmax(maxb, b[nuke[i][j]]);
        }
    }
    for(int i = 1;i <= m;i++){
        ans[i] += ans[i - 1];
    }
    for(int i = 1;i <= m;i++){
        if(i >= 2)cout << " ";
        cout << ans[i];
    }
    cout << endl;
}