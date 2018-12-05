// https://github.com/v-gr-dev18/2018-12-04_samples/blob/master/sample02-find2skipped/findNskipped.h
// поиск N пропущенных элементов последовательности
//=============================================================================================
#ifndef _FINDNSKIPPED_H_
#define _FINDNSKIPPED_H_
#include <vector>

template<typename T>
void findNskipped(std::vector<T> &result, std::vector<T> &v, size_t l0, size_t r0, size_t N)
{
    if (!v.size() || r0 < l0 || N < 1)
        return;
    do
    {
        size_t Lshift = result.size();
        T L = Lshift + l0;
        T R = Lshift + r0 + N;
        T M = size_t((L + R) / 2);
        size_t l = l0, r = r0;
        while (true)
        {
            while (v[l] <= M && l < r0)
                ++l;
            while (M < v[r] && l0 < r)
                --r;
            if (l < r)
                std::swap(v[l++], v[r--]);
            else
                break;
        }
        if (M + 1 == Lshift + l && M < v[l])
            l0 = l;
        else if (Lshift + N + r == M && v[r] <= M)
            r0 = r;
        else if (l == r0 && v[l] <= M) {
            findNskipped(result, v, l0, r0, N - 1);
            result.push_back(R);
            return;
        }
        else if (r == l0 && M < v[r]) {
            result.push_back(L);
            findNskipped(result, v, l0, r0, N - 1);
            return;
        }
        else {
            findNskipped(result, v, l0, r, M + 1 - Lshift - l); // проверить
            findNskipped(result, v, l, r0, N - (M + 1 - Lshift - l));
            return;
        }
    } while (l0 <= r0);
}

#endif