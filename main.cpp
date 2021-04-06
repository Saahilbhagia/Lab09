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
        int getID() {return ID;}
        int getTime() {return time;}
        operator int() {return time;}
        operator string() {return to_string(ID);}
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
        int getID() {return ID;}
        int getAvailTime() {return availTime;}
        void setAvailTime(int t) {availTime = t;}
        operator int() {return availTime;}
        operator string() {return to_string(ID);}
        bool operator==(const MachineNode &o1) {return this->availTime == o1.availTime;}
};

int main()
{
    MinHeap<MachineNode> machineHeap;
    MaxHeap<JobNode> jobHeap;
    MachineNode M1(1, 0);
    MachineNode M2(2, 0);
    MachineNode M3(3, 0);
    MachineNode M4(4, 0);
    machineHeap.add(M1);
    machineHeap.add(M3);
    machineHeap.add(M2);
    JobNode J1(1, 2);
    JobNode J2(2, 14);
    JobNode J3(3, 4);
    JobNode J4(4, 16);
    JobNode J5(5, 6);
    JobNode J6(6, 5);
    JobNode J7(7, 3);
//    jobHeap.add(M1);
//    jobHeap.add(M2);
//    jobHeap.add(M3);
//    jobHeap.add(M3);

    jobHeap.add(J1);
    jobHeap.add(J2);
    jobHeap.add(J3);
    jobHeap.add(J4);
    jobHeap.add(J5);
    jobHeap.add(J6);
    jobHeap.add(J7);
    while(jobHeap.size() != 0) {
        MachineNode tempM = machineHeap.extract();
        JobNode tempJ = jobHeap.extract();
        int t = tempM.getAvailTime() + tempJ.getTime();
        cout << "Schedule Job " << tempJ.getID() << " on machine " << tempM.getID();
        cout << " from " << tempM.getAvailTime() << " to " << t;
        cout << endl;
        tempM.setAvailTime(t);
        machineHeap.add(tempM);
    }
    //jobHeap.print();
    return 0;
}
