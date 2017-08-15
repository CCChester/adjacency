#ifndef __ADJACENCY_H__
#define __ADJACENCY_H__

struct User;
const int MAXUSERS=100;
struct AdjacencyList {
    
    User *users[MAXUSERS];//array of User pointers
    //for descriptions of the following refer to
    //commands in the assignment specifications
    void addUser(int);
    void removeUser(int);
    void follow(int, int);
    void unfollow(int, int);
    void list(int id, int level) const;
    void printAll() const;
    void print(int) const;
    void myhelp(User * const [ ], int, int, int *) const; //myhelp helper
    int check(int) const; //check helper function
    ~AdjacencyList();
};

void readmyfile(AdjacencyList &, char *); //to do include file helper

#endif
