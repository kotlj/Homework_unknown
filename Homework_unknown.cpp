
#include <iostream>
using namespace std;

const int numberSightSize = 8;
const int standartCharBuffSize = 100;
const int arrSize = 10;

union dbi
{
    double flySpeed;
    bool fourLegs;
    int iq;
};

struct car
{
    char color[standartCharBuffSize];
    char model[standartCharBuffSize];
    char number[numberSightSize];
};

enum creature
{
    bird,
    beast,
    human,
};

struct liveCreature
{
    double groundSpeed;
    creature crt;
    dbi peculiarity;
};

void fillCar(car* a, int indx = -1);
void showCar(car* a, int indx = -1);
void editCar(car* a);
void showAllCars(car* a);
void searchCarByNumber(car* a);
void simpleArrFill(car* a);

void fillCreature(liveCreature* a, int indx = -1);
void showLiveCreature(liveCreature* a, int indx = -1);
void editLiveCreature(liveCreature* a);
void showAllLiveCreatures(liveCreature* a);
void searchByPeculiarity(liveCreature* a);
void simpleArrFill(liveCreature* a);

int main()
{
    int choise = 1;
    while (choise != 0)
    {
        cout << "choose task:\n1 - car/arrays;\n2 - live creatures/arrays\n0 - exit.\n";
        cin >> choise;
        if (choise == 1)
        {
            car simpleArr[arrSize];
            car user = { 'b', 'b', 'b' };
            simpleArrFill(simpleArr);
            while (choise != 0)
            {
                cout << "Choose option:\n1 - fill car struct;\n2 - show car struct;\n3 - edit car info from car array;\n\
                    4 - show car array;\n5 - search car from array by numb;\n0 - exit.\n";
                cin >> choise;
                if (choise == 1)
                {
                    fillCar(&user);
                }
                else if (choise == 2)
                {
                    showCar(&user);
                }
                else if (choise == 3)
                {
                    editCar(simpleArr);
                }
                else if (choise == 4)
                {
                    showAllCars(simpleArr);
                }
                else if (choise == 5)
                {
                    searchCarByNumber(simpleArr);
                }
                else if (choise != 0)
                {
                    cout << "ERROR: INVALID OPTION\n";
                }
            }
        }
        else if (choise == 2)
        {
            liveCreature simpleArr[arrSize];
            liveCreature user;
            simpleArrFill(simpleArr);
            while (choise != 0)
            {
                cout << "Choose option:\n1 - fill live creature struct;\n2 - show live creature struct;\
                    \n3 - edit creature info from live creature array;\n\
                    4 - show live creature array;\n5 - search creature from array by peculiarity;\n0 - exit.\n";
                cin >> choise;
                if (choise == 1)
                {
                    fillCreature(&user);
                }
                else if (choise == 2)
                {
                    showLiveCreature(&user);
                }
                else if (choise == 3)
                {
                    editLiveCreature(simpleArr);
                }
                else if (choise == 4)
                {
                    showAllLiveCreatures(simpleArr);
                }
                else if (choise == 5)
                {
                    searchByPeculiarity(simpleArr);
                }
                else if (choise != 0)
                {
                    cout << "ERROR: INVALID OPTION\n";
                }
            }
        }
        else if (choise != 0)
        {
            cout << "ERROR: INVALID TASK\n";
        }
    }
}


void fillCar(car* a, int indx)
{
    if (indx == -1)
    {
        gets_s((*a).color, standartCharBuffSize);
        cout << "Write color:\n";
        gets_s((*a).color, standartCharBuffSize);
        cout << "Write model:\n";
        gets_s((*a).model, standartCharBuffSize);
        cout << "Write car number:\n";
        gets_s((*a).number, numberSightSize);
    }
    else
    {
        gets_s(a[indx].color, standartCharBuffSize);
        cout << "Write color:\n";
        gets_s(a[indx].color, standartCharBuffSize);
        cout << "Write model:\n";
        gets_s(a[indx].model, standartCharBuffSize);
        cout << "Write car number:\n";
        gets_s(a[indx].number, numberSightSize);
    }
}

void showCar(car* a, int indx)
{
    if (indx == -1)
    {
        cout << "Color: " << (*a).color << " model: " << (*a).model << " number: " << (*a).number << "\n";
    }
    else
    {
        cout << "Color: " << *a[indx].color << " model: " << *a[indx].model << " number: " << *a[indx].number << "\n";
    }
}

void editCar(car* a)
{
    int choise = 0;
    cout << "Choose car to edit:\n";
    showAllCars(a);
    cin >> choise;
    fillCar(a, choise);
}

void showAllCars(car* a)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << i << " - ";
        showCar(a, i);
    }
}

void searchCarByNumber(car* a)
{
    char search[numberSightSize];
    cout << "Enter number of car:\n";
    gets_s(search, numberSightSize);
    gets_s(search, numberSightSize);
    for (int i = 0; i < arrSize; i++)
    {
        if (*search == *a[i].number)
        {
            cout << i << " - ";
            showCar(a, i);
            break;
        }
    }
}

void simpleArrFill(car* a)
{
    for (int i = 0; i < arrSize; i++)
    {
        *a[i].color = char(65 + i);
        *a[i].model = char(65 + i);
        *a[i].number = char(65 + i);
    }
}

