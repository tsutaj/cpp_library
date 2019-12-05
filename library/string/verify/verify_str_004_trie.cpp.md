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
<script type="text/javascript" src="../../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: ../../string/verify/verify_str_004_trie.cpp
* category: ../../string/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [../../string/str_004_trie.cpp](../str_004_trie.cpp.html)


## Code
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

[Back to top page](../../../index.html)
