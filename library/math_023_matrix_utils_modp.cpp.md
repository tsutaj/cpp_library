<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: math\_023\_matrix\_utils\_modp.cpp
---

## Code

```cpp
// mod p 行列に対する主要な操作
// 実数じゃないので絶対値最大のものを pivot にするとかがいらない

// ガウスの消去法
template <typename mint>
int gaussianEliminationModp(Matrix<mint> &mat, bool ext=false) {
    int N = mat.size(), M = mat[0].size(), rank = 0;
    for(int j=0; j+ext<M; j++) {
        int piv = -1;
        for(int i=rank; i<N; i++) {
            if(mat[i][j] != mint(0)) piv = i, i = N;
        }
        if(piv < 0) continue;
        swap(mat[rank], mat[piv]);
        mint div(mat[rank][j]);
        for(auto &v : mat[rank]) v /= div;
        for(int i=0; i<N; i++) {
            if(i == rank or mat[i][j] == mint(0)) continue;
            mint scale = mat[i][j];
            for(int k=0; k<M; k++) {
                mat[i][k] -= mat[rank][k] * scale;
            }
        }
        rank++;
    }
    return rank;
}

template <typename mint>
vector<mint> linearEquationModp(Matrix<mint> A, vector<mint> b) {
    int N = A.size(), M = A[0].size();
    Matrix<mint> mat(N, M+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M+1; j++) {
            mat[i][j] = (j < M ? A[i][j] : b[i]);
        }
    }

    int rank = gaussianEliminationModp(mat, true);
    vector<mint> res(N);
    for(int i=0; i<N; i++) {
        res[i] = mat[i][M];
        if(i >= rank and mat[i][M] != mint(0)) return {};
    }
    return res;
}

template <typename mint>
mint detModp(Matrix<mint> A) {
    int N = A.size(), cnt_swap = 0;
    for(int j=0; j<N; j++) {
        int piv = -1;
        for(int i=j; i<N; i++) {
            if(A[i][j] != mint(0)) piv = i, i = N;
        }
        if(piv < 0) return mint(0);
        cnt_swap += (piv != j);
        swap(A[piv], A[j]);
        for(int i=j+1; i<N; i++) {
            mint scale(A[i][j] / A[j][j]);
            for(int k=0; k<N; k++) {
                A[i][k] -= A[j][k] * scale;
            }
        }
    }

    mint res = (cnt_swap % 2 ? mint(-1) : mint(1));
    for(int i=0; i<N; i++) res *= A[i][i];
    return res;
}

```

[トップページに戻る](../index.html)
