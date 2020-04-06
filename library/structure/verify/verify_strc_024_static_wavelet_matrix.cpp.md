---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: structure/verify/verify_strc_024_static_wavelet_matrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_024_static_wavelet_matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 00:46:27+09:00




## Depends on

* :heavy_check_mark: <a href="../strc_023_compact_bitvector.cpp.html">簡潔ビットベクトル (compact bit vector)</a>
* :heavy_check_mark: <a href="../strc_024_static_wavelet_matrix.cpp.html">Wavelet 行列 (wavelet matrix)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <array>
#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <tuple>
#include <utility>
using namespace std;
#include "../strc_023_compact_bitvector.cpp"
#include "../strc_024_static_wavelet_matrix.cpp"

int main() {
    vector<int> vec = {2, 10, 2, 3, 2, 5, 4, 4};
    WaveletMatrix<4> wm(vec);
    
    for(size_t i=0; i<vec.size(); i++) {
        cerr << wm[i] << " ";
    }
    cerr << endl;

    while(true) {
        // int k, x; cin >> k >> x; k--;
        // cout << wm.rank_idx(k, x) << endl;
        int l, r, k, x; cin >> l >> r >> k >> x; l--;
        cout << wm.select(l, r, k, x) << endl;
        // cout << res << endl;
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 170, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: structure/strc_024_static_wavelet_matrix.cpp: line 7: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

