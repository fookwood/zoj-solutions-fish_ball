#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node* parent;
    string name;
    vector<Node*> children;
};

string& trim(string& s) {
    s.erase(s.find_last_not_of(' ') + 1); 
    s.erase(0, s.find_first_not_of(' ')); 
    return s;
}

void destroy(Node* nd) {
    if(nd == NULL) return;
    for(int i = 0; i < nd->children.size(); ++i) {
        destroy(nd->children[i]);
    }
    delete nd;
}

bool valid(string& s) {
    if(s.find('=') != string::npos) {
        string val = s.substr(s.find('=') + 1);
        s.erase(s.find('='));
        return val.size() > 2 && val[0] == '\"' && val[val.size()-1] == '\"';
    }
}

vector<string> parse(string tag) {
    if(tag.find("</") != string::npos) tag.erase(0, 2);
    if(tag.find("/>") != string::npos) tag.erase(tag.size() - 2);
    if(tag.find("<") != string::npos) tag.erase(0, 1);
    if(tag.find(">") != string::npos) tag.erase(tag.size() - 1);
    vector<string> ans;
    while(trim(tag).size() != 0) {
        int p = tag.find(' ');
        if(p == string::npos) {
            if(!valid(tag)) {
                ans.clear();
                return ans;
            }
            ans.push_back(tag);
            break;
        }
        else {
            string s = tag.substr(0, p);
            if(!valid(tag)) {
                ans.clear();
                return ans;
            }
            ans.push_back(s);
            tag.erase(0, p+1);
        }
    }
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    string buf;
    getline(cin, buf);
    while(buf.find("<?xml version=\"1.0\"?>") != string::npos) {
        vector<string> tags;
        while(getline(cin, buf)) {
            if(buf.find("<?xml version=\"1.0\"?>") != string::npos || buf.find("<?end?>") != string::npos) break;
            while(buf.find('<') != string::npos) {
                int p1 = buf.find('<');
                int p2 = buf.find('>');
                tags.push_back(buf.substr(p1, p2 - p1 + 1));
                buf.erase(0, p2 + 1);
            }
        }
        bool ans = true;
        Node* root = new Node();
        Node* ptr = root;
        set<string> names;
        for(int k = 0; k < tags.size() && ans; ++k) {
//cout << tags[k] << endl;
            string s = tags[k];
            vector<string> props = parse(s);
//for(int i = 0; i < props.size(); ++i) {
//    cout << '\t' << props[i] << endl;
//}
//cout << "[names]\t";
//for(set<string>::iterator iter = names.begin(); iter != names.end(); ++iter){
//    cout << *iter << " ";
//}
//cout << endl;
            if(props.size() == 0) {
                ans = false;
                break;
            }
            for(int i = 1; i < props.size(); ++i) {
                for(int j = i + 1; j < props.size(); ++j) {
                    if(props[i] == props[j]) {
                        ans = false;
                    }
                }
            }
            if(tags[k].find("</") != string::npos) {
                if(ptr == root) {
                    ans = false;
                }
                else if(ptr->name != props[0]) {
                    ans = false;
                }
                else {
                    names.erase(ptr->name);
                    ptr = ptr->parent;
                }
            }
            else if(tags[k].find("/>") != string::npos) {
                if(names.find(props[0]) != names.end()) {
                    ans = false;
                }
            }
            else {
                if(names.find(props[0]) != names.end()) {
                    ans = false;
                }
                names.insert(props[0]);
                ptr->children.push_back(new Node());
                ptr->children.back()->parent = ptr;
                ptr = ptr->children.back();
                ptr->name = props[0];
            }
        }
        if(ptr != root) {
            ans = false;
        }
        if(root->children.size() > 1) {
            ans = false;
        }
        destroy(root);
        puts(ans ? "well-formed" : "non well-formed");
    }
//    system("pause");
}
