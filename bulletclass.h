#ifndef BULLETCLASS_H_INCLUDED
#define BULLETCLASS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class bullet{
private :
        int x_bullet,y_bullet ,color_bullet,n_bullet;

public :
    void setX_bullet(int);
    void setY_bullet(int);
    int  getX_bullet();
    int  getY_bullet();
    void setn_bullet();
    void setcolor_bullet();
    int  getn_bullet();
    int  getcolor_bullet();

};


#endif // BULLETCLASS_H_INCLUDED
