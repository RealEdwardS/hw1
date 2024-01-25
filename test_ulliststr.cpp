#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

    // Test 1
    // ULListStr dat;
    // // dat.push_front("7");
    // // std::cout << dat.get(0) << std::endl;

    // // dat.push_front("8");
    // // std::cout << dat.get(0) << " " << dat.get(1) << std::endl;

    // for (int i = 0; i < 50; ++i){
    //     dat.push_front(std::to_string(i));
    //     // std::cout << dat.get(i) << std::endl;
    // }

    // // for (int i = 0; i < 15; ++i){
    // //     std::cout << dat.get(i) << std::endl; 
    // // }

    // for (int i = 0; i < 50; ++i){
    //     dat.pop_front(); 
    //     std::cout << "popbacked" << std::endl;
    // }
    // // std::cout << "Pushed 15 times" << std::endl; 
    // // std::cout << dat.get(0) << " " << dat.get(1) << std::endl;

    // // dat.push_front("8");
    // // dat.push_front("9");
    // //std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;
    // // prints: 9 8 7

    // for (int i = 0; i < 4; ++i){
    //     dat.push_back("test");

    //     dat.pop_front();
    // }

    // Test 2 

    ULListStr list;

	// list.push_back("oldfront");
    list.push_back("newback");
	list.push_back("oldback");
    
    // // this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
	list.push_front("newfront");

    // // now, a new element struct should get created at the front
	list.pop_back();
	list.push_front("cloudfront");

	// // now, the original head should get deleted
	list.pop_back();

	list.pop_front();

    std::cout << std::to_string(list.empty()) << std::endl;
	list.push_front("newback");
    list.push_back("newback");



    // // Test 3
	// ULListStr list;
    // list.push_back("test");
    // list.pop_back();

    // std::cout << std::to_string(list.empty()) << std::endl;
    // list.push_back("test");
    
    // list.pop_back();

	// for(int count = 0; count < 2; ++count)
	// {
    //     list.push_back("test");
	// 	list.pop_back();
	// }




    return 0;
}
