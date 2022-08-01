# Range Sums

## 解説

半開区間で考えたほうが楽なので，入力で与えられた $L, R$ を以下のように解釈する（以後， 0-indexed で考える）

$(l_i, r_i)$ := $[L_i - 1, R_i)$

union-find で $(l_i, r_i)$ に辺を結んで，最終的に $(0, n)$ が結ばれるかどうかを判定すればよい．

```C++
int n, q;
int l[202020], r[202020];

int main(){
    cin >> n >> q;
    UnionFind uf(n + 1);
    REP(i, q){
        cin >> l[i] >> r[i];
        l[i]--;
        uf.unite(l[i], r[i]);
    }

    cout << (uf.same(0, n) ? "Yes" : "No") << endl;
}
```
