// 纯粹的编程题，算法不难 
// 注意输入输出要比较斟酌
// 还有数据结构的选择也有关系
#include <iostream>
#include <string>
using namespace std;

struct Node {
	string	name;
	int	grade;
	Node*	parent;
};

int main() {
	int	N,	Q;
	string	temp;
	Node	tree[1000];
	while( ( cin >> N >> Q ) && ( N || Q ) ) {
		getchar();
		// 建树 
		for( int i = 0; i < N; i++ ) {
			getline( cin, tree[i].name );
			tree[i].grade = 0;
			while( tree[i].name[tree[i].grade] == ' ' )
				tree[i].grade++;
			tree[i].name.erase( 0,tree[i].grade );
			if( tree[i].grade == 0 )
				tree[i].parent = NULL;
			else {
				for( int j = i - 1; j >= 0; j-- ) {
					if( tree[j].grade < tree[i].grade ) {
						tree[i].parent = tree + j;
						break;
					}
				}
			}
		}
		// 查找
		string	node1,	oper,	node2;
		Node*	pNode1;
		Node*	pNode2;
		bool	yes;
		while( Q-- ) {
			cin >> node1 >> oper >> oper >> oper >> node2 >> node2;
			// 擦掉最后一个句点 
			node2.erase( node2.size() - 1 );
			// 查找前后操作数所在的节点指针 
			pNode1 = pNode2 = NULL;
			for( int i = 0; i < N; i++ ) {
				if( node1 == tree[i].name )
					pNode1 = tree + i;
				if( node2 == tree[i].name )
					pNode2 = tree + i;
				if( pNode1 && pNode2 )
					break;
			}
			if( !pNode1 || !pNode2 ) {
				// 搜索失败
				cout << "False" << endl;
				continue;
			}
			// 逻辑判别 
			yes = false; 
			if( oper == "child" )
				yes = pNode1 -> parent == pNode2;
			else if( oper == "parent" )
				yes = pNode2 -> parent == pNode1; 
			else if( oper == "sibling" )
				// 有没有多个树根的情况？谨慎点好。 
				yes = pNode1 -> parent ==
				      pNode2 -> parent &&
				      pNode2 -> parent ; 
			else if( oper == "ancestor" ) {
				while( pNode2 -> parent ) {
					if( pNode2 -> parent == pNode1 ) {
						yes = true;
						break;
					}
					pNode2 = pNode2 -> parent;
				}
			}
			else if( oper == "descendant" ) {
				while( pNode1 -> parent ) {
					if( pNode1 -> parent == pNode2 ) {
						yes = true;
						break;
					}
					pNode1 = pNode1 -> parent;
				}
			}
			// 输出
			if( yes ) cout << "True" << endl;
			else	  cout << "False" << endl;
		} 
		cout << endl;
	}
}
