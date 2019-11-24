[トップページに戻る](../index.html)

# math\_021\_crt.cpp
---

## Code

```cpp
// 中国剰余定理
// x = b_1 (mod_1), ..., x = b_k (mod_k), ... を満たす x を
// 0 <= x < lcm(mod_1, mod_2, ..., mod_k, ...) の範囲で求める

template <typename NumType, NumType LIMIT = NumType(1e10)>
struct CRT {
    pair<NumType, NumType> NIL;
    CRT() : NIL(-1, -1) {}
    
    NumType extgcd(NumType a, NumType b, NumType &p, NumType &q) {
        if(b == 0) {
            p = 1, q = 0;
            return a;
        }
        NumType d = extgcd(b, a%b, q, p);
        q -= a / b * p;
        return d;
    }

    pair<NumType, NumType> solve(NumType b1, NumType mod1, NumType b2, NumType mod2) {
        NumType p, q;
        NumType d = extgcd(mod1, mod2, p, q);
        
        if((b2 - b1) % d != 0) return NIL;
        NumType s = (b2 - b1) / d;
        NumType t = (s * p % (mod2 / d));

        // get lcm
        NumType lc = mod1 / d * mod2;
        NumType so = (b1 + mod1 * t) % lc;
        (so += lc) %= lc;
        return make_pair(so, lc);
    }

    // m, mod の vector をもらって、
    // CRT の解を (x, lcm(mod_1, mod_2, ..., mod_k, ...)) の形で返す
    pair<NumType, NumType> solve(vector<NumType> m, vector<NumType> mod) {
        assert(m.size() == mod.size());
        NumType so = 0, lc = 1;
        for(size_t i=0; i<m.size(); i++) {
            tie(so, lc) = solve(so, lc, m[i], mod[i]);
            if(so > LIMIT or so < 0) {
                return NIL;
            }
        }
        return make_pair(so, lc);
    }
};

```

[トップページに戻る](../index.html)
