---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"etc/etc_001_dice.cpp\"\n// Dice library\n//         ---------\n\
    //         | back  |\n//         |  (5)  |\n// --------+-------+-------+--------+\n\
    // | left  |  top  | right | bottom |\n// |  (4)  |  (1)  |  (2)  |   (3)  |\n\
    // --------+-------+-------+---------\n//         | front |\n//         |  (0)\
    \  |\n//         ---------\n\nenum Direction {\n    // \u5317\u3001\u5357\u3001\
    \u6771\u3001\u897F\u65B9\u5411 \u304A\u3088\u3073 \u53F3\u3001\u5DE6\u56DE\u308A\
    \ \u306B 90 \u5EA6\u56DE\u8EE2\n    NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3,\
    \ ROT_R = 4, ROT_L = 5,\n};\n\nenum View {\n    // \u3069\u3053\u304B\u3089\u898B\
    \u305F\u6642\u306E\u5024\u304B\uFF1F\n    FRONT = 0, TOP = 1, RIGHT = 2, BOTTOM\
    \ = 3, LEFT = 4, BACK = 5,\n};\n\nstruct Dice {\n    vector<int> value;\n    Dice(int\
    \ front, int top, int right) {\n        int sum = 7;\n        assert(front + top\
    \   != sum);\n        assert(top   + right != sum);\n        assert(front + right\
    \ != sum);\n        value = {front, top, right, sum-top, sum-right, sum-front};\n\
    \    }\n\n    void rotate(int dir) {\n        vector<int> fnc, swp(6);\n     \
    \   if(dir == NORTH) fnc = {1, 5, 2, 0, 4, 3};\n        if(dir == SOUTH) fnc =\
    \ {3, 0, 2, 5, 4, 1};\n        if(dir == EAST ) fnc = {0, 2, 3, 4, 1, 5};\n  \
    \      if(dir == WEST ) fnc = {0, 4, 1, 2, 3, 5};\n        if(dir == ROT_R) fnc\
    \ = {4, 1, 0, 3, 5, 2};\n        if(dir == ROT_L) fnc = {2, 1, 5, 3, 0, 4};\n\n\
    \        for(int i=0; i<6; i++) swp[ fnc[i] ] = value[i];\n        swap(value,\
    \ swp);\n    }\n\n    int get_value(int view) {\n        return value[view];\n\
    \    }\n};\n"
  code: "// Dice library\n//         ---------\n//         | back  |\n//         |\
    \  (5)  |\n// --------+-------+-------+--------+\n// | left  |  top  | right |\
    \ bottom |\n// |  (4)  |  (1)  |  (2)  |   (3)  |\n// --------+-------+-------+---------\n\
    //         | front |\n//         |  (0)  |\n//         ---------\n\nenum Direction\
    \ {\n    // \u5317\u3001\u5357\u3001\u6771\u3001\u897F\u65B9\u5411 \u304A\u3088\
    \u3073 \u53F3\u3001\u5DE6\u56DE\u308A \u306B 90 \u5EA6\u56DE\u8EE2\n    NORTH\
    \ = 0, SOUTH = 1, EAST = 2, WEST = 3, ROT_R = 4, ROT_L = 5,\n};\n\nenum View {\n\
    \    // \u3069\u3053\u304B\u3089\u898B\u305F\u6642\u306E\u5024\u304B\uFF1F\n \
    \   FRONT = 0, TOP = 1, RIGHT = 2, BOTTOM = 3, LEFT = 4, BACK = 5,\n};\n\nstruct\
    \ Dice {\n    vector<int> value;\n    Dice(int front, int top, int right) {\n\
    \        int sum = 7;\n        assert(front + top   != sum);\n        assert(top\
    \   + right != sum);\n        assert(front + right != sum);\n        value = {front,\
    \ top, right, sum-top, sum-right, sum-front};\n    }\n\n    void rotate(int dir)\
    \ {\n        vector<int> fnc, swp(6);\n        if(dir == NORTH) fnc = {1, 5, 2,\
    \ 0, 4, 3};\n        if(dir == SOUTH) fnc = {3, 0, 2, 5, 4, 1};\n        if(dir\
    \ == EAST ) fnc = {0, 2, 3, 4, 1, 5};\n        if(dir == WEST ) fnc = {0, 4, 1,\
    \ 2, 3, 5};\n        if(dir == ROT_R) fnc = {4, 1, 0, 3, 5, 2};\n        if(dir\
    \ == ROT_L) fnc = {2, 1, 5, 3, 0, 4};\n\n        for(int i=0; i<6; i++) swp[ fnc[i]\
    \ ] = value[i];\n        swap(value, swp);\n    }\n\n    int get_value(int view)\
    \ {\n        return value[view];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: etc/etc_001_dice.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: etc/etc_001_dice.cpp
layout: document
redirect_from:
- /library/etc/etc_001_dice.cpp
- /library/etc/etc_001_dice.cpp.html
title: etc/etc_001_dice.cpp
---
