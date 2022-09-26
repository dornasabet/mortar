#ifndef MORTARCLASS_H_INCLUDED
#define MORTARCLASS_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;
class mortar{
private :
   int   x_mortar ,y_mortar ,
        color_mortar , radious_mortar;
public :
    void setcoX_mortar(int,int[]);
    void setcoY_mortar(int,int[]);
    void setcoX_mortarV(int,int[]);
    void setcoY_mortarV(int,int[]);
    void set_Xmortar();
    void set_Ymortar();
    int  get_Xmortar();
    int  get_Ymortar();
    void setcolor_mortar();
    int  getcolor_mortar();
    void setsize_mortar();
    int  getsize_mortar();
    void changecolor_mortar(int ,int[]);

};


#endif // MORTARCLASS_H_INCLUDED
