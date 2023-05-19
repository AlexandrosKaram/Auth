# pragma once
// class PriorityQueue

// includes

// declaration of class
template <class X>
class PriorityQueue{
private:
    X queue;   // X type queue
    int front, rear, maxSize;   // index of front and rear object
public:
    PriorityQueue();   // constructor
    ~PriorityQueue();   // destructor
    // functions
    bool enQueue(X key);   // prepares queue for new key
    bool deQueue(X &key);   // removes key from queue
    void show();   // prints queue
    // personal functions
    bool expandQueue();   // expands queue's size by 5
    void shiftQueue(int);   // shifts all elements from a certain point and after 1 position
    void placeInQueue(X key);   // places the key in queue in descending order
};


// definition of class

template <class X>
PriorityQueue <X>:: PriorityQueue() {   // constructor
    front = -1;
    rear = -1;  
    maxSize = 10;
    queue = new X[10];   // creates array of 10
}

template <class X>
PriorityQueue <X>:: ~PriorityQueue() {   // destructor
    delete[] queue;   // deletes array
}

// functions
template <class X>
bool PriorityQueue <X>:: enQueue(X key){   // puts X type key in queue
    if (rear == maxSize-1){
        cout << "Not enough space. Requesting more..."
        // attempt to expand queue to place item accordingly 
        if (expandQueue()){
            cout << "Space found. Moving data..."
            placeInQueue(X key);
        } else {
            cout << "Space not found. Stopping."
        }
    } else if (front == -1){   // means queue is empty so we initialize it
        front = 0;
        rear = 0;
        queue[0] = key;
    } else {
        placeInQueue(X key);
    }
}

// personal functions
template <class X>
bool PriorityQueue <X>:: expandQueue() {   // expands queue's size by 5
    // create temporary resized array
    int newSize = maxSize+5;
    X* temp = new X[newSize];   // make it pointer so i can copy later

    if (temp == null) return false;   // error
    
    // copy elements from old array
    for (int i=0 ; i<=rear ; i++) {
        temp[i] = queue[i];
    }
    
    // delete old array
    delete[] queue;
    // assign resized array to the dynamic array pointer
    queue = temp;
    maxSize = newSize;
    
    // delete temporary array
    delete[] temp;
    return true;
}

template <class X>
void PriorityQueue <X>:: shiftQueue(int pos) {   // shifts all objects from a certain point to the right
    for (int i=rear+1 ; i > pos ; i--) {
        queue[i] = queue[i-1];
    }
    rear++;
}

template <class X>
void PriorityQueue <X>:: placeInQueue(X key) {   // places key in the queue in descending order
    // loop through the queue to place key correctly
    for (int i=0 ; i<=rear ; i++){
        if (key < queue[i]){
            shiftQueue(i);
            queue[i] = key;
            break;
        }
    }
}
