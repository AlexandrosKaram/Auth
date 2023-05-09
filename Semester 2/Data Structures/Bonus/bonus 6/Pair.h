# pragma once
// declaration of class Pair
template <class X> class Pair {
    private:
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
};