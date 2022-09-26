#include "counter.h"

  
    //no value passed in so its initilizes as 0
    Counter::Counter():c(0){
        
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

    
    //value passed in so its initilizes as value
    Counter::Counter(int value): c(value){
        
    }
        //return value then implents 1
    Counter Counter::operator++(int){
        Counter temp;
        temp.c = c++;
        return temp;

}
