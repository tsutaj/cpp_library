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
