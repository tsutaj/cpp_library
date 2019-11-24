[トップページに戻る](../index.html)

# etc\_001\_dice.cpp
---

## Code

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

[トップページに戻る](../index.html)
