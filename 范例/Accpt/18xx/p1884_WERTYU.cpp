#include<stdio.h>
#include<string.h>
char shift(char a)
{
	char b;
	if(a<='9'&&a>='2') b=a-1;
	else switch(a){
	case '=':b='-';break;
	case '-':b='0';break;
	case '0':b='9';break;
	case '1':b='`';break;
	case '\\':b=']';break;
	case ']':b='[';break;
	case '[':b='P';break;
	case 'P':b='O';break;
	case 'O':b='I';break;
	case 'I':b='U';break;
	case 'U':b='Y';break;
	case 'Y':b='T';break;
	case 'T':b='R';break;
	case 'R':b='E';break;	
	case 'E':b='W';break;
	case 'W':b='Q';break;	
	case '\'':b=';';break;	
	case ';':b='L';break;	
	case 'L':b='K';break;	
	case 'K':b='J';break;	
	case 'J':b='H';break;
	case 'H':b='G';break;
	case 'G':b='F';break;
	case 'F':b='D';break;
	case 'D':b='S';break;
	case 'S':b='A';break;
	case '/':b='.';break;
	case '.':b=',';break;
	case ',':b='M';break;
	case 'M':b='N';break;
	case 'N':b='B';break;
	case 'B':b='V';break;
	case 'V':b='C';break;
	case 'C':b='X';break;
	case 'X':b='Z';break;
	default: b=' ';break;
	}
	return b;
}
int main()
{
	char cc[1000];
	while(gets(cc)){
	int len=strlen(cc);
	for(int i=0;i<len;i++)
		printf("%c",shift(cc[i]));
	printf("\n");
	
	}
	return 0;
}
//Powered by SHOIT.050515.