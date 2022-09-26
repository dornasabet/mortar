#include <iostream>
#include <graphics.h>
#include <cmath>
#include "mortarclass.h"
#include "bulletclass.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
/*******************************************************mortar**************************************************************/
void mortar::setcolor_mortar(){
cout<<"please enter the color of your mortar(1-RED  2-YELLOW  3-MAGENTA  4-white):";
bool a=true;
int cm;
do{cin>>cm;
    if (cm==1){
        color_mortar=4;
        a=false;
    }
    else if (cm==2){
            color_mortar=14;
            a=false;
        }
    else if (cm==3){
            color_mortar=5;
            a=false;
    }
    else if (cm==4){
            color_mortar=15;
            a=false;
    }
    else {
        cout<<"number invalid please try again:\n";}

            }while(a);
}
int mortar::getcolor_mortar(){
    return color_mortar;
}

void mortar::setsize_mortar(){
cout<<"please enter the radius of your mortar:";
cin>>radious_mortar;}

int mortar::getsize_mortar(){
return radious_mortar;}

void mortar::setcoX_mortar(int nx,int co_X[]){

    cout<<"Enter the Coefficients of equation X:"<<endl;

        for (int i=1;i<=nx;i++){
            cout<<"x("<<i<<")=";
            cin>>co_X [i];
        }

}

void mortar::setcoY_mortar(int ny,int co_Y[]){

    cout<<"Enter the Coefficients of equation Y: "<<endl;
        for (int i=1;i<=ny;i++){
            cout<<"y("<<i<<")=";
            cin>>co_Y [i];
        }

}
void mortar::setcoX_mortarV(int nx,int co_X[]){

    cout<<"Enter the Coefficients of equation Vx:"<<endl;
            int q;

        for (int i=0;i<=(nx);i++){
            if (i==0){
             cout<<"Xv("<<i<<")=";
             cin>>co_X[1];
            }
            else{
            cout<<"Xv("<<i<<")=";
            cin>>q;
            co_X [i+1]=q/(i+1);}

}
}

void mortar::setcoY_mortarV(int ny,int co_Y[]){

    cout<<"Enter the Coefficients of equation Y: "<<endl;
            int q;
        for (int i=0;i<=(ny);i++){
                  if (i==0){
             cout<<"Yv("<<i<<")=";
             cin>>co_Y[1];
                  }
                  else{
            cout<<"Yv("<<i<<")=";
            cin>>q;
            co_Y [i+1] =q/(i+1);}


}}
void mortar::set_Xmortar(){
    cout<<"Enter your X0=";
    cin>>x_mortar;
}
void mortar::set_Ymortar(){
    cout<<"Enter your Y0=";
    cin>>y_mortar;
}

int mortar::get_Xmortar(){
    return x_mortar;
    }
int mortar::get_Ymortar(){
    return y_mortar;
}
void mortar::changecolor_mortar(int i ,int c[]){
 color_mortar=c[i];
 }
/*********************bullet**************************/
int bullet::getX_bullet(){
    return  x_bullet;
}
void bullet::setX_bullet(int x){
    x_bullet=x;
}
int bullet::getY_bullet(){
    return y_bullet;

}
void bullet::setY_bullet(int y){
    y_bullet=y;

}
void bullet::setn_bullet(){
    cout<<"Enter the number of bullets =";
    cin>>n_bullet;
}
int bullet::getn_bullet(){
    return n_bullet;
}
void bullet::setcolor_bullet(){
        color_bullet= rand()%7+1;
}
int bullet::getcolor_bullet(){
        return color_bullet;//color_bullet= rand()%7+1;
}


