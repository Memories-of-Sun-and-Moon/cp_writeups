# D - Draw Your Cards

## 解説

シミュレート。 set で {山の一番上, カードの枚数} の情報を管理する。

重ねた親のカードと今のカードを関連付けることで、カードを食べたターンの処理をする。

```C++
int n, k;
int p[202020];
int ans[202020];
int par[202020];
set<pair<int, int>> st;

int main(){
    cin >> n >> k;
    REP(i, n)cin >> p[i];

    if(k == 1){
        REP(i, n){
            ans[p[i]] = i + 1;
        }
        for(int i = 1;i <= n;i++){
            cout << ans[i] << endl;
        }
        return 0;
    }

    REP(i, 202020)par[i] = -1;
    REP(i, 202020)ans[i] = -1;
    REP(i, n){
        auto it = st.lower_bound({p[i], 0});
        if(it == st.end()){
            st.insert({p[i], 1});
        }else{
            par[p[i]] = it->first;
            int sz = it->second + 1;
            st.erase(it);
            if(sz == k){
                int cur = p[i];
                while(cur != -1){
                    ans[cur] = i + 1;
                    cur = par[cur];
                }
            }else{
                st.insert({p[i], sz});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout << ans[i] << endl;
    }
}
```
