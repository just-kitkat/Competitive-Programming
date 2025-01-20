/*
// ALL ARE 1-INDEXED, using 0 indexed will result in inf loop (i think)

// PUPQ
const int N=1e7+5;
int fw[N]={0};
void update(int x, int v) {
    for (; x<N; x+=x&(-x)) fw[x] = (fw[x] + v) % MOD; 
}
int sum(int x) {
    int res = 0;
    for(; x; x-=x&(-x)) res = (res + fw[x]) % MOD;
    return res;
}

// RURQ
int fw[N], fw2[N];
void update(int x, int y, int v) { //inclusive
    for (int tx=x; tx < N; tx += tx&(-tx)) fw[tx] += v, fw2[tx] -= v*(x-1);
    for (int ty=y+1; ty < N; ty += ty&(-ty)) fw[ty] -= v, fw2[ty] += v*y; 
}
int sum (int x) {
    int res = 0;
    for (int tx=x; tx; tx -= tx&(-tx)) res += fw[tx]*x + fw2[tx];
    return res;
}
int range_sum(int x, int y) { //inclusive
    return sum(y)-sum(x-1);
}

// Point update in 2D space, range sum in 2D space
int fw[H][W]; //x for H, y for W
void update(int x, int y, int v) {
    for (int tx=x; tx<H; tx+=tx&(-tx))
        for(int ty=y; ty<W; ty+=ty&(-ty)) 
            fw[tx][ty] += v;
}
int sum(int x, int y) {
    int res = 0;
    for (int tx=x; tx; tx-=tx&(-tx))
        for(int ty=y; ty; ty-=ty&(-ty)) 
            res += fw[tx][ty];
    return res;
}
int rangesum(int x1, int y1, int x2, int y2) {  //Inclusive of (x1, y1) and (x2, y2)
    return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
}

*/