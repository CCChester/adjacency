#include <iostream>
#include <cstdlib>
#include <fstream>
#include "adjacency.h"
#include "User.h"

using namespace std;

int n = 0;

void readmyfile(AdjacencyList &p, char *filename){
    ifstream file(filename);
    string command;
    int num1;
    int num2;
    while(file >> command){
	if (file.fail() && file.eof()){
            return;
        }
        else if (command == "+"){
            file >> num1;
            p.addUser(num1);
        }
        else if (command == "-"){
            file >> num1;
            p.removeUser(num1);
        }
        else if (command == "follow"){
            file >> num1;
            file >> num2;
            p.follow(num1, num2);
        }
        else if (command == "unfollow"){
            file >> num1;
            file >> num2;
            p.unfollow(num1, num2);
        }
        else if (command == "print"){
            file >> num1;
            p.print(num1);
        }
        else if (command == "printall"){
            p.printAll();
        }
        else if (command == "list"){
            file >> num1;
            file >> num2;
            p.list(num1, num2);
        }
        else if (command == "include"){
            char filename[300] = {0};
            file >> filename;
            readmyfile(p, filename);
        }
        else if (command == "quit"){
           n = 1;
           return;
	}
    }
}


int main(){
    string command;
    int num1;
    int num2;
    AdjacencyList *p = new AdjacencyList;
    for(int i = 0; i < 100; i++){
        p->users[i] = NULL;
    }
    while (cin >> command){
       if (cin.fail() && cin.eof()){
            break;
        }
       else  if (command == "+"){
            cin >> num1;
            p->addUser(num1);
        }
        else if (command == "-"){
            cin >> num1;
            p->removeUser(num1);
        }
        else if (command == "follow"){
            cin >> num1;
            cin >> num2;
            p->follow(num1, num2);
        }
        else if (command == "unfollow"){
            cin >> num1;
            cin >> num2;
            p->unfollow(num1, num2);
        }
        else if (command == "print"){
            cin >> num1;
            p->print(num1);
        }
        else if (command == "printall"){
            p->printAll();
        }
        else if (command == "list"){
            cin >> num1;
            cin >> num2;
            p->list(num1, num2);
        }
        else if (command == "include"){
            char filename[300] = {0};
            cin >> filename;
            readmyfile(*p,filename);
	    if(n==1){delete p;
            return 0;}
        }
        else if (command == "quit"){
	    delete p;
	    return 0;
	}
    }
    delete p;
    return 0;
}

