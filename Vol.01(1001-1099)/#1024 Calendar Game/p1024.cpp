// 是一个递归的关系
// 用了一个三维的数组来 DP
// 但是 DP 的时候采用了递归，可能一开始求 1900 1 1 的话
// 递归层数过多会导致堆栈区溢出而 RE
// 因此要做准备工作，逐步前推填表，也就是下面的 buffer 函数
// 这个方法并不是很漂亮，至少，可以找到一个非递归的 DP 

#include <cstdio>
#include <cstring>

/*
关于这道题的逻辑：
    假设有某一天是肯定能赢的：这天为 date1 = yyyy/mm/dd
明显，开始知道这样的日子有两个：即是2001/11/3和2001/10/4
    那么，现在随便找某一天，假如这个日子不合法，那这一天肯定是输的
否则，如果这一天的下个月同一天不存在，那么他 Move 到这个位置去肯定会导致他输，

因此取决于紧接着的下一天是否必胜，即 win(someDay) = !win(someDay.nextday())
或者，如果这一天的下个月同一天存在，那么他有权利 Move 到这两个位置当中的任意一个，如果这两个位置当中至少有一个必输，那么他就可以将对手置于必输的位置，因此这个位置必赢，即 win(someDay) = !win(someDay.nextday()) || !win(someDay.nextmonth())
*/

char	A[103][12][31];
int	DAY[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31 };

// 判断一个年份是否为闰年 
inline bool isLeapYear( int year ) {
	return	year % 400 == 0 || year % 100 && year % 4 == 0;
}

// 判断一个日期是否在合法范围内 
inline bool isValid( int year, int month, int day ) {
	if( year < 1900 || month < 1 || day < 1 )
		return	false;
	DAY[1] = isLeapYear( year ) ? 29 : 28;
	if( year > 2001 || month > 12 || day > DAY[month - 1] )
		return	false;
	if( year == 2001 && month == 12 )
		return	false;
	if( year == 2001 && month == 11 && day > 3 )
		return	false;
	return	true;
}

// 判断一个日期是否能胜利 
bool win( int year, int month, int day ) {
//	printf( "call: %d/%d/%d\n", year, month, day );
	if( !isValid( year, month, day ) )
		return	false;
	if( A[year - 1900][month - 1][day - 1] >= 0 )
		return	A[year - 1900][month - 1][day - 1];
	DAY[1] = isLeapYear( year ) ? 29 : 28;
	// 紧邻着的下一天 
	int	nextDay = day + 1,
		nextMonth = month,
		nextYear = year;
	// 如果本日是月末 
	if( day == DAY[month - 1] ) {
		// 下一日应当是 1 号
		nextDay = 1;
		// 月份加 1，如果本月为 12 月，则下月为 1 月 
		if( nextMonth++ == 12 ) {
			nextMonth = 1;
			// 并且年份加 1 
			nextYear++;
		}
	}
	// 若下一个位置是胜利的位置，那么本日是可能输的位置
	bool	ans = !win( nextYear, nextMonth, nextDay );
	// 如果存在下个月的同一天
	if( isValid( year + month / 12, month % 12 + 1, day ) )
		// 而只要这天是个失败的位置的话，本日是个胜利的位置 
		ans = ans || !win( year + month / 12, month % 12 + 1, day );
	return	A[year - 1900][month - 1][day - 1] = char( ans );
}

// 迭代缓冲，防止过度递归堆栈溢出 
void buffer() {
	for( int year = 2000; year >= 1900; year -= 1 )	win( year, 1, 1 ); 
} 

int main() {
	memset( A, -1, sizeof( A ) );
	A[101][10][2] = 1;
	A[101][9][3] = 1;
	buffer();
	int	N,	yyyy,	mm,	dd;
	scanf( "%d", &N );
	while( N-- ) {
		scanf( "%d%d%d", &yyyy, &mm, &dd );
		printf( "%s\n", win( yyyy, mm, dd ) ? "YES" : "NO" );
	}
}
