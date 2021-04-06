#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"
using namespace std;

class JobNode {
    friend int main();
    private:
        int ID, time;
    public:
        JobNode(int id, int t) {
            ID = id;
            time = t;
        }
        operator int() {return time;}
        bool operator==(const JobNode &o1) {return this->time == o1.time;} // support find() function in find index of a vector
};

class MachineNode {
    friend int main();
    private:
        int ID, availTime;
    public:
        MachineNode(int id, int t) {
            ID = id;
            availTime = t;
        }
        operator int() {return availTime;}
        bool operator==(const MachineNode &o1) {return this->availTime == o1.availTime;}
};

int main()
{
    MaxHeap<MachineNode> heap;
    MachineNode a(3, 3);
    MachineNode b(2, 6);
    MachineNode c(1, 9);
    heap.add(a);
    heap.add(b);
    heap.add(c);
    //heap.extract();
    heap.print();

    return 0;
}
