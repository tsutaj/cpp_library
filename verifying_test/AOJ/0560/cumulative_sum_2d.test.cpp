#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"
#include <cstdio>
using namespace std;
#include "../../../algorithm/cumulative_sum_2d.cpp"

int main() {
    int H, W, Q; scanf("%d%d%d", &H, &W, &Q);
    vector< vector<int> > J(H, vector<int>(W)), O = J, I = J;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            char c; scanf(" %c ", &c);
            if(c == 'J') J[i][j]++;
            if(c == 'O') O[i][j]++;
            if(c == 'I') I[i][j]++;
        }
    }

    auto add = [](int a, int b) { return a + b; };
    auto sub = [](int a, int b) { return a - b; };
    CumulativeSum2D<int> AJ(J, 0, add, sub);
    CumulativeSum2D<int> AO(O, 0, add, sub);
    CumulativeSum2D<int> AI(I, 0, add, sub);

    while(Q--) {
        int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1--, y1--;
        int VJ = AJ.range_val(x1, y1, x2, y2);
        int VO = AO.range_val(x1, y1, x2, y2);
        int VI = AI.range_val(x1, y1, x2, y2);
        printf("%d %d %d\n", VJ, VO, VI);
    }
    return 0;
}
