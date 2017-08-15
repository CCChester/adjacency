#include <iostream>
#include <cstdlib>
#include <fstream>
#include "adjacency.h"
#include "User.h"

using namespace std;
/***********  addUser  **********
   Purpose: add a user in my users array.
   Returns: NULL
 ***********************************/

void AdjacencyList::addUser(int num){
    int index = 0;
    int control = 0;
    while (users[index] != NULL){
        if (users[index]->id == num){
            control = 1;
            break;
        } //if
        else{index++;}
    } //while 
    if (control == 1){
        cout << "User" << " " << num << " " << "already has an account" << endl;
    } //if
    else{
        User *u1 = new User(num);
        u1->nextFollow = NULL;
        users[index] = u1;
        cout << "User" << " " << num << " " << "has joined the social network" << endl;
    }
}

/*********** removerUser  **********
      Purpose: remove a user from the 
 		users array.
      Return: NULL
 ***********************************/

void AdjacencyList::removeUser(int num){
    int index = 0;
    int control = 0;
    int pos = 0;
    int k = 0;
    int close = 0;
    while (users[index] != NULL){   //check user do not in the array
        if (users[index]->id == num){ //if find the index.id = num
            control = 1;
            break;
        }
        index++;
    }
    if (control == 0){
        cout << "User" << " " << num << " " << "does not have an account" << endl;
    }
    else{
        while (users[pos] != NULL){
            if (users[pos]->id == num){
                close = 1;
                while (users[pos]->nextFollow != NULL){
                    User *u = users[pos];
                    users[pos] = users[pos]->nextFollow;
                    delete u ;
                }
                k = pos;
                delete users[k];
                while (users[k] != NULL){   //let this connect to the next one
                    users[k] = users[k + 1];
                    k++;
                }
            }//delete whole
            else{
   		if (close == 1){
			pos--;
			close = 0;
		}
                User *temp1 = users[pos];
                while(temp1->nextFollow != NULL){
                    if (temp1->nextFollow->id == num){
                        if (temp1->nextFollow->nextFollow != NULL){
                            User *temp2 = temp1->nextFollow->nextFollow;
                            delete temp1->nextFollow;
                            temp1->nextFollow = temp2;
                        }
                        else{
                            User *temp2 = temp1->nextFollow;
                            delete temp2;
                            temp1->nextFollow = NULL;
                        }
                    }
                    else{temp1 = temp1->nextFollow;}
                }
            }
        pos++;
        }
        cout << "User" << " " << num << " " << "has deleted their account" << endl;
    }
}

/*********** follow   **********
      Purpose: contain two integer, let 
		the first integer follow to 
		the second integer.
      Return: NULL
 ***********************************/

void AdjacencyList::follow(int num1, int num2){
    int index = 0;
    int control = 0;
    int control2 = 0;
    while (users[index] != NULL){
        if (users[index]->id == num1){
            control = 1;
            break;
        }
        index++;
    }
    if(control == 0){
        cout << "User" << " " << num1 << " " << "does not have an account" << endl;
        return;
    }
    index = 0;
    while (users[index] != NULL){
        if (users[index]->id == num2){
            control2 = 1;
            break;
        }
        index++;
    }
    if (control2 == 0){
        cout << "User" << " " << num2 << " " << "does not have an account" << endl;
        return;
    }
    if (num1 == num2){
        cout << "Cannot follow yourself" << endl;
        return;
    }
    else{
        int pos = 0;
        while (users[pos] != NULL){
            if (users[pos]->id == num1){
                break;
            }
            pos++;
        } //find the where is the num1;
        User *one = users[pos]->nextFollow;
        int open = 0;
        while(one){
            if (one->id == num2){
                cout << "User" << " " << num1 << " " << "is already following" << " " << num2 << endl;
                open = 1;
                break;
            }
            else{one = one->nextFollow;}
        }
        if(open == 1){return;}
        User *u1 = new User(num2);   //build a new struct, initialize this num2
        u1->nextFollow = NULL;  //next be NULL
        User *temp = users[pos];
        while(temp->nextFollow != NULL){
            temp = temp->nextFollow;
        }
        temp->nextFollow = u1;
        cout << "User" << " " << num1 << " " << "is now following" << " " << num2 << endl;
    }
}

/*********** unfollow    **********
     Purpose: contains two integers, let the 
 	      first integer unfollow the second 
	      integer.
     Returns: NULL
 ***********************************/

