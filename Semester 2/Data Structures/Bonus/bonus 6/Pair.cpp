// definition of class Pair

// includes
#include "Pair.h"
using namespace std;

// class
template <class X> Pair <X>:: Pair(){   // default constructor
    a=0;
    b=0;
}

template <class X> Pair <X>:: Pair(X a, X b){   // constructor with 2 parameters
    this->a = a;
    this->b = b;
}

template <class X> void Pair <X>:: setFirst(X a){   // setter for first var
    this->a = a;
}

template <class X> void Pair <X>:: setFirst(X b){   // setter for second var
    this->b = b;
}

template <class X> X Pair <X>:: getFirst(){   // setter for first var
    return(a);
}

template <class X> X Pair <X>:: getSecond(){   // setter for second var
    return(b);
}

template <class X> void Pair <X>:: swap(){   // swaps the 2 vars' values
    temp = a;
    a = b;
    b = temp;
}

template<class X>
ostream& operator<<(ostream& os, const Pair<X>& pair){   // overloads >> operator
    cout << a << "," << b << endl;
}