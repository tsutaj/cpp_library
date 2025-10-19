#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1227"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define call_from_test
#include "../../../marathon/trace.cpp"
#undef call_from_test

string char_to_digit = "22233344455566677778889999";

int solve_testcases() {
    int N; cin >> N;
    if (N == 0) return 1;
    vector<string> words(N);
    for(auto &e : words) cin >> e;
    string seq; cin >> seq;

    vector<string> word_digits(N);
    for(int i=0; i<N; i++) {
        string digits = "";
        for(char c : words[i]) {
            digits += char_to_digit[c - 'a'];
        }
        word_digits[i] = digits;
    }
    
    Trace<string> trace;
    vector<int> terminals;
    auto go = [&](auto &&self, int pos, int id) -> void {
        if (pos == seq.size()) {
            terminals.emplace_back(id);
            return;
        }
        for(int i=0; i<N; i++) {
            if (pos + word_digits[i].size() > seq.size()) continue;
            if (seq.substr(pos, word_digits[i].size()) == word_digits[i]) {
                int nxt = pos + word_digits[i].size();
                self(self, nxt, trace.add(words[i], id));
            }
        }
    };
    go(go, 0, -1);
    for(int id : terminals) {
        vector<string> words = trace.get(id);
        for(int i=0; i<(int)words.size(); i++) {
            cout << words[i];
            if (i + 1 < (int)words.size()) cout << " ";
            else cout << ".\n";
        }
    }
    cout << "--" << endl;
    return 0;
}

int main() {
    while(!solve_testcases());
    return 0;
}
