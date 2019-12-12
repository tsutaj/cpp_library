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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/math_007_fraction.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/math_007_fraction.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// fraction library (use C++11)
struct fraction{
    // init (nume / deno)
    int numerator, denominator;
    fraction(int i) : numerator(i), denominator(1) {}
    fraction(int i, int j) : numerator(i), denominator(j) {}
    fraction(string s) {
        int i = s.find('/');
        if(i != string::npos) {
            numerator = atoi(s.substr(0,i).c_str());
            denominator = atoi(s.substr(i+1).c_str());
        }
        else {
            numerator = atoi(s.c_str());
            denominator = 1;
        }
    }

    fraction fixshape(fraction A) {
        int p = A.denominator, q = A.numerator;
        if(p < 0) {p *= -1; q *= -1;}
        int k = gcd(abs(p), abs(q));
        p /= k, q /= k;
        A.denominator = p, A.numerator = q;
        return A;
    }
};

// print fraction
string printfrac(fraction A, int n) {
    if(!n) return to_string(A.numerator) + "/" + to_string(A.denominator);
    else {
        if(A.denominator == 1) return to_string(A.numerator);
        else return printfrac(A, 0);
    }
}

string printfrac(fraction A) {
    if(A.denominator == 1) return to_string(A.numerator);
    else return printfrac(A, 0);
}

void simplify(fraction &A, fraction &B) {
    int k = lcm(A.denominator, B.denominator);
    A.numerator *= (k / A.denominator);
    B.numerator *= (k / B.denominator);
    A.denominator = k; B.denominator = k;
}

// overloading the arithmetic operators
fraction operator+(const fraction &A, const fraction &B) {
    int q = lcm(A.denominator, B.denominator);
    int p = A.numerator * (q / A.denominator) + B.numerator * (q / B.denominator);
    fraction ret = ret.fixshape(fraction(p, q));
    return ret;
}

fraction operator-(const fraction &A, const fraction &B) {
    int q = lcm(A.denominator, B.denominator);
    int p = A.numerator * (q / A.denominator) - B.numerator * (q / B.denominator);
    fraction ret = ret.fixshape(fraction(p, q));
    return ret;
}

fraction operator*(const fraction &A, const fraction &B) {
    int p = A.numerator * B.numerator;
    int q = A.denominator * B.denominator;
    int k = gcd(abs(p), abs(q));
    p /= k, q /= k;
    fraction ret = ret.fixshape(fraction(p, q));
    return ret;
}

fraction operator/(const fraction &A, const fraction &B) {
    fraction C = C.fixshape(fraction(B.denominator, B.numerator));
    fraction ret = ret.fixshape(A*C);
    return ret;
}

bool operator<(const fraction &A, const fraction &B) {
    fraction C = A, D = B;
    simplify(C, D);
    return C.numerator < D.numerator;
}

bool operator>(const fraction &A, const fraction &B) {
    fraction C = A, D = B;
    simplify(C, D);
    return C.numerator > D.numerator;
}
// fraction library end
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

