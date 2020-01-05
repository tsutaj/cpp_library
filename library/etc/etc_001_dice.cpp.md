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


# :warning: etc/etc_001_dice.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e80f17310109447772dca82b45ef35a5">etc</a>
* <a href="{{ site.github.repository_url }}/blob/master/etc/etc_001_dice.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Dice library
//         ---------
//         | back  |
//         |  (5)  |
// --------+-------+-------+--------+
// | left  |  top  | right | bottom |
// |  (4)  |  (1)  |  (2)  |   (3)  |
// --------+-------+-------+---------
//         | front |
//         |  (0)  |
//         ---------

enum Direction {
    // 北、南、東、西方向 および 右、左回り に 90 度回転
    NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3, ROT_R = 4, ROT_L = 5,
};

enum View {
    // どこから見た時の値か？
    FRONT = 0, TOP = 1, RIGHT = 2, BOTTOM = 3, LEFT = 4, BACK = 5,
};

struct Dice {
    vector<int> value;
    Dice(int front, int top, int right) {
        int sum = 7;
        assert(front + top   != sum);
        assert(top   + right != sum);
        assert(front + right != sum);
        value = {front, top, right, sum-top, sum-right, sum-front};
    }

    void rotate(int dir) {
        vector<int> fnc, swp(6);
        if(dir == NORTH) fnc = {1, 5, 2, 0, 4, 3};
        if(dir == SOUTH) fnc = {3, 0, 2, 5, 4, 1};
        if(dir == EAST ) fnc = {0, 2, 3, 4, 1, 5};
        if(dir == WEST ) fnc = {0, 4, 1, 2, 3, 5};
        if(dir == ROT_R) fnc = {4, 1, 0, 3, 5, 2};
        if(dir == ROT_L) fnc = {2, 1, 5, 3, 0, 4};

        for(int i=0; i<6; i++) swp[ fnc[i] ] = value[i];
        swap(value, swp);
    }

    int get_value(int view) {
        return value[view];
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "etc/etc_001_dice.cpp"
// Dice library
//         ---------
//         | back  |
//         |  (5)  |
// --------+-------+-------+--------+
// | left  |  top  | right | bottom |
// |  (4)  |  (1)  |  (2)  |   (3)  |
// --------+-------+-------+---------
//         | front |
//         |  (0)  |
//         ---------

enum Direction {
    // 北、南、東、西方向 および 右、左回り に 90 度回転
    NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3, ROT_R = 4, ROT_L = 5,
};

enum View {
    // どこから見た時の値か？
    FRONT = 0, TOP = 1, RIGHT = 2, BOTTOM = 3, LEFT = 4, BACK = 5,
};

struct Dice {
    vector<int> value;
    Dice(int front, int top, int right) {
        int sum = 7;
        assert(front + top   != sum);
        assert(top   + right != sum);
        assert(front + right != sum);
        value = {front, top, right, sum-top, sum-right, sum-front};
    }

    void rotate(int dir) {
        vector<int> fnc, swp(6);
        if(dir == NORTH) fnc = {1, 5, 2, 0, 4, 3};
        if(dir == SOUTH) fnc = {3, 0, 2, 5, 4, 1};
        if(dir == EAST ) fnc = {0, 2, 3, 4, 1, 5};
        if(dir == WEST ) fnc = {0, 4, 1, 2, 3, 5};
        if(dir == ROT_R) fnc = {4, 1, 0, 3, 5, 2};
        if(dir == ROT_L) fnc = {2, 1, 5, 3, 0, 4};

        for(int i=0; i<6; i++) swp[ fnc[i] ] = value[i];
        swap(value, swp);
    }

    int get_value(int view) {
        return value[view];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

