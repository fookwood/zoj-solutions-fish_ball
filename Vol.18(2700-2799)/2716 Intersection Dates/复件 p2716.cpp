//日期函数

int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
struct date{
	int year,month,day;
};

//判闰年
inline int leap(int year){
	return (year%4==0&&year%100!=0)||year%400==0;
}

//判合法性
inline int legal(date a){
	if (a.month<0||a.month>12)
		return 0;
	if (a.month==2)
		return a.day>0&&a.day<=28+leap(a.year);
	return a.day>0&&a.day<=days[a.month-1];
}

//比较日期大小
inline int datecmp(date a,date b){
   if (a.year!=b.year)
	   return a.year-b.year;
   if (a.month!=b.month)
	   return a.month-b.month;
   return a.day-b.day;
}

//返回指定日期是星期几
int weekday(date a){
	int tm=a.month>=3?(a.month-2):(a.month+10);
	int ty=a.month>=3?a.year:(a.year-1);
	return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+a.day)%7;
}

//日期转天数偏移
int date2int(date a){
	int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400,i;
	days[1]+=leap(a.year);
	for (i=0;i<a.month-1;ret+=days[i++]);
	days[1]=28;
	return ret+a.day;
}

//天数偏移转日期
date int2date(int a){
	date ret;
	ret.year=a/146097*400;
	for (a%=146097;a>=365+leap(ret.year);a-=365+leap(ret.year),ret.year++);
	days[1]+=leap(ret.year);
	for (ret.month=1;a>=days[ret.month-1];a-=days[ret.month-1],ret.month++);
	days[1]=28;
	ret.day=a+1;
	return ret;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int get() {
    date d;
    scanf("%4d%2d%2d", &d.year, &d.month, &d.day);
    return date2int(d);
}

void put(int x) {
    date d = int2date(x);
    printf("%d/%d/%d", d.month, d.day, d.year);
}

vector<pair<int, int> > V, W;
int M, N, T = 0;
bool yes;

int main() {    
    while(cin >> M >> N && (M || N)) {
        V.clear();
        while(M--) {
            int x = get(), y = get();
            V.push_back(make_pair(x, y+1));
        }
        sort(V.begin(), V.end());
        yes = false;
        while(N--) {
            int x = get(), y = get() + 1;
            W.clear();
            for(int i = 0; i < V.size(); ++i) {
                if(V[i].second < x) {
                    W.push_back(V[i]);
                }
                else if(V[i].first <= x && V[i].second < y) {
                    yes = true;
                    x = V[i].first;
                }
                else if(V[i].first <= x && V[i].second >= y) {
                    for(; i < V.size(); ++i)
                        W.push_back(V[i]);
                    x = y = 0;
                }
                else if(V[i].first > x && V[i].first <= y) {
                    yes = true;
                    y = max(y, V[i].second);
                }
                else if(V[i].first > y ) {
                    yes = true;
                    W.push_back(make_pair(x, y));
                    for(; i < V.size(); ++i)
                        W.push_back(V[i]);
                    x = y = 0;
                }
            }
            if(x) {W.push_back(make_pair(x, y)); yes = true;}
            swap(V, W);
        }
        if(T++) puts("");
        printf("Case %d:\n", T);
        if(!yes) puts("No additional quotes are required.");
        else for(int i = 0; i < V.size(); ++i) {
            if(V[i].first + 1 == V[i].second) {
                put(V[i].first);
                puts("");
            }
            else {
                put(V[i].first);
                printf(" to ");
                put(V[i].second - 1);
                puts("");
            }
        }
    }
}
