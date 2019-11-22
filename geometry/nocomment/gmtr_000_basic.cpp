/***** 基本的準備 *****/

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))

double dot(P a, P b) {
    return (a.X * b.X + a.Y * b.Y);
}
double cross(P a, P b) {
    return (a.X * b.Y - a.Y * b.X);
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

/***** テクニック編 *****/

double len = abs(a);
double dist = abs(a-b);

if(abs(a-b) < EPS)

P b = a / abs(a);

P n1 = a * P(0, 1);
P n2 = a * P(0, -1);

P un1 = (a * P(0, 1)) / abs(a);
P un2 = (a * P(0, -1)) / abs(a);