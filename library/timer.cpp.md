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

# :warning: timer.cpp

## Code

```cpp
class Timer {
    chrono::high_resolution_clock::time_point start, end;
    double limit;

public:
    Timer() {
        start = chrono::high_resolution_clock::now();
    }
    Timer(double l) {
        start = chrono::high_resolution_clock::now();
        limit = l;
    }

    double getTime() {
        end = chrono::high_resolution_clock::now();
        return chrono::duration<double>(end - start).count();
    }

    bool isTimeOver() {
        if (getTime() > limit) {
            return true;
        }
        return false;
    }

    double getLimit() { return limit; }
    void setLimit(double l) {
        limit = l;
    }
    void setStart() { start = chrono::high_resolution_clock::now(); }
};

```

[トップページに戻る](../index.html)