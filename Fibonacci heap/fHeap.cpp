#include "graph.h"
#include "fHeap.h"
#include <iostream>

fHeap::fHeap(){
    rootList = nullptr;
    min = nullptr;
    n = 0;
}

fhNode* fHeap::insert(vertex* v){
    fhNode* x = new fhNode(v);
    
    if (min == nullptr) {
        rootList = x;
        min = x;
    }
    else {
        fhNode* next = rootList->right;
        next->left = x;
        x->right = next;
        x->left = rootList;
        rootList->right = x;
        if (x->v->d < min->v->d) {
            min = x;
        }
    }
    n++;
    return x;
}

vertex* fHeap::extractMin(){
    fhNode* z = min;
    
    if (z == nullptr) return nullptr;
    fhNode* x = z->child;
    
    if (x != nullptr) {
        while (x->right != x){
            //removing right of x from child list
            fhNode* next = x->right;
            next->right->left = x;
            x->right = next->right;
            
            //inserting it into rootList, to the right of z
            fhNode* zRight = z->right;
            zRight->left = next;
            next -> right = zRight;
            z->right = next;
            next->left = z;
            
            next->parent = nullptr;
        }
        
        //removing x from child list
        z->child = nullptr;
        fhNode* zRight = z->right;
        zRight->left = x;
        x->right = zRight;
        z->right = x;
        x->left = z;
        x->parent = nullptr;
    }
    
    if (z->right == z) {
        rootList = nullptr;
        min = nullptr;
        } else {
            if(z == rootList)
                rootList = z->right;
        
        //removing z from root list
        z->right->left = z->left;
        z->left->right = z->right;
        consolidate();
    }
    
    n--;
    return z->v;
}

void fHeap::consolidate(){
    fhNode** A = new fhNode*[D(n)+1];
    for (int i = 0; i <= D(n); i++) {
        A[i] = nullptr;
    }
    fhNode* w = rootList;
    if (w != nullptr) {
        do {
            fhNode* x = w;
            w = w->right;
            int d = x->degree;
            while (A[d] != nullptr) {
                fhNode* y = A[d];
                if (x->v->d > y->v->d) {
                    fhNode* z = x;
                    x = y;
                    y = z;
                }
                link(y,x);
                A[d] = nullptr;
                d++;
            }
            A[d] = x;
        } while (w != rootList);
        min = nullptr;
        for (int i = 0; i <= D(n); i++) {
            if (A[i] != nullptr) {
                if (min == nullptr) {
                    rootList = A[i];
                    min = A[i];
                    A[i]->left = A[i];
                    A[i]->right = A[i];
                } else {
                    fhNode* next = rootList->right;
                    next->left = A[i];
                    A[i]->right = next;
                    A[i]->left = rootList;
                    rootList->right = A[i];
                    if (A[i]->v->d < min->v->d) {
                        min = A[i];
                    }
                }
            }
        }
    }
}

void fHeap::link(fhNode* y, fhNode* x){
    if (x->child == nullptr) {
        x->child = y;
        y->left = y;
        y->right = y;
    } else {
        y->right = x->child->right;
        x->child->right->left = y;
        y->left = x->child;
        x->child->right = y;
    }
    y->parent = x;
    x->degree++;
    y->marked = false;
}

void fHeap::decreaseKey(fhNode* node){
    node->d = node->v->d;
    fhNode* y = node->parent;
    if (y != nullptr && node->v->d < y->v->d) {
        cut(node,y);
        cascadingCut(y);
    }
    if (node->v->d < min->v->d) {
        min = node;
    }
    
}

void fHeap::cut(fhNode* x, fhNode* y){
    if (x->right == x) {
        y->child = nullptr;
    } else {
        if(y->child == x) y->child = x->right;
        fhNode* next = x->right;
        fhNode* prev = x->left;
        next->left = prev;
        prev->right = next;
    }
    y->degree--;
    fhNode* rRight = rootList->right;
    rRight->left = x;
    x->right = rRight;
    x->left = rootList;
    rootList->right = x;
    x->parent = nullptr;
    x->marked = false;
}

void fHeap::cascadingCut(fhNode* y){
    fhNode* z = y->parent;
    if (z != nullptr) {
        if (y->marked == false) {
            y->marked = true;
        } else {
            cut(y,z);
            cascadingCut(z);
        }
    }
}
