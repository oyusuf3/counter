//Program 4:creates a counter object and making increments toward those objects,
//Omar Yusuf, cs320,11/11/21
#include<iostream>
using namespace std;
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
    
    
    
    
    
    //no value passed in so its initilizes as 0
    Counter::Counter():c(0){
        
    }
    
    //value passed in so its initilizes as value
    Counter::Counter(int value): c(value){
        
    }
    //return the value of the Counter
    int Counter::getCount(){
        return c;
        
    }
    Counter Counter::operator++(){
         //implents 1 then return the value
        Counter temp;
        temp.c = ++c;
        return temp;
}
    //return value then implents 1
    Counter Counter::operator++(int){
        Counter temp;
        temp.c = c++;
        return temp;

}
    int  main() {
     Counter c1, c2;
        cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

        ++c1;
        for(int i =0; i < 100; ++i)
            ++c2;
            cout << "c1:" << c1.getCount() << ", "
             << "c2:" << c2.getCount() << endl;

        c1++;
         c2++;
         cout << "c1:" << c1.getCount() << ", "
        << "c2:" << c2.getCount() << endl;

        Counter c3;
         Counter c4(2);
        cout << "c3:" << c3.getCount() << ", "
         << "c4:" << c4.getCount() << endl;

            c3 = c4++;
         cout << "c3:" << c3.getCount() << ", "
        << "c4:" << c4.getCount() << endl;

        c3 = ++c4;
        cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

                    return 0;
}