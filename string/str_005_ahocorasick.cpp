// Aho-Corasick 法
// 入力文字列に対してマッチするパターンを検索
// N := 入力文字列の長さ、M := パターンの文字列の長さの合計とするとき、
// 計算量は O(N + M)
// Verified: JOI 2010 春合宿 Day2: DNA の合成

struct Elem {
    int wordidx, lidx, ridx;
};

const int SIZE = 256;
struct PMA {
    PMA* node[SIZE + 1];
    vector<int> matched;
    PMA() { memset(node, 0, sizeof(node)); }

    vector<int> unite(const vector<int> &a, const vector<int> &b) {
        vector<int> res;
        set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
        return res;
    }

    void build(vector<string> pattern) {
        PMA* root = this;
        root -> node[SIZE] = root;
        for(size_t i=0; i<pattern.size(); i++) {
            // 入力文字を絞るときはここも変えよう
            PMA* now = root;
            for(size_t j=0; j<pattern[i].length(); j++) {
                if(!now -> node[ (int)pattern[i][j] ]) {
                    now -> node[ (int)pattern[i][j] ] = new PMA;
                }
                now = now -> node[ (int)pattern[i][j] ];
            }
            now -> matched.push_back(i);
        }

        queue<PMA*> que;
        for(int i=0; i<SIZE; i++) {
            if(!root -> node[i]) root -> node[i] = root;
            else {
                root -> node[i] -> node[SIZE] = root;
                que.push(root -> node[i]);
            }
        }

        while(!que.empty()) {
            PMA* now = que.front(); que.pop();
            for(int i=0; i<SIZE; i++) {
                if(now -> node[i]) {
                    PMA *next = now -> node[SIZE];
                    while(!next -> node[i]) next = next -> node[SIZE];
                    now -> node[i] -> node[SIZE] = next -> node[i];
                    now -> node[i] -> matched = unite(now -> node[i] -> matched, next -> node[i] -> matched);
                    que.push(now -> node[i]);
                }
            }
        }
    }

    // 検索対象の文字列から、どのパターン文字列がどのインデックスで現れたか (半開)
    vector<Elem> match(const string s, vector<string> pattern) {
        vector<Elem> res;
        PMA* pma = this;
        for(size_t i=0; i<s.length(); i++) {
            // 入力文字を絞るときはここも変えよう
            int c = s[i];
            while(!pma -> node[c]) pma = pma -> node[SIZE];
            pma = pma -> node[c];
            for(size_t j=0; j<pma -> matched.size(); j++) {
                int r = i+1, l = r - pattern[ pma -> matched[j] ].length();
                res.push_back(Elem{pma -> matched[j], l, r});
            }
        }
        return res;
    }
};