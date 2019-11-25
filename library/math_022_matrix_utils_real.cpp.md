<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
  jax: ["input/TeX", "output/HTML-CSS"],
  tex2jax: {
    inlineMath: [ ['$', '$'] ],
    displayMath: [ ['$$', '$$']],
    processEscapes: true,
    skipTags: ['script', 'noscript', 'style', 'textarea', 'pre', 'code']
  },
  messageStyle: "none",
  "HTML-CSS": { preferredFont: "TeX", availableFonts: ["STIX","TeX"] }
});
</script>
<script src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML" type="text/javascript"></script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: math\_022\_matrix\_utils\_real.cpp

## Code

```cpp
// 実数行列に対する主要な操作

// ガウスの消去法 (元の行列を参照で変形、ランクを返す)
template <typename Real>
int gaussianEliminationReal(Matrix<Real> &mat,
                            const Real EPS=1e-9, bool ext=false) {
    int N = mat.size(), M = mat[0].size(), rank = 0;

    // 拡大係数行列なら最後の列は掃き出しの対象にしない
    for(int j=0; j+ext<M; j++) {
        int piv = -1; Real abs_max(0.0);
        for(int i=rank; i<N; i++) {
            Real val(abs(mat[i][j]));
            if(val >= EPS and abs_max < val) abs_max = val, piv = i;
        }
        if(piv < 0) continue;
        swap(mat[rank], mat[piv]);
        Real div(mat[rank][j]);
        for(auto &v : mat[rank]) v /= div;
        for(int i=0; i<N; i++) {
            if(i == rank or abs(mat[i][j]) < EPS) continue;
            Real scale = mat[i][j];
            for(int k=0; k<M; k++) {
                mat[i][k] -= mat[rank][k] * scale;
            }
        }
        rank++;
    }
    return rank;
}

// 線形方程式を解く
// empty なら解なし、M != rank なら無限に存在、そうでなければ一意
template <typename Real>
vector<Real> linearEquationReal(Matrix<Real> A, vector<Real> b,
                                const Real EPS = 1e-9) {
    int N = A.size(), M = A[0].size();
    Matrix<Real> mat(N, M+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M+1; j++) {
            mat[i][j] = (j < M ? A[i][j] : b[i]);
        }
    }

    int rank = gaussianEliminationReal(mat, EPS, true);
    vector<Real> res(N);
    for(int i=0; i<N; i++) {
        res[i] = mat[i][M];
        if(i >= rank and abs(mat[i][M]) > EPS) return {};
    }
    return res;
}

template <typename Real>
Real detReal(Matrix<Real> A, const Real EPS=1e-9) {
    int N = A.size(), cnt_swap = 0;
    for(int j=0; j<N; j++) {
        int piv = -1; Real abs_max(0);
        for(int i=j; i<N; i++) {
            Real val = abs(A[i][j]);
            if(val >= EPS and abs_max < val) abs_max = val, piv = i;
        }
        if(piv < 0) return Real(0);
        cnt_swap += (piv != j);
        swap(A[piv], A[j]);
        for(int i=j+1; i<N; i++) {
            Real scale(A[i][j] / A[j][j]);
            for(int k=0; k<N; k++) {
                A[i][k] -= A[j][k] * scale;
            }
        }
    }

    Real res = (cnt_swap % 2 ? Real(-1) : Real(1));
    for(int i=0; i<N; i++) res *= A[i][i];
    return res;
}

```

[トップページに戻る](../index.html)
