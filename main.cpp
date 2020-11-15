#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
void crash(int& speed)
{
    for(speed;speed>=0;speed-=5)
    {
        system("CLS");
        cout<<"Samochod zwalnia do "<<speed<<"km/h!";
        Sleep(50);
    }
    cout<<" Samochod sie wylaczyl!\nPowod: ";
}
void user_crash(int& speed, int& bieg)
{
    bool a1=(speed>0&&speed<25&&bieg!=1);
    bool a2=(speed>20&&speed<45&&bieg!=2);
    bool a3=(speed>40&&speed<65&&bieg!=3);
    bool a4=(speed>60&&speed<85&&bieg!=4);
    bool a5=(speed>80&&bieg!=5);
    if(a1||a2||a3||a4||a5)
    {
        crash(speed);
        cout<<"Nieprawidlowy bieg spowodowal wylaczenie silnika!";
        exit(0);
    }
}
int biegi_w(int& speed,int& bieg)
{
//1-------------------------------------------------------------------------
    if(speed==25&&bieg==1)
    {
        cout<<"Nie mozesz jechac szybciej bez zmiany biegu!"<<endl;
        return speed=20;
    }
//2-------------------------------------------------------------------------
    if(speed==45&&bieg==2)
    {
        cout<<"Nie mozesz jechac szybciej bez zmiany biegu!"<<endl;
        return speed=40;
    }
//3-------------------------------------------------------------------------
    if(speed==65&&bieg==3)
    {
        cout<<"Nie mozesz jechac szybciej bez zmiany biegu!"<<endl;
        return speed=60;
    }
//4-------------------------------------------------------------------------
    if(speed==85&&bieg==4)
    {
        cout<<"Nie mozesz jechac szybciej bez zmiany biegu!"<<endl;
        return speed=80;
    }
}
int biegi_s(int& speed, int& bieg)
{
//1-------------------------------------------------------------------------
    if(speed<90&&bieg==5)
    {
        cout<<"Nie mozesz zwolnic  bez zmiany biegu!"<<endl;
        return speed=85;
    }
//2-------------------------------------------------------------------------
    if(speed<70&&bieg==4)
    {
        cout<<"Nie mozesz zwolnic  bez zmiany biegu!"<<endl;
        return speed=65;
    }
//3-------------------------------------------------------------------------
    if(speed<50&&bieg==3)
    {
        cout<<"Nie mozesz zwolnic  bez zmiany biegu!"<<endl;
        return speed=45;
    }
//4-------------------------------------------------------------------------
    if(speed<30&&bieg==2)
    {
        cout<<"Nie mozesz zwolnic  bez zmiany biegu!"<<endl;
        return speed=25;
    }
}
void hello()
{
    system("CLS");
    cout << "Witaj w symulatorze jazdy samochodem!"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout<<"Wlaczenie/wylaczenie silnika - H"<<endl;
    cout<<"Przyspieszanie/zwalnienie    - W/S"<<endl;
    cout<<"Zmiana biegow w dol/w gore   - Q/E"<<endl;
    cout<<"Bieg wsteczny                - R"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout<<"Aby rozpoczac, wlacz silnik!"<<endl;
}
void cofanie(int& speed)
{
    system("CLS");
    cout<<"Wlaczony bieg wsteczny!";
    for(;;)
    {
    char opcja;opcja=getch();
    switch(opcja)
        {
            case'w':
            case'W':
                system("CLS");
                speed+=5;
                if(speed==15)
                {
                    speed=10;
                }
                cout<<"Cofasz "<<speed<<"km/h!\nobroty silnika: "<<34*(speed);break;
            case's':
            case'S':
                system("CLS");
                speed-=5;
                if(speed>0)
                {
                    cout<<"Cofasz "<<speed<<"km/h!\nobroty silnika: "<<34*(speed);break;
                }
                else
                {
                    speed=0;
                    cout<<"Stoisz w miejscu!\nWcisnij R any przelaczyc na bieg 1!\nobroty silnika: "<<34*(speed);break;
                }
            case'r':
            case'R':
                {
                    if(speed!=0)
                    {
                        crash(speed);
                        cout<<"Zmiana biegu podczas cofania wylaczyla silnik!";
                        exit(0);
                    }
                    else
                    {
                        system("CLS");
                        cout<<"Wrzucono 1 bieg!";
                        return;
                    }
                }
        while(kbhit()) getch();
        }
    }
}
void input(int speed)
{
    int bieg=1;
    for(;;)
    {
    char opcja;opcja=getch();
    switch(opcja)
        {
            case'w':
            case'W':
                system("CLS");
                speed+=5;
                biegi_w(speed,bieg);
                if(speed==155)
                {
                    speed=150;
                }
                cout<<"Jedziesz "<<speed<<"km/h!\nObecny bieg: "<<bieg<<"\nobroty silnika: "<<34*(speed);break;
            case's':
            case'S':
                system("CLS");
                speed-=5;
                biegi_s(speed,bieg);
                if(speed>0)
                {
                    cout<<"Jedziesz "<<speed<<"km/h!\nObecny bieg: "<<bieg<<"\nobroty silnika: "<<34*(speed);break;
                }
                else
                {
                    speed=0;
                    cout<<"Stoisz w miejscu!\nObecny bieg: "<<bieg<<"\nobroty silnika: "<<34*(speed);break;
                }
            case'h':
            case'H':
                crash(speed);
                cout<<"Reczne wylaczenie silnika.";
                exit(0);
            case'e':
            case'E':
                if(speed==0)
                {
                    break;
                }
                else
                {
                    system("CLS");
                    bieg++;
                    speed+=5;
                    if(bieg==6)
                    {
                        bieg=5;
                        speed-=5;
                    }
                    cout<<"Jedziesz "<<speed<<"km/h!""\nObecny bieg: "<<bieg<<"\nobroty silnika: "<<34*(speed);break;
                }
            case'q':
            case'Q':
                if(speed==0)
                {
                    break;
                }
                else
                {
                    system("CLS");
                    bieg--;
                    speed-=5;
                    if(bieg==0)
                    {
                        bieg=1;
                        speed+=5;
                    }
                    cout<<"Jedziesz "<<speed<<"km/h!""\nObecny bieg: "<<bieg<<"\nobroty silnika: "<<34*(speed);break;
                }
            case'r':
            case'R':
                if(speed!=0)
                {
                    crash(speed);
                    cout<<"Proba wlaczenia wstecznego biegu podczas jazdy wylaczyla silnik!";
                    exit(0);
                }
                else
                {
                    cofanie(speed);
                }
            }
    user_crash(speed,bieg);
    while(kbhit()) getch();
    }
}
int main()
{
    hello();
    char a;
    while((a!='r')||(a!='R'))
    {
    a=getch();
    switch(a)
        {
            case'h':
            case'H':
            {
                system("CLS");
                cout<<"Silnik wlaczony i gotowy do startu!";
                input(0);
            }
            default:
            {
                system("CLS");
                cout << "Najpierw wcisnij H, aby wlaczyc silnik!";
                Sleep(500);
                hello();
                while(kbhit()) getch();
            }
        }
    }
    return 0;}


