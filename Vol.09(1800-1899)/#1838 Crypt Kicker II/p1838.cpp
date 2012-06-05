// 3061719 2008-09-06 20:40:12 Accepted 1838 C++ 00:00.01 868K ´ôÖÍµÄÂý°å 

// ¼òµ¥µÄ×Ö·ûÌæ»» 

#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

string  task = "the quick brown fox jumps over the lazy dog";

int c_map[26],  temp[26];

vector<string>  text;

string  input; 

int main() {
        
    int C = 0;
    
    while( cin ) {
        
        if( C++ )   puts( "" );
    
        text.clear();
    
        memset( c_map, -1, sizeof( c_map ) ); 
    
        bool valid = false;
    
        while( getline( cin, input ) ) {
        
            if( input == "" ) break;
        
            text.push_back( input );
            if( input.size() != task.size() ) continue;
            memset( temp, -1, sizeof( temp ) );
            bool yes = true;
            for( int i = 0; i < task.size(); ++i ) {
                if( (task[i] == ' ') ^ (input[i] == ' ') ) {
                    yes = false;
                    break;
                }
                if( input[i] == ' ' ) continue;
                if( temp[input[i]-'a'] == -1 )
                    temp[input[i]-'a'] = task[i] - 'a';
                else if( temp[input[i]-'a'] != task[i] - 'a' ) {
                    yes = false;
                    break;
                }
            }
            if( yes ) {
                valid = true;
                memcpy( c_map, temp, sizeof( temp ) );
            }
        }
    
        if( !valid ) puts( "No solution." );
        else for( int i = 0; i < text.size(); ++i ) {
            for( int j = 0; j < text[i].size(); ++j )
                if( text[i][j] != ' ' ) 
                    text[i][j] = c_map[text[i][j]-'a']+'a';
            cout << text[i] << endl; 
        }
    
    }
    
}
