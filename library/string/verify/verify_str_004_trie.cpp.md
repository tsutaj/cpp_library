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


# :warning: string/verify/verify_str_004_trie.cpp
<a href="../../../index.html">Back to top page</a>

* category: string/verify
* <a href="{{ site.github.repository_url }}/blob/master/string/verify/verify_str_004_trie.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Depends On
* :warning: <a href="../str_004_trie.cpp.html">string/str_004_trie.cpp</a>


## Code
{% raw %}
```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <functional>
using namespace std;
#include "../str_004_trie.cpp"

void tiny_test() {
    trie<26, 'a'> tr;
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        tr.add(s);
    }

    int K;
    while(cin >> K) {
        cout << tr.kth_string(K) << endl;
    }
}

int main() {
    tiny_test();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

