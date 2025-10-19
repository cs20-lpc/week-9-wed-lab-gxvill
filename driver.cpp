#include "ArrayQueue.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    cout << "testing consctructor\n";

    ArrayQueue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "q front: " << q.front() << endl;
    cout << "q back:\t " << q.back() << endl;

    ArrayQueue<int> c = ArrayQueue(q);
    cout << "copying q to c\n";

    cout << "c front: " << c.front() << endl;
    cout << "c back:\t " << c.back() << endl;

    try{
        q.clear();
        cout << "q is cleared" << endl;
    }
    catch(const string& e){
        cout << e << endl;
    }

    cout << "dequeue on c\n";
    while (c.getLength() > 0)
    {
        cout << "c front: " << c.front() << endl;
        c.dequeue();
    }

    try{
        cout << c.back() << endl;
    }
    catch (const string &e){
        cout << e << endl;
    }
    try{
    }
    catch (const string &e){
        cout << e << endl;
    }

    return 0;
}
