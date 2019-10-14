#include <iostream>
#include <vector>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

}


class Heap{

    public:
        int *heap;
        int e;
        int max;

        Heap(int maximum){
            e = 0;
            max = maximum;
            heap = new int[max];
        }

        int parent(int i){ return (i-1)/2; }
        int left(int i){ return (2*i + 1); }
        int right(int i){ return (2*i + 2); }

        bool EmptyHeap();        
        void insert(int);
        int first();
        int peek();
        void Heapy(int);
                
};

void Heap::insert(int x){

    if(e == max){
        cout << "It is not possible to insert <<FULL>>";
        return;
    }

    e++;
    int i = e - 1;
    heap[i] = x;

    while(i != 0 && heap[parent(i)] > heap[i]){
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }

}

void Heap::Heapy(int i){


    int r = right(i);
    int l = left(i);
    int s = i;

    if(l < e && heap[l] < heap[i]) s = l;

    if(r < e && heap[r] < heap[s]) s = r;
 
    if(s != i){

        swap(&heap[i], &heap[s]);
        Heapy(s);

    }

}

int Heap::peek(){

    if(e <= 0){
        cout << "0 Elements in the heap" << endl;
        exit(-1);

    }

    if(e == 1){
        e--;
        return heap[0];
    }


    int r = heap[0];
    heap[0] = heap[e-1];
    e--;
    Heapy(0);


    return r;
}



int main(){
    Heap h(4);
    h.insert(3);
    h.insert(5);
    h.insert(1);
    
    cout << h.peek() << endl;
    cout << h.peek() << endl;
    cout << h.peek() << endl;
    cout << h.peek() << endl;
}
