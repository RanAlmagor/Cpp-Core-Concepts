#include<iostream>
#include "Test.h"

Test::Test() : data{ 0 } 
{ std::cout << "\tTest constructor (" << data << ")" << std::endl; 
}

Test::Test(int data) : data{ data } 
{ std::cout << "\tTest constructor (" << data << ")" << std::endl; 
}
int Test::get_data() const 
{ return data; 
}
Test::~Test() 
{ std::cout << "\tTest destructor (" << data << ")" << std::endl; 
}