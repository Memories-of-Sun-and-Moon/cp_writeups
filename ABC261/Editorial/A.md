# A - Intersection

## 解説

$max(0, min(L_1, L_2) - max(R_1, R_2))$

あるいは単純に実装（入力で与えられているものは，すべて区間上の一点であることに注意）

```C++
bool isred[101], isblue[101];

int main(){
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r;i++)isred[i] = true;
    cin >> l >> r;
    for(int i = l; i <= r;i++)isblue[i] = true;
    int cnt =0;
    for(int i = 0;i <= 100;i++)if(isred[i] && isblue[i])cnt++;
    cout << max(0, cnt - 1) << endl;
}
```