void AdjacencyList::unfollow(int num1, int num2){
    int index = 0;
    int control = 0;
    int control2 = 0;
    while(users[index]){
        if (users[index]->id == num1){
            control = 1;
            break;
        }
        index++;
    }
    if (control == 0){
        cout << "User" << " " << num1 << " " << "does not have an account" << endl;
        return;
    }
    index = 0;
    while(users[index]){
        if (users[index]->id == num2){
            control2 = 1;
            break;
        }
        index++;
    }
    if (control2 == 0){
        cout << "User" << " " << num2 << " " << "does not have an account" << endl;
        return;
    }
    if (num1 == num2){
        cout << "Cannot follow yourself therefore cannot unfollow yourself" << endl;
        return;
    }
    else{
        int pos = 0;
        while (users[pos]){
            if (users[pos]->id == num1){
                break;
            }
            pos++;
        } //find the where is the num1;
        User *temp1 = users[pos];
        int open = 1;
        while(temp1->nextFollow != NULL){
            if (temp1->nextFollow->id == num2){
                open = 0;
                if (temp1->nextFollow->nextFollow != NULL){
                    User *temp2 = temp1->nextFollow->nextFollow;
                    delete temp1->nextFollow;
                    temp1->nextFollow = temp2;
                }
                else{
                    User *temp2 = temp1->nextFollow;
                    delete temp2;
                    temp1->nextFollow = NULL;
                }
                cout << "User" << " " << num1 << " " << "is no longer following" << " " <<  num2 << endl;
                break;
            }
            else{temp1 = temp1->nextFollow;}
        }
        if (open == 1){
            cout << "User" << " " << num1 << " " << "was not following" << " " << num2 << endl;
            return;
        }
    }
}

/*********** print  **********
    Purpose:  contains a integer which 
	   represent the user, then print 
	  all the user who this user following.
    Returns: NULL
 ***********************************/

void AdjacencyList::print(int num) const{
    int index = 0;
    int control = 0;
    while (users[index]){   //check user do not in the array
        if (users[index]->id != num){  //if in the array
            control = 0;
        }
        else if (users[index]->id == num){ //if find the index.id = num
            control = 1;
            break;
        }
        index++;
    }
    if (control == 0){
        cout << "User" << " " << num << " " << "does not have an account";
    }
    else if(users[index]->nextFollow == NULL){
        cout << "User" << " " << num << " " << "is following no one";
    }
    else{
        cout << "User" << " " << num << " " << "is following" << " ";
        User *temp = users[index];
        while(temp->nextFollow != NULL){
            cout << temp->nextFollow->id;
            temp = temp -> nextFollow;
            if (temp->nextFollow != NULL){
                cout << ",";
            }
        }
    }
    cout << endl;
}

/*********** printALL    **********
    Purpose: print all the users who users following.
    Returns: NULL
 ***********************************/

void AdjacencyList::printAll() const{
    int index = 0;
    while (users[index]){
        if ( users[index]->nextFollow == NULL){
            cout << "User" << " " << users[index]->id << " " << "is following no one" << endl;
        }
        else{
            User *temp = users[index];
            cout << "User" << " " << temp->id << " " << "is following" << " ";
            while(temp->nextFollow != NULL){
                cout << temp->nextFollow->id;
                temp = temp -> nextFollow;
                if (temp->nextFollow != NULL){
                    cout << ",";
                }
            }
            cout << endl;
        }
        index++;
    }
}

/*********** check   **********
    Purpose: contains integer, which represent
	user, check this user whether in the users
	arrray or not.
    Return: if in the array, then return the index 
	of this user. - 1 otherwise.
 ***********************************/

int AdjacencyList::check(int num) const{
    for(int j = 0; users[j]; j++){
        if (users[j]->id == num){
            return j;
        }
    }
    return -1;
}

/*********** myhep   **********
	Purpose: the helper to do the list function.
        Return: NULL
 ***********************************/

void AdjacencyList::myhelp(User * const u1[ ], int id, int level, int *p) const{
    if(level == 0){
        return;
    }
    User * one = u1[check(id)]->nextFollow;
    for(;;){
        if(one == NULL){
            break;
        }
        p[one->id] = 1;
        myhelp(u1, one->id, level-1,p);
        one = one->nextFollow;
    }
}

/*********** List   **********
    Purpose: list the user to print the number of
	unique users when this users walk level step
    Return: NULL
 ***********************************/

void AdjacencyList::list(int id, int level) const{
    int index = check(id);
    if (index == -1){
        cout << "User" << " " << id << " " << "does not have an account" << endl;
        return;
    }
    int * po = new int [150];
    int k = 0;
    while(k < 150){
        po[k] = 0;
        k++;
    }
    User * one = users[index]->nextFollow;
    for(;;){
        if (one == NULL){
            break;
        }
        po[one->id] = 1;
        myhelp(users, one->id, level-1, po);
        one = one->nextFollow;
    }
    po[id] = 0;
    int number = 0;
    for (int g = 0; g < 150; g++){
        number = number + po[g];
    }
    cout << number << endl;
    delete [ ] po;
}

/*********** ~   **********
   Purpose: to delete all the user and 
   	 the array of user.
   Return: NULL
 ***********************************/

AdjacencyList::~AdjacencyList(){
    int i = 0;
    while (users[i]){
        while (users[i]->nextFollow != NULL){
            User *u = users[i];
            users[i] = users[i]->nextFollow;
            delete u;
        }
        delete users[i];
        i++;
    }
}
