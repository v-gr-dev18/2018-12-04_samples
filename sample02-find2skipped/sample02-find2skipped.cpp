// https://github.com/v-gr-dev18/2018-12-04_samples/blob/master/sample02-find2skipped/sample02-find2skipped.cpp
// 2. В массиве длины n - 1 встречаются все числа от 0 до n, кроме
// двух.За время порядка n найти эти числа.Можно использовать
// только не зависящее от n число байт дополнительной памяти.
//============================================================================================================

const size_t SKIPPED_NUMBER = 2;
const size_t n = 11;

#include "findNskipped.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void generate_skipped_vector(vector<unsigned> &v, size_t vector_size, size_t skipped_number);
template<typename T>
inline void find_skipped(vector<T> &input, vector<T> &result) { findNskipped(result, input, 0, input.size()-1, SKIPPED_NUMBER); };

int main()
{
    vector<unsigned> input;
	//input = { 0,1,3,4,2,10,8,9,7,6 };
    generate_skipped_vector(input, n-1, SKIPPED_NUMBER);
    { auto &ov = input; auto on = "input"; cout << on << "[" << ov.size() << "]={"; int count = 0; for_each(ov.begin(), ov.end(), [&count](const int item) { cout << (count++ ? "," : "") << item; }); cout << "}" << endl; }

    vector<unsigned> result;
    find_skipped(input, result);
    { auto &ov = result; auto on = "skip"; cout << on << "[" << ov.size() << "]={"; int count = 0; for_each(ov.begin(), ov.end(), [&count](const int item) { cout << (count++ ? "," : "") << item; }); cout << "}" << endl; }

    { auto &ov = input; auto on = "modified_input"; cout << on << "[" << ov.size() << "]={"; int count = 0; for_each(ov.begin(), ov.end(), [&count](const int item) { cout << (count++ ? "," : "") << item; }); cout << "}" << endl; }
}
