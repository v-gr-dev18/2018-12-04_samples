// https://github.com/v-gr-dev18/2018-12-04_samples/blob/master/sample01-invert_list/sample01-invert_list.cpp
// 1. Инвертировать односвязный список за линейное время и
// константную дополнительную память.
//============================================================================================================

#include "MyList.h"
#include <iostream>

using namespace std;
int main()
{
    MyList<int> l;
    int input[] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++) l.add(input[i]);
    cout << "{"; l.for_each([](const int item) { static int count = 0;  cout << (count++ ? "," : "") << item; }); cout << "}" << endl;
    l.invert();
    cout << "{"; l.for_each([](const int item) { static int count = 0;  cout << (count++ ? "," : "") << item; }); cout << "}" << endl;
 }