void fillCreature(liveCreature* a, int indx)
{
    int choise = 0;
    if (indx == -1)
    {
        cout << "choose type of creature(0 - bird; 1 -  beast; 2 -  human):\n";
        cin >> choise;
        if (choise == 0)
        {
            cout << "enter bird fly speed:\n";
            cin >> (*a).peculiarity.flySpeed;
            (*a).crt = bird;
        }
        else if (choise == 1)
        {
            cout << "beast have 4 legs?\n1 - true;\n0 - false;\n";
            cin >> (*a).peculiarity.fourLegs;
            (*a).crt = beast;
        }
        else if (choise == 2)
        {
            cout << "enter human IQ:\n";
            cin >> (*a).peculiarity.iq;
            (*a).crt = human;
        }
        cout << "enter on-ground move speed:\n";
        cin >> (*a).groundSpeed;
    }
    else
    {
        cout << "choose type of creature(0 - bird; 1 -  beast; 2 -  human):\n";
        cin >> choise;
        if (choise == 0)
        {
            cout << "enter bird fly speed:\n";
            cin >> a[indx].peculiarity.flySpeed;
            a[indx].crt = bird;
        }
        else if (choise == 1)
        {
            cout << "beast have 4 legs?\n1 - true;\n0 - false;\n";
            cin >> a[indx].peculiarity.fourLegs;
            a[indx].crt = beast;
        }
        else if (choise == 2)
        {
            cout << "enter human IQ:\n";
            cin >> a[indx].peculiarity.iq;
            a[indx].crt = human;
        }
        cout << "enter on-ground move speed:\n";
        cin >> a[indx].groundSpeed;
    }
}

void showLiveCreature(liveCreature* a, int indx)
{
    if (indx == -1)
    {
        cout << " On-ground move speed: " << (*a).groundSpeed << " creature: " << ((*a).crt == 0 ? "bird"
            : ((*a).crt == 1 ? "beast" :
            ((*a).crt == 2 ? "human" : "")))
            << " peculiarity: " 
            << ((*a).crt == 0 ? (*a).peculiarity.flySpeed : ((*a).crt == 1 ? (*a).peculiarity.fourLegs :
                ((*a).crt == 2 ?(*a).peculiarity.iq : NULL))) << "\n";
    }
    else
    {
        cout << " On-ground move speed: " << a[indx].groundSpeed << " creature: " << (a[indx].crt == 0 ? "bird" :
            (a[indx].crt == 1 ? "beast" :
            (a[indx].crt == 2 ? "human" : ""))) << " peculiarity: "
            << (a[indx].crt == 0 ? a[indx].peculiarity.flySpeed : (a[indx].crt == 1 ? a[indx].peculiarity.fourLegs :
                (a[indx].crt == 2 ? a[indx].peculiarity.iq : NULL))) << "\n";
    }
}

void editLiveCreature(liveCreature* a)
{
    int choise = 0;
    cout << "choose live creature you want to edit:\n";
    showAllLiveCreatures(a);
    cin >> choise;
    fillCreature(a, choise);
}

void showAllLiveCreatures(liveCreature* a)
{
    for (int i = 0; i < arrSize; i++)
    {
        showLiveCreature(a, i);
    }
}

void searchByPeculiarity(liveCreature* a)
{
    int choise = 0;
    double _flySpeed = 0;
    int _iq = 0;
    bool _fourLegged = false;
    cout << "choose type: 0 - bid, 1 - beast, 2 - human;\n";
    cin >> choise;
    if (choise == 0)
    {
        cout << "enter flySpeed:\n";
        cin >> _flySpeed;
    }
    else if (choise == 1)
    {
        cout << "beast have four legs?\n1 - yes, 0 - 0;\n";
        cin >> _fourLegged;
    }
    else if (choise == 2)
    {
        cout << "enter iq:\n";
        cin >> _iq;
    }
    else
    {
        cout << "ERROR";
    }
    for (int i = 0; i < arrSize; i++)
    {
        if (choise == 0 && _flySpeed == a[i].peculiarity.flySpeed)
        {
            cout << i << " - ";
            showLiveCreature(a, i);
        }
        else if (choise == 1 && _fourLegged == a[i].peculiarity.fourLegs)
        {
            cout << i << " - ";
            showLiveCreature(a, i);
        }
        else if (choise == 2 && _iq == a[i].peculiarity.iq)
        {
            cout << i << " - ";
            showLiveCreature(a, i);
        }
    }
}

void simpleArrFill(liveCreature* a)
{
    for (int i = 0; i < arrSize; i++)
    {
        a[i].crt = (i % 3 == 0 ? bird : (i % 3 == 1 ? beast : (i % 3 == 2 ? human : bird)));
        a[i].groundSpeed = i;
        if (i % 3 == 0)
        {
            a[i].peculiarity.flySpeed = i + 1;
        }
        else if (i % 3 == 1)
        {
            a[i].peculiarity.fourLegs = (i % 2 == 0 ? true : false);
        }
        else if (i % 3 == 2)
        {
            a[i].peculiarity.iq = i * 10;
        }
    }
}