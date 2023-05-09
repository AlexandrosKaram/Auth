// class Pair

// includes
#include <iostream>
using namespace std;

// declaration of class Pair
template <class X> 
class Pair {
    protected:
        X a,b;
    public:
        // constructors
        Pair();
        Pair(X, X);
        // setters
        void setFirst(X);
        void setSecond(X);
        // getters
        X getFirst();
        X getSecond();
        // methods
        void swap(); // method that swaps the 2 variables' values
        // overloads
        template <class Y>
        friend ostream& operator<<(ostream& os, const Pair<Y>& pair); // overloads >> operator
};

// implementation of class Pair
template <class X> Pair <X>:: Pair(){}   // default constructor

template <class X> Pair <X>:: Pair(X a, X b){   // constructor with 2 parameters
    this->a = a;
    this->b = b;
}

template <class X> void Pair <X>:: setFirst(X a){   // setter for first var
    this->a = a;
}

template <class X> void Pair <X>:: setSecond(X b){   // setter for second var
    this->b = b;
}

template <class X> X Pair <X>:: getFirst(){   // setter for first var
    return(a);
}

template <class X> X Pair <X>:: getSecond(){   // setter for second var
    return(b);
}

template <class X> void Pair <X>:: swap(){   // swaps the 2 vars' values
    X temp = a;
    a = b;
    b = temp;
}

template<class X>
ostream& operator<<(ostream& os, const Pair<X>& pair){   // overloads >> operator
    os << pair.a << "," << pair.b;
    return os;
}