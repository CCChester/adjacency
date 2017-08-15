#ifndef __User_h__
#define __User_h__

struct User {
    const int id;
    User *nextFollow;
    User(int c): id(c) {}   //MIL initialize
};

#endif
