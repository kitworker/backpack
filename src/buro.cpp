//============================================================================
// Name        : Buro.cpp
// Author      : Kasianov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
using namespace std;

#include "buro.h"




char int2char(int i){
	switch(i){
		case 0: return '0'; break;
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '6'; break;
		case 6: return '7'; break;
		case 7: return '8'; break;
		case 8: return '9'; break;

		default: return '?';
	}

}


/*
 * wts - массив весов,
	cost - массив стоимостей предметов,
	W - вместимость рюкзака
	функция возвращает максимальную стоимость, которую можно набрать(решение задачи о рюкзаке
	с повторениями)
	массив dp собственно реализует динамическое программирование, описанное в статье, как K_w
 *
 */

int knapsack1(const std::vector<int>& _wts_arrVes, const std::vector<int>& arrCost, int Wmestimost)
{
	size_t n = _wts_arrVes.size();							 //  _wts_arrVes - массив весов,
	std::vector<int> dp(Wmestimost + 1);
	dp[0] = 0;
	for (int wmest = 1, x = 1; wmest <= Wmestimost; wmest++ , ++x)		 // Wmestimost - вместимость рюкзака
	{
		point shift(6,2);
		dp[wmest] = dp[wmest-1];               				 // смотрим
		for (size_t i = 0, y = 0; i < n; i++, ++y)   // arrCost - массив стоимостей
		{
			int delt = 1;
			point pos(x+delt, y+delt);
			pos = pos * shift;
			if (_wts_arrVes[i] <= wmest)
			{
				dp[wmest] = std::max(dp[wmest], dp[wmest - _wts_arrVes[i]] + arrCost[i]);
				point del(1,1);
//				new rectangle( pos + del,  pos + del , int2char(dp[wmest]));
			}
			new rectangle( pos,   pos, int2char(dp[wmest]));

			cout << "w= " << wmest << " dp[w] = " << dp[wmest] << endl;


		//	new rectangle( pos,  pos, int2char(w));
//			shift = pos;
			 shape_refresh();

		}
	}



	return dp[Wmestimost];
}

int main() {
	vector<int>  arrVes; // ves
	arrVes.push_back(2);
	arrVes.push_back(2);
	arrVes.push_back(2);

	vector<int> arrCost;	 // cost - массив стоимостей
	arrCost.push_back(1);
	arrCost.push_back(2);
	arrCost.push_back(3);

	int Wmest = 6;		// W - вместимость рюкзака


	int del =  knapsack1(arrVes, arrCost, Wmest);

	cout << del;

	return 0;
}
