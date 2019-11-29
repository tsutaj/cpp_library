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
<script type="text/javascript" src="../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: ../../marathon/timer.cpp
* category: ../../marathon


[Back to top page](../../index.html)



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

[Back to top page](../../index.html)

