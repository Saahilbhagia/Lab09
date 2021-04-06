#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <exception>
#include <iostream>
using namespace std;
template <class T>
class MaxHeap {
  private:
    std::vector <T> heap;
    void swap(int lIndex, int rIndex);
    unsigned int getIndex(T val); // get index from each node
    unsigned int getPIndex(int cIndex) {return cIndex/2;} // get parent index
    unsigned int getLCIndex(int pIndex) {return pIndex * 2;} // get left children index
    unsigned int getRCIndex(int pIndex) {return getLCIndex(pIndex) + 1;} // get right children index

  public:
    MaxHeap();
    ~MaxHeap();
    void add(T node);
    T extract();
    void print();
    int size() {return heap.size() - 1;}
};

template <class T>
MaxHeap<T>::MaxHeap() {
    T a(0,0);
    heap.insert(heap.begin() + 0, a); // dummie node
}

template <class T>
MaxHeap<T>::~MaxHeap() {
    std::vector<T>().swap(heap);
}

template <class T>
unsigned int MaxHeap<T>::getIndex(T val) {
    auto it = find(heap.begin(), heap.end(), val);
    if(it != heap.end()) return it - heap.begin();
    else return 0;
}

template <class T>
void MaxHeap<T>::swap(int lIndex, int rIndex) {
    T val = heap.at(lIndex);
    heap.at(lIndex) = heap.at(rIndex);
    heap.at(rIndex) = val;
}

template <class T>
void MaxHeap<T>::add(T node) {
    if(size() == 0) heap.push_back(node);
    else {
        heap.push_back(node);
        int i = size();
        int pI = getPIndex(i); // get the first parent index
        while(i != 1) {
            if(int(heap.at(pI)) < int(heap.at(i))) {
                swap(i, pI);
                i = pI;
                pI = getPIndex(i);
            } else break;
        }
    }
}

template <class T>
T MaxHeap<T>::extract() {
    if(size() == 0) throw "No element to extract";
    else {
        T ans = heap.at(1);
        swap(1, size());
        heap.pop_back();
        int i = 1;
        while(getLCIndex(i) < heap.size()) {
            unsigned int j = getLCIndex(i); // when you bubble down, start compare by left child first
            if(getRCIndex(i) < heap.size()) {
                T rVal = heap.at(getRCIndex(i));
                T lVal = heap.at(getLCIndex(i));
                if(int(heap.at(rVal)) > int(heap.at(lVal))) {
                    j = getRCIndex(i);
                }
            }
            if(int(heap.at(i)) < int(heap.at(j))) {
                swap(i, j);
            } else break;
            i = j;
        }
        return ans;
    }
}

template <class T>
void MaxHeap<T>::print() {
    if(size() == 0) {
        std::cout <<"No element in heap" << std::endl;
    } else {
        for(unsigned i = 1; i < heap.size(); i++) {
            std::cout << int(heap.at(i)) << " ";
        }
        cout << endl;
    }

}

#endif // MAXHEAP_H
