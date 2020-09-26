---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/strc_010_abst_sqrtdecomp.cpp\"\n#include <cstdio>\n\
    #include <vector>\n#include <climits>\nusing namespace std;\nusing ll = long long\
    \ int;\n\ntemplate<typename Type>\nstruct SqrtDecomp {\n    int SIZE;\n    vector<Type>\
    \ node, bucket, lazy, need_upd;\n    Type (*op1) (Type x, Type y, int sz);\n \
    \   Type (*op2) (Type x, Type y);\n    Type I_op1, I_op2;\n\n    SqrtDecomp( vector<Type>\
    \ vec,\n                Type (*g_op1) (Type x, Type y, int sz),\n            \
    \    Type (*g_op2) (Type x, Type y),\n                Type X_op1, Type X_op2)\
    \ {\n        int N = vec.size();\n        SIZE = 1; while(SIZE * SIZE < N) SIZE++;\n\
    \        op1 = g_op1, op2 = g_op2;\n        I_op1 = X_op1, I_op2 = X_op2;\n\n\
    \        node.resize(SIZE*SIZE, I_op2);\n        bucket.resize(SIZE, I_op2);\n\
    \        lazy.resize(SIZE, I_op1);\n        need_upd.resize(SIZE, 0);\n\n    \
    \    for(int i=0; i<SIZE; i++) {\n            Type rep_val = I_op2;\n        \
    \    for(int j=0; j<SIZE && i*SIZE+j<N; j++) {\n                int idx = (i*SIZE\
    \ + j);\n                node[idx] = vec[idx];\n                rep_val = op2(rep_val,\
    \ node[idx]);\n            }\n            bucket[i] = rep_val;\n        }\n  \
    \  }\n\n    void lazy_eval(int k) {\n        int l = SIZE*k, r = SIZE*(k+1);\n\
    \        if(need_upd[k]) {\n            Type seg_val = I_op2;\n\n            //\
    \ \u8A72\u5F53\u3059\u308B\u4E0B\u306E\u30CE\u30FC\u30C9\u3092\u307E\u305A\u66F4\
    \u65B0\n            for(int i=l; i<r; i++) {\n                node[i] = op1(node[i],\
    \ lazy[k], 1);\n                seg_val = op2(seg_val, node[i]);\n           \
    \ }\n\n            // \u4E0A\u306E\u30CE\u30FC\u30C9\u3092\u66F4\u65B0\n     \
    \       bucket[k] = seg_val;\n        }\n        lazy[k] = I_op1;\n        need_upd[k]\
    \ = false;\n    }\n\n    void update(int l, int r, Type val) {\n        int lidx\
    \ = l / SIZE, ridx = r / SIZE;\n        // \u5DE6\u7AEF\u306E\u66F4\u65B0\n  \
    \      lazy_eval(lidx);\n        bucket[lidx] = I_op2;\n        for(int k=SIZE*lidx;\
    \ k<SIZE*(lidx+1); k++) {\n            if(l <= k && k < r) node[k] = op1(node[k],\
    \ val, 1);\n            bucket[lidx] = op2(bucket[lidx], node[k]);\n        }\n\
    \n        if(lidx != ridx) {\n            // \u771F\u3093\u4E2D (lazy \u3092\u66F4\
    \u65B0)\n            for(int k=lidx+1; k<ridx; k++) {\n                lazy[k]\
    \ = op1(lazy[k], val, 1);\n                need_upd[k] = true;\n            }\n\
    \n            if(ridx != SIZE) {\n                lazy_eval(ridx);\n         \
    \       bucket[ridx] = I_op2;\n\n                // \u53F3\u7AEF\u306E\u66F4\u65B0\
    \n                for(int k=SIZE*ridx; k<SIZE*(ridx+1); k++) {\n             \
    \       if(k < r) node[k] = op1(node[k], val, 1);\n                    bucket[ridx]\
    \ = op2(bucket[ridx], node[k]);\n                }\n            }\n        }\n\
    \    }\n\n    Type query(int l, int r) {\n        int lidx = l / SIZE, ridx =\
    \ r / SIZE;\n        Type ret = I_op2;\n        \n        // \u5DE6\u7AEF\u306E\
    \u53D6\u5F97\n        for(int k=l; k<min(r, SIZE*(lidx+1)); k++) {\n         \
    \   lazy_eval(lidx);\n            ret = op2(ret, node[k]);\n        }\n\n    \
    \    if(lidx != ridx) {\n            for(int k=lidx+1; k<ridx; k++) {\n      \
    \          // \u5168\u4F53\u306E\u5024\u3068 lazy \u306E\u5024\u3092\u8003\u616E\
    \u3057\u3066\u5024\u3092\u8A08\u7B97\n                Type val = (need_upd[k]\
    \ ? op1(bucket[k], lazy[k], SIZE) : bucket[k]);\n                ret = op2(ret,\
    \ val);\n            }\n\n            for(int k=SIZE*ridx; k<r; k++) {\n     \
    \           lazy_eval(ridx);\n                ret = op2(ret, node[k]);\n     \
    \       }\n        }\n\n        return ret;\n    }\n\n    /*\n    void print_debug()\
    \ {\n        printf(\"<< node >>\\n\");\n        printf(\"upper bucket:\\n\");\n\
    \        for(int i=0; i<SIZE; i++) {\n            int l = SIZE*i, r = SIZE*(i+1);\n\
    \            printf(\"[%6d, %6d) -> %lld\\n\", l, r, bucket[i]);\n        }\n\
    \        printf(\"lower bucket:\\n\");\n        for(int i=0; i<SIZE*SIZE; i++)\
    \ {\n            printf(\"[%6d, %6d) -> %lld\\n\", i, i+1, node[i]);\n       \
    \ }\n\n        printf(\"<< lazy >>\\n\");\n        printf(\"upper bucket:\\n\"\
    );\n        for(int i=0; i<SIZE; i++) {\n            int l = SIZE*i, r = SIZE*(i+1);\n\
    \            printf(\"[%6d, %6d) -> %lld\\n\", l, r, lazy[i]);\n        }\n  \
    \      printf(\"\\n\");\n    }\n    */\n};\n"
  code: "#include <cstdio>\n#include <vector>\n#include <climits>\nusing namespace\
    \ std;\nusing ll = long long int;\n\ntemplate<typename Type>\nstruct SqrtDecomp\
    \ {\n    int SIZE;\n    vector<Type> node, bucket, lazy, need_upd;\n    Type (*op1)\
    \ (Type x, Type y, int sz);\n    Type (*op2) (Type x, Type y);\n    Type I_op1,\
    \ I_op2;\n\n    SqrtDecomp( vector<Type> vec,\n                Type (*g_op1) (Type\
    \ x, Type y, int sz),\n                Type (*g_op2) (Type x, Type y),\n     \
    \           Type X_op1, Type X_op2) {\n        int N = vec.size();\n        SIZE\
    \ = 1; while(SIZE * SIZE < N) SIZE++;\n        op1 = g_op1, op2 = g_op2;\n   \
    \     I_op1 = X_op1, I_op2 = X_op2;\n\n        node.resize(SIZE*SIZE, I_op2);\n\
    \        bucket.resize(SIZE, I_op2);\n        lazy.resize(SIZE, I_op1);\n    \
    \    need_upd.resize(SIZE, 0);\n\n        for(int i=0; i<SIZE; i++) {\n      \
    \      Type rep_val = I_op2;\n            for(int j=0; j<SIZE && i*SIZE+j<N; j++)\
    \ {\n                int idx = (i*SIZE + j);\n                node[idx] = vec[idx];\n\
    \                rep_val = op2(rep_val, node[idx]);\n            }\n         \
    \   bucket[i] = rep_val;\n        }\n    }\n\n    void lazy_eval(int k) {\n  \
    \      int l = SIZE*k, r = SIZE*(k+1);\n        if(need_upd[k]) {\n          \
    \  Type seg_val = I_op2;\n\n            // \u8A72\u5F53\u3059\u308B\u4E0B\u306E\
    \u30CE\u30FC\u30C9\u3092\u307E\u305A\u66F4\u65B0\n            for(int i=l; i<r;\
    \ i++) {\n                node[i] = op1(node[i], lazy[k], 1);\n              \
    \  seg_val = op2(seg_val, node[i]);\n            }\n\n            // \u4E0A\u306E\
    \u30CE\u30FC\u30C9\u3092\u66F4\u65B0\n            bucket[k] = seg_val;\n     \
    \   }\n        lazy[k] = I_op1;\n        need_upd[k] = false;\n    }\n\n    void\
    \ update(int l, int r, Type val) {\n        int lidx = l / SIZE, ridx = r / SIZE;\n\
    \        // \u5DE6\u7AEF\u306E\u66F4\u65B0\n        lazy_eval(lidx);\n       \
    \ bucket[lidx] = I_op2;\n        for(int k=SIZE*lidx; k<SIZE*(lidx+1); k++) {\n\
    \            if(l <= k && k < r) node[k] = op1(node[k], val, 1);\n           \
    \ bucket[lidx] = op2(bucket[lidx], node[k]);\n        }\n\n        if(lidx !=\
    \ ridx) {\n            // \u771F\u3093\u4E2D (lazy \u3092\u66F4\u65B0)\n     \
    \       for(int k=lidx+1; k<ridx; k++) {\n                lazy[k] = op1(lazy[k],\
    \ val, 1);\n                need_upd[k] = true;\n            }\n\n           \
    \ if(ridx != SIZE) {\n                lazy_eval(ridx);\n                bucket[ridx]\
    \ = I_op2;\n\n                // \u53F3\u7AEF\u306E\u66F4\u65B0\n            \
    \    for(int k=SIZE*ridx; k<SIZE*(ridx+1); k++) {\n                    if(k <\
    \ r) node[k] = op1(node[k], val, 1);\n                    bucket[ridx] = op2(bucket[ridx],\
    \ node[k]);\n                }\n            }\n        }\n    }\n\n    Type query(int\
    \ l, int r) {\n        int lidx = l / SIZE, ridx = r / SIZE;\n        Type ret\
    \ = I_op2;\n        \n        // \u5DE6\u7AEF\u306E\u53D6\u5F97\n        for(int\
    \ k=l; k<min(r, SIZE*(lidx+1)); k++) {\n            lazy_eval(lidx);\n       \
    \     ret = op2(ret, node[k]);\n        }\n\n        if(lidx != ridx) {\n    \
    \        for(int k=lidx+1; k<ridx; k++) {\n                // \u5168\u4F53\u306E\
    \u5024\u3068 lazy \u306E\u5024\u3092\u8003\u616E\u3057\u3066\u5024\u3092\u8A08\
    \u7B97\n                Type val = (need_upd[k] ? op1(bucket[k], lazy[k], SIZE)\
    \ : bucket[k]);\n                ret = op2(ret, val);\n            }\n\n     \
    \       for(int k=SIZE*ridx; k<r; k++) {\n                lazy_eval(ridx);\n \
    \               ret = op2(ret, node[k]);\n            }\n        }\n\n       \
    \ return ret;\n    }\n\n    /*\n    void print_debug() {\n        printf(\"<<\
    \ node >>\\n\");\n        printf(\"upper bucket:\\n\");\n        for(int i=0;\
    \ i<SIZE; i++) {\n            int l = SIZE*i, r = SIZE*(i+1);\n            printf(\"\
    [%6d, %6d) -> %lld\\n\", l, r, bucket[i]);\n        }\n        printf(\"lower\
    \ bucket:\\n\");\n        for(int i=0; i<SIZE*SIZE; i++) {\n            printf(\"\
    [%6d, %6d) -> %lld\\n\", i, i+1, node[i]);\n        }\n\n        printf(\"<< lazy\
    \ >>\\n\");\n        printf(\"upper bucket:\\n\");\n        for(int i=0; i<SIZE;\
    \ i++) {\n            int l = SIZE*i, r = SIZE*(i+1);\n            printf(\"[%6d,\
    \ %6d) -> %lld\\n\", l, r, lazy[i]);\n        }\n        printf(\"\\n\");\n  \
    \  }\n    */\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_010_abst_sqrtdecomp.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_010_abst_sqrtdecomp.cpp
layout: document
redirect_from:
- /library/structure/strc_010_abst_sqrtdecomp.cpp
- /library/structure/strc_010_abst_sqrtdecomp.cpp.html
title: structure/strc_010_abst_sqrtdecomp.cpp
---
