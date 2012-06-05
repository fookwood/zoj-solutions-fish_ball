#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct TeamInfo {
	string	fullName;
	string	subName;
	int	seq;
	int	point;
	int	win;
	int	tie;
	int	lose;
	int	goal;
	int	igoal;
};

bool icmp( TeamInfo team1, TeamInfo team2 ) {
	if( team1.point > team2.point ) return true;
	if( team2.point > team1.point ) return false;
	if( team1.goal - team1.igoal >
	    team2.goal - team2.igoal )  return true;
	if( team1.goal - team1.igoal <
	    team2.goal - team2.igoal )  return false;
	if( team1.goal > team2.goal )	return true;
	if( team1.goal < team2.goal )	return false;
	if( team1.win > team2.win )	return true;
	if( team1.win < team2.win )	return false;
	if( team1.seq > team2.seq )	return true;
	if( team1.seq < team2.seq )	return false;
}

void itoa( int num, char* s ) {
	int	top = 0;
	if( !num ) s[top++] = '0';
	while( num ) {
		s[top++] = '0' + num % 10;
		num /= 10;
	}
	reverse( s, s + top );
	s[top] = '\0';
}

int main() {
	
	
	string	result[80][80];
	vector<TeamInfo> team;
	int	N,	M;
	while( ( cin >> N ) && N ) {
		team.resize( N );
		int	longest = 0;
		// 录入所有组队的初始信息 
		for( int i = 0; i < N; i++ ) {
			cin >> team[i].fullName;
			if( team[i].fullName.size() >= 3 )
				team[i].subName = team[i].fullName.substr( 0, 3 );
			else	team[i].subName = team[i].fullName + string( 3 - team[i].fullName.size(), ' ' );
			if( longest < team[i].fullName.size() )
				longest = team[i].fullName.size(); 
			team[i].point = 0;
			team[i].win = 0;
			team[i].lose = 0;
			team[i].tie = 0;
			team[i].goal = 0;
			team[i].igoal = 0;
			team[i].seq = i;
		}
		// 清空比分矩阵 
		for( int i = 0; i < N; i++ )
			for( int j = 0; j < N; j++ )
				result[i][j] = "   ";
		for( int i = 0; i < N; i++ )
			result[i][i] = " X ";
		// 处理比赛信息 
		string	team1,	team2,	vs;
		cin >> M;
		while( M-- ) {
			cin >> team1 >> team2 >> team2 >> vs;
			int	xPos,	yPos;
			for( int i = 0; i < N; i++ ) {
				if( team1 == team[i].fullName ) xPos = i;
				if( team2 == team[i].fullName ) yPos = i;
			}
			result[xPos][yPos] = vs;
			team[xPos].goal += ( vs[0] - '0' );
			team[xPos].igoal += ( vs[2] - '0' );
			team[yPos].goal += ( vs[2] - '0' );
			team[yPos].igoal += ( vs[0] - '0' );
			if( vs[0] == vs[2] ) {
				team[xPos].tie++;
				team[yPos].tie++;
				team[xPos].point++;
				team[yPos].point++;
			}
			else if( vs[0] > vs[2] ) {
				team[xPos].win++;
				team[yPos].lose++;
				team[xPos].point += 3;
			}
			else {
				team[xPos].lose++;
				team[yPos].win++;
				team[yPos].point += 3;
			}
		}
		// 拉伸组队全名以符合缩进 
		for( int i = 0; i < N; i++ )
			for( int j = team[i].fullName.size(); j < longest; j++ )
				team[i].fullName += " ";
		// 输出结果列表
		cout << "RESULTS:" << endl;
		string	emptyLine;
		emptyLine = "+";
		for( int i = 0; i < longest; i++ )
			emptyLine += "-";
		emptyLine += "+";
		for( int i = 0; i < N; i++ )
			emptyLine += "---+";
		cout << emptyLine << endl << '|';
		for( int i = 0; i < longest; i++ )
			cout << ' ';
		cout << '|';
		for( int i = 0; i < N; i++ )
			cout << team[i].subName << '|';
		cout << endl << emptyLine << endl;
		for( int i = 0; i < N; i++ ) {
			cout << '|' << team[i].fullName << '|';
			for( int j = 0; j < N; j++ )
				cout << result[i][j] << '|';
			cout << endl << emptyLine << endl;
		}
		cout << endl << "STANDINGS:\n----------" << endl;
		// 处理排名
		sort( team.begin(), team.end(), icmp );
		string	total[80], win[80], tie[80], lose[80], point[80], vesus[80], index[80];
		int	ltotal = 0,lwin = 0,ltie = 0,llose = 0,lpoint = 0,lvesus = 0,lindex = 0;
		char	temp[100];
		for( int i = 0; i < N; i++ ) {
			itoa( team[i].goal, temp );
			vesus[i] = temp;
			vesus[i] += ':';
			itoa( team[i].igoal, temp );
			vesus[i] += temp;
			lvesus = ( lvesus > vesus[i].size() ) ? lvesus : vesus[i].size();
			
			itoa( i + 1, temp );
			index[i] = temp;
			index[i] += ".";
			lindex = ( lindex > index[i].size() ) ? lindex : index[i].size();
			
			itoa( team[i].win + team[i].tie + team[i].lose, temp );
			total[i] = temp;
			ltotal = ( ltotal > total[i].size() ) ? ltotal : total[i].size();
			
			itoa( team[i].win, temp );
			win[i] = temp;
			lwin = ( lwin > win[i].size() ) ? lwin : win[i].size();
			
			itoa( team[i].tie, temp );
			tie[i] = temp;
			ltie = ( ltie > tie[i].size() ) ? ltie : tie[i].size();
		
			itoa( team[i].lose, temp );
			lose[i] = temp;
			llose = ( llose > lose[i].size() ) ? llose : lose[i].size();
		
			itoa( team[i].point, temp );
			point[i] = temp;
			lpoint = ( lpoint > point[i].size() ) ? lpoint : point[i].size();
		}
		for( int i = 0 ; i < N; i++ ) {
			while( vesus[i].size() < lvesus ) vesus[i] = " " + vesus[i];
			while( index[i].size() < lindex ) index[i] = " " + index[i];
			while( total[i].size() < ltotal ) total[i] = " " + total[i];
			while( win[i].size() < lwin ) win[i] = " " + win[i];
			while( tie[i].size() < ltie ) tie[i] = " " + tie[i];
			while( lose[i].size() < llose ) lose[i] = " " + lose[i];
			while( point[i].size() < lpoint ) point[i] = " " + point[i];
		}
		// 输出排名信息
		for( int i = 0; i < N; i++ ) {
			cout << index[i] << " " << team[i].fullName << " ";
			cout << total[i] << ' ' << win[i] << ' ';
			cout << tie[i] << ' ' << lose[i] << ' ';
			cout << vesus[i] << ' ' << point[i] << endl;
		}
		cout << endl;
	}
}
