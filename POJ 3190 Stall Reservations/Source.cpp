#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
#define MAX_N 50000
using namespace std;
struct P
{
	int first;
	int second;
	int index;
	bool operator < (const P& p1) const
	{
		if (second == p1.second)
			return first > p1.first;
		return second > p1.second;
	}
};

bool cmp(const P &p1, const P &p2) 
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

P ar[MAX_N];
int a[MAX_N];
int N;
priority_queue<P> rowMan;


void slove() 
{
	int amount = 0;
	for (int i = 0; i < N; ++i) 
	{
		if (rowMan.size() && ar[i].first > rowMan.top().second) 
		{
			a[ar[i].index] = a[rowMan.top().index];
			rowMan.pop();
		}
		else 
		{
			amount++;
			a[ar[i].index] = amount;
		}
		rowMan.push(ar[i]);
		
	}
	
	printf("%d\n", amount);
	for (int j = 0; j < N; ++j)
		printf("%d\n", a[j]);
}



int main() 
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) 
	{
		scanf("%d%d", &ar[i].first, &ar[i].second);
		ar[i].index = i;
	}
	sort(ar, ar + N, cmp);
	slove();
	
	return 0;
}