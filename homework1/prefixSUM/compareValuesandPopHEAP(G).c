#include <stdio.h>
#include <stdlib.h>

static char buf[1 << 16];
static size_t buf_len = 0, buf_pos = 0;

static inline int gc(void) {
    if (buf_pos == buf_len) {
        buf_len = fread(buf, 1, sizeof(buf), stdin);
        buf_pos = 0;
        if (buf_len == 0) return -1;
    }
    return (unsigned char)buf[buf_pos++];
}

static int read_ll(long long *out) {
    int c = gc();
    while (c != '-' && (c < '0' || c > '9')) {
        if (c == -1) return 0;
        c = gc();
    }
    int neg = 0;
    if (c == '-') { neg = 1; c = gc(); }
    long long x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = gc();
    }
    *out = neg ? -x : x;
    return 1;
}

typedef struct { long long num, den; int i, j; } Ev;

static Ev *heap;
static int hsize = 0;

static inline int less(const Ev *a, const Ev *b) {
    __int128 lhs = (__int128)a->num * b->den;
    __int128 rhs = (__int128)b->num * a->den;
    if (lhs != rhs) return lhs < rhs;
    return a->i < b->i;
}

static void hpush(Ev e) {
    int k = hsize++;
    while (k > 0) {
        int p = (k - 1) / 2;
        if (!less(&e, &heap[p])) break;
        heap[k] = heap[p];
        k = p;
    }
    heap[k] = e;
}

static Ev hpop(void) {
    Ev top = heap[0];
    Ev last = heap[--hsize];
    if (hsize > 0) {
        int k = 0;
        while (1) {
            int c = 2 * k + 1;
            if (c >= hsize) break;
            if (c + 1 < hsize && less(&heap[c + 1], &heap[c])) c++;
            if (!less(&heap[c], &last)) break;
            heap[k] = heap[c];
            k = c;
        }
        heap[k] = last;
    }
    return top;
}

static void tryPush(int i, int j, const long long *pos, const long long *vel) {
    if (i < 0 || j < 0) return;
    if (vel[i] > vel[j]) {
        Ev e = { pos[j] - pos[i], vel[i] - vel[j], i, j };
        hpush(e);
    }
}

int main(void) {
    long long n_ll;
    if (!read_ll(&n_ll) || n_ll <= 0) return 0;
    int n = (int)n_ll;

    long long *pos   = malloc((size_t)n * sizeof(long long));
    long long *vel   = malloc((size_t)n * sizeof(long long));
    int *alive       = malloc((size_t)n * sizeof(int));
    int *left        = malloc((size_t)n * sizeof(int));
    int *right       = malloc((size_t)n * sizeof(int));
    heap             = malloc((size_t)(2 * n + 2) * sizeof(Ev));
    if (!pos || !vel || !alive || !left || !right || !heap) return 1;

    for (int i = 0; i < n; i++) {
        if (!read_ll(&pos[i]) || !read_ll(&vel[i])) { pos[i] = vel[i] = 0; }
        alive[i] = 1;
        left[i]  = i - 1;
        right[i] = (i + 1 < n) ? i + 1 : -1;
    }

    for (int i = 0; i + 1 < n; i++) tryPush(i, i + 1, pos, vel);

    while (hsize > 0) {
        Ev e = hpop();
        /* lazy deletion: skip stale events */
        if (!alive[e.i] || !alive[e.j] || right[e.i] != e.j) continue;

        alive[e.i] = alive[e.j] = 0;
        int l = left[e.i], r = right[e.j];
        if (l != -1) right[l] = r;
        if (r != -1) left[r] = l;
        tryPush(l, r, pos, vel);
    }
    
    char *out = malloc((size_t)n * 12 + 32);
    if (!out) return 1;
    size_t p = 0;
    int count = 0;
    for (int i = 0; i < n; i++) count += alive[i];
    p += sprintf(out + p, "%d\n", count);

    int first = 1;
    for (int i = 0; i < n; i++) {
        if (!alive[i]) continue;
        if (!first) out[p++] = ' ';
        first = 0;
        p += sprintf(out + p, "%d", i + 1);
    }
    out[p++] = '\n';
    fwrite(out, 1, p, stdout);

    free(out); free(pos); free(vel); free(alive);
    free(left); free(right); free(heap);
    return 0;
}