/****************************************************/
int main()
{   double x1,x2,distancex,y1,y2,distancey;
    int counter=0,eq,xb,yb;
    mortar M;
    bullet B;
    ofstream myfilex,myfiley;
    myfilex.open("x.txt");
    myfiley.open("y.txt");

    srand (time (0));

    cout<<"which equation do you want to use ?:\n 1-distance equation \n 2-velocity equation "<<endl;
    cin>>eq;

    B.setn_bullet();
    int a[B.getn_bullet()];
    int b[B.getn_bullet()];
    int c[B.getn_bullet()];
    for (int j =0 ;j<(B.getn_bullet());j++){
            step :
                yb=rand()%(499-150)+10;
                xb= rand ()%(799-40)+25;

        B.setX_bullet(xb);
        B.setY_bullet(yb);
        a[j]=B.getX_bullet();
        b[j]=B.getY_bullet();
        bool overlap=false;
         for (int i=1;i<=j;i++){
            if (a[j-i]+26<a[j]||a[j]+26<=a[j-i])
                overlap=false;
            else if (b[j-i]+26<b[j]||b[j]+26<=b[j-i])
                overlap=false;
            else
                overlap=true;
        if(overlap==true)
                goto step;
        }
        B.setcolor_bullet();
        c[j]=B.getcolor_bullet();

    }


    if (eq==1){
    int nx,ny;
    cout<<"Enter the grade of your equation X=";
    cin>>nx;
    cout<<"Enter the grade of your equation Y=";
    cin>>ny;
    int co_X [nx],co_Y[ny];

    M.set_Xmortar();
    M.setcoX_mortar(nx,co_X);
    M.set_Ymortar();
    M.setcoY_mortar(ny,co_Y);
    co_X[0]=M.get_Xmortar();
    co_Y[0]=M.get_Ymortar();
    M.setcolor_mortar();
    M.setsize_mortar();

    int time,x=0,y=400;;
    cout<<"Enter Time=";
    cin>>time;

    initwindow(800,500);
    bool result= true;
    setbkcolor(LIGHTBLUE);
    for(double t=0;t<time;t+=0.1){
            cleardevice();
          if (400<=y){
            y=400;
          }
          else{
            x=0;
            y=400;}

        setfillstyle(1,2);
        bar(0,410,800,500);
        for(int i = 0 ;i<B.getn_bullet();i++){
            setfillstyle( 1,c[i]);
            bar (a[i],b[i],a[i]+25,b[i]+25);
            }


        for(int i=0;i<=nx&&result;i++){
            x+=co_X[i]*pow(t,i);
        }
        myfilex<<x<<"\n";

        for(int i=0;i<=ny&&result;i++){
            y+=-(co_Y[i]*pow(t,i));
            if (400<=y){
                result=false;
            cout<<"Time took to touch the ground="<<t<<"seconds\n";
            }}
            myfiley<<y<<"\n";

        if(t==0){
            x2=static_cast<double>(x);
            y2=static_cast<double>(y);
            distancex=0;
            distancey=0;
        }
        else{
            x1=x2;
            x2=static_cast<double>(x);
            y1=y2;
            y2=static_cast<double>(y);
            distancex+=abs(x2-x1);
            distancey+=abs(y2-y1);
        }
    if (400<=y){
        setfillstyle(1,M.getcolor_mortar());
        bar(0,410,800,500);

        }

    setcolor(M.getcolor_mortar());
    setfillstyle(1,M.getcolor_mortar());
    fillellipse(x,y,M.getsize_mortar(),M.getsize_mortar());

     bool overlap2=false;
    for(int i=0;i<B.getn_bullet();i++){
        if(x+M.getsize_mortar()<a[i]||x-M.getsize_mortar()>a[i]+20)
            overlap2=false;
        else if(y+M.getsize_mortar()<b[i]||y-M.getsize_mortar()>b[i]+20)
                overlap2=false;
            else
                overlap2=true;
    if(overlap2==true){
        counter++;
       M.changecolor_mortar(i,c);

       cout<<"X bullet#"<<counter<<"="<<a[i]<<"\t"<<"y bullet#"<<counter<<"="<<b[i]<<endl;
       b[i]=1000;
    }}
    delay(100);
    }
if(y <= 399)
    cout<< "Mortar did not touch the ground"<<endl;
    }
    /*************************************************velocity**************************************************************/
    if (eq==2){
    int nx,ny;
    cout<<"Enter the grade of your equation Vx=";
    cin>>nx;
    cout<<"Enter the grade of your equation Vy=";
    cin>>ny;
    int co_X [nx],co_Y[ny];
    M.set_Xmortar();
    M.setcoX_mortarV(nx,co_X);
    M.set_Ymortar();
    M.setcoY_mortarV(ny,co_Y);
    co_X[0]=M.get_Xmortar();
    co_Y[0]=M.get_Ymortar();
    M.setcolor_mortar();
    M.setsize_mortar();

    int time,x=0,y=400;
    cout<<"Enter Time=";
    cin>>time;
    initwindow(800,500);
    bool result= true;
    setbkcolor(LIGHTBLUE);
    for(double t=0;t<time;t+=0.1){
        cleardevice();
         if (400<=y){
            y=400;
          }
          else{
            x=0;
            y=400;}
        setfillstyle(1,2);
        bar(0,410,800,500);
        for(int i = 0 ;i<B.getn_bullet();i++){
            setfillstyle( 1,c[i]);
            bar (a[i],b[i],a[i]+25,b[i]+25);
            }


        for(int i=0;i<=(nx+1)&&result;i++){
            x+=co_X[i]*pow(t,i);
        }
         myfilex<<x<<"\n";


        for(int i=0;i<=(ny+1)&&result;i++){
            y+=-(co_Y[i]*pow(t,i));
            if (400<=y){
                result=false;
            cout<<"Time took to touch the ground="<<t<<"seconds\n";
            }}
        myfiley<<y<<"\n";


        if(t==0){
            x2=static_cast<double>(x);
            y2=static_cast<double>(y);
            distancex=0;
            distancey=0;
        }
        else{
            x1=x2;
            x2=static_cast<double>(x);
            y1=y2;
            y2=static_cast<double>(y);
        }

    if (400<=y){
        setfillstyle(1,M.getcolor_mortar());
        bar(0,410,800,500);}
    setcolor(M.getcolor_mortar());
    setfillstyle(1,M.getcolor_mortar());
    fillellipse(x,y,M.getsize_mortar(),M.getsize_mortar());
     bool overlap2=false;
    for(int i=0;i<B.getn_bullet();i++){
        if(x+M.getsize_mortar()<a[i]||x-M.getsize_mortar()>a[i]+20)
            overlap2=false;
        else if(y+M.getsize_mortar()<b[i]||y-M.getsize_mortar()>b[i]+20)
                overlap2=false;
            else
                overlap2=true;
    if(overlap2==true){
       counter++;
       M.changecolor_mortar(i,c);
       cout<<"X bullet#"<<counter<<"="<<a[i]<<"\t"<<"y bullet#"<<counter<<"="<<b[i]<<endl;
       //a[i]=-50;
       b[i]=1000;}
    }

    delay(100);

    }
    if(y <= 399)
    cout<< "Mortar did not touch the ground"<<endl;
    }

cout<<"number of destroyed bullets:"<<counter<<'\n';
cout<<"the distance mortar traversed:\n";
cout<<"in x axis="<<distancex<<'\n';
cout<<"in y axis="<<distancey;

closegraph();
myfilex.close();
myfiley.close();


    return 0;
}
