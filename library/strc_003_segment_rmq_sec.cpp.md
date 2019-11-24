[トップページに戻る](../index.html)

# strc\_003\_segment\_rmq\_sec.cpp
---

## Code

```cpp
// 次の2つのクエリに対応するRMQ
// ・[a, b) の要素全てに x を加えるクエリ
// ・[a, b) の和を計算するクエリ
// (strc_006_bit_sec.cpp に BIT 版があり、そちらの方が速いです)
// Verify: なし (POJ の問題が TLE した)

template <typename T>
class rmq_sec {
public:
    vector<T> data, datb;
    rmq_sec(int n_) {
        int m = 1; while(m < n_) m *= 2;
        data.resize(2*m-1);
        datb.resize(2*m-1);
    }

    void add(int a, int b, int x, int k, int l, int r) {
        if(a <= l && r <= b) {
            data[k] += x;
        }
        else if(l < b && a < r) {
            datb[k] += (min(b, r) - max(a, l)) * x;
            add(a, b, x, k*2 + 1, l, (l + r) / 2);
            add(a, b, x, k*2 + 2, (l + r) / 2, r);
        }
    }

    ll sum(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a) {
            return 0;
        }
        else if(a <= l && r <= b) {
            return data[k] * (r - l) + datb[k];
        }
        else {
            ll res = (min(b, r) - max(a, l)) * data[k];
            res += sum(a, b, k*2 + 1, l, (l + r) / 2);
            res += sum(a, b, k*2 + 2, (l + r) / 2, r);
            return res;
        }
    }
};
```

[トップページに戻る](../index.html)
