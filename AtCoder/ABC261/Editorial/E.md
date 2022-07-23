# E - Many Operations 

## 解説

$2$ 進数の各位ごとに

- $j$ 桁目が $0$ だったとき，操作 $1, 2, \cdots , i - 1$ を行った結果
- $j$ 桁目が $1$ だったとき，操作 $1, 2, \cdots , i - 1$ を行った結果
をメモしておく

```C++
int n;
int t[202020];
LL a[202020];
LL c;

bool ansbit[30];

bool ruibit[202020][30][2];

int main(){
    cin >> n >> c;
    REP(i, 30){
        if(c & (1LL << i))ansbit[i] = 1;
    }
    REP(i, n){
        cin >> t[i] >> a[i];
        vector<bool> abit(30, 0);
        REP(j, 30)if(a[i] & (1LL << j))abit[j] = 1;
        if(!i){
            REP(j, 30){
                if(t[i] == 1)ruibit[i][j][0] = (0 & abit[j]), ruibit[i][j][1] = (1 & abit[j]);
                if(t[i] == 2)ruibit[i][j][0] = (0 | abit[j]), ruibit[i][j][1] = (1 | abit[j]);
                if(t[i] == 3)ruibit[i][j][0] = (0 ^ abit[j]), ruibit[i][j][1] = (1 ^ abit[j]);
            }
            REP(j, 30){
                ansbit[j] = ruibit[i][j][ansbit[j]];
            }
        }else{
            REP(j, 30)REP(k, 2){
                if(t[i] == 1)ruibit[i][j][k] = (ruibit[i - 1][j][k] & abit[j]);
                if(t[i] == 2)ruibit[i][j][k] = (ruibit[i - 1][j][k] | abit[j]);
                if(t[i] == 3)ruibit[i][j][k] = (ruibit[i - 1][j][k] ^ abit[j]);
            }
            REP(j, 30){
                ansbit[j] = ruibit[i][j][ansbit[j]];
            }
        }
        LL tmp = 0;
        REP(j, 30){
            if(ansbit[j])tmp += (1LL << j);
        }
        cout << tmp << endl;
    }
}
```