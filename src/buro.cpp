//============================================================================
// Name        : Buro.cpp
// Author      : Kasianov
// Version     :
// Copyright   : Your copyright notice
// Description : buro in C++, Ansi-style
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
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		case 10: return 'a'; break;


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

int cnt = 0;

int knapsack1(const std::vector<int>& _wts_arrVes, const std::vector<int>& arrCost, int Wmestimost)
{
	size_t n = _wts_arrVes.size();							 //  _wts_arrVes - массив весов,
	std::vector<int> dp(Wmestimost + 1);
	dp[0] = 0;
	for (int wmest = 1, x = 1; wmest <= Wmestimost; wmest++ , ++x)		 // Wmestimost - вместимость рюкзака
	{
		point shift(6,4);
		dp[wmest] = dp[wmest-1];               				 // смотрим
		for (size_t i = 0, y = 0; i < n; i++, ++y)   // arrCost - массив стоимостей
		{

			point pos(x, y);
			pos = pos * shift;
			if (_wts_arrVes[i] <= wmest)
			{
				dp[wmest] = std::max(dp[wmest], dp[wmest - _wts_arrVes[i]] + arrCost[i]);
				point del1(1,0);
				shape * spd =  new rectangle( pos,   pos, int2char(dp[wmest]));
				shape * star =new rectangle( pos + del1,  pos + point(1,1), '*');
				stackWE(spd, star);
			}

//			point del(1,1);
//			new rectangle( pos + del,  pos + del , int2char(cnt++));
//
//
////			point del(3,3);
////			new rectangle( pos + del,  pos + del , int2char(cnt++));
//
//
//
//			new rectangle( pos,   pos, int2char(dp[wmest]));
//			point del1(1,0);
//			new rectangle( pos + del1,   pos + del1, '*');


			cout << "w= " << wmest << " dp[w] = " << dp[wmest] << endl;

			shape_refresh();
			shape_refresh();

		} // for ...
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

	int Wmest = 4;		// W - вместимость рюкзака


	int del =  knapsack1(arrVes, arrCost, Wmest);

	cout << del;

	return 0;
}
