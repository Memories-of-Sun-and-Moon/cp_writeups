# E - At Least One

## 解説

良い数列の要素のうち、一番小さい数字を $L$ 、一番大きい数字を $R$ とする。 $L$ を $1$ から順に固定して考える。

例えば、 $L$ が $1$ の時、 $R$ は $max(A_i)$ 以上であればなんでもいい。

$L$ がとある値 $K$ の時、 $R$ は $min(max(A_i), max(B_j))$ （ただし、 $(j : A_j < K)$）以上であればなんでもいい。

このように、 $L$ を小さい値から順に走査していくことで、それぞれで可能な文字長の範囲がわかるので、あとはいもす法で答えを出す。

（尺取り法克服のために尺取り法でも実装する...？）

```C++
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
```
