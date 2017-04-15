#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class WaterAndOxygen {
public:
	double maxDays(double remainH20, double remainO2, double costH2O, double costO2) {
		double minimumdays=min(remainH20/costH2O,remainO2/costO2);
		remainH20 = remainH20-(minimumdays*costH2O);
		remainO2 = remainO2 - (minimumdays*costO2);
		double low=0,high=remainH20;
		int count=0;
		double mid=0;
		while(low<=high && count!=500){
			count++;
			mid = ((high-low)*1.0)/2 + low;
			double remain = remainH20-2*(mid*(costO2));
			if(remain/costH2O >= mid)
			low=mid;
			else
			high=mid;
		}
		return minimumdays+mid;
	}
};

