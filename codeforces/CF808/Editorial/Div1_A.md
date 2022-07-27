# Doremy's IQ

## 解説

逆から考えることで，貪欲法で解くことができる．

終了時，$q$ が $0$ であると仮定し，$a_i$ を後ろから見ていく．

- この時点で $q \geq a_i$ 以上ならば，その問題を解く
- そうでないならば，この問題を解き， $q$ に $1$ 加算する．
- $q$ が，与えられた $q$ と同じになった時
  - $q \geq a_i$ ならば，その問題を解く
  - そうでないならば，何もしない

```C++
int n, q;
int a[101010];
void solve(){
    cin >> n >> q;
    REP(i, n){
        cin >> a[i];
    }
    vector<int> ans(n, 0);
    int iq = 0;
    for(int i = n - 1;i >= 0;i--){
        if(iq != q){
            if(iq >= a[i])ans[i] = 1;
            else{
                ans[i] = 1;
                iq++;
            }
        }else{
            if(q >= a[i])ans[i] = 1;
        }
    }
    REP(i, n)cout << ans[i];
    cout << endl;
}

int t;

int main(){
    cin >> t;
    while(t--)solve();
}
```
