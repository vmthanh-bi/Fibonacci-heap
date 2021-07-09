//#include <cmath>
class vertex;

class fhNode {
public:
    vertex* v;
    fhNode *left, *right, *parent, *child;
    int degree;
    bool marked;
    int d;
    char key;
    
    fhNode(vertex* vt)
    : v(vt), left(this), right(this), parent(nullptr),
    child(nullptr), degree(0), marked(false), d(vt->d), key(vt->key) {}
};

class fHeap {
private:
    fhNode* rootList;
    fhNode* min;
    int n;
    int D(int n) {
        //return ceil(log2(n));
        return 8;
    }
    void consolidate();
    void link(fhNode* y, fhNode* x);
    void cut(fhNode* x, fhNode* y);
    void cascadingCut(fhNode* y);
    
public:
    fHeap();
    
    bool empty() { return n == 0; }
    fhNode* insert(vertex* v);
    vertex* extractMin();
    void decreaseKey(fhNode* node);
};

