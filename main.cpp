#include "utils.h"
#include "DataType/Mutex_Stack.h"






int main()
{
    Mutex_Stack<std::string>  stack;

    std::cout<<stack.size()<<"\n";


    return 0;
}