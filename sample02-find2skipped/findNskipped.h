// https://github.com/v-gr-dev18/2018-12-04_samples/blob/master/sample02-find2skipped/findNskipped.h
#ifndef _FINDNSKIPPED_H_
#define _FINDNSKIPPED_H_
#include <vector>

// поиск N пропущенных элементов последовательности v, с позиции l0, по позицию r0 (включая l0, r0)
//============================================================================================================
template<typename T>
void findNskipped(std::vector<T> &result, std::vector<T> &v, size_t l0, size_t r0, size_t N)
{
#ifdef _DEBUG
	{ const auto &ov = std::vector<size_t>({ l0, r0, N }); auto on = "l0,r0,N"; int count = 0; std::cout << on << "={"; for_each(ov.begin(), ov.end(), [&count](const int item) { std::cout << (count++ ? "," : "") << item; }); std::cout << "}" << std::endl; }
#endif
	if (!v.size() || r0 < l0 || N < 1)
		return;
	// левое, среднее, правое значения в умозрительной последовательности без пропусков
	T L, M, R;
	// для текущих позиций слева, справа
	size_t l, r;
	// уже найдено пропусков слева
	size_t Lshift = result.size();
	while (true) {
		L = Lshift + l0;
		R = Lshift + r0 + N;
		M = size_t((L + R) / 2);
#ifdef _DEBUG
		{ const auto &ov = std::vector<size_t>({ L, M, R }); auto on = "L,M,R"; int count = 0; std::cout << on << "={"; for_each(ov.begin(), ov.end(), [&count](const int item) { std::cout << (count++ ? "," : "") << item; if (3 == count) count = 0; }); std::cout << "}" << std::endl; }
#endif
		l = l0, r = r0;
		// предсортировка-разбиение последовательности относительно значения M
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
		if (M + 1 == Lshift + l)
			// если в левой "половине" нет пропусков, переместим фокус на правую
			l0 = l;
		else if (Lshift + N + r == M)
			// если в правой "половине" нет пропусков, переместим фокус на левую
			r0 = r;
		else
			break;
	}
	if (l0 == r0) {
		for (T I = L; I <= R; ++I)
			if (v[l0] != I)
				result.push_back(I);
    }
	else if (M < v[r]) {
		// если значение M слева от [l0,r0]
		for (T I = L; I <= M; ++I)
			result.push_back(I);
#ifdef _DEBUG
		{ auto &ov = result; auto on = "skip"; std::cout << on << "[" << ov.size() << "]={"; int count = 0; std::for_each(ov.begin(), ov.end(), [&count](const int item) { std::cout << (count++ ? "," : "") << item; }); std::cout << "}" << std::endl; }
#endif
		findNskipped(result, v, r, r0, N - (M-L+1));
	}
	else if (v[l] <= M) {
		// если значение M справа от [l0,r0]
		findNskipped(result, v, l0, l, N - (R-M));
		for (T I = M+1; I <= R; ++I)
			result.push_back(I);
#ifdef _DEBUG
		{ auto &ov = result; auto on = "skip"; std::cout << on << "[" << ov.size() << "]={"; int count = 0; std::for_each(ov.begin(), ov.end(), [&count](const int item) { std::cout << (count++ ? "," : "") << item; }); std::cout << "}" << std::endl; }
#endif
	}
	else /* if (Lshift + l0 <= M && M < Lshift + r0) */ {
		// если значение M внутри [l0,r0]
		findNskipped(result, v, l0, r, M + 1 - Lshift - l); // проверить
		findNskipped(result, v, l, r0, N - (M + 1 - Lshift - l));
	}
}

#endif