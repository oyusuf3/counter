#ifndef COUNTER__H
#define COUNTER__H

class Counter
{
    public:
        Counter(); //creates a counter and initilizes as 0
        Counter(int value);//creates a counter and initilizes as value
        int getCount(); //return the value of the objects
        Counter operator++(); //implement 1 to the object then returns it
        Counter operator++(int);//returns the object then implement it by 1

    private:
        int c;
};
#endif