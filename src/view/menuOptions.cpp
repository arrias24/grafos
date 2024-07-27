#include <iostream>
using namespace std;

int ingresarNumPerson()
{
    system("cls");
    int numPersonas;
    while(true)
    {   
        system("cls");
        cout<<"Ingrese el numero de personas: "; 
        cin>>numPersonas;cout<<endl;

        if(cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"[ERROR] - Debes ingresar un numero entero."<<endl<<endl;
            system("pause");
        }
        else if(numPersonas <= 0)
        {
            cout<<"[ERROR] - No puedes ingresar 0 o menos personas."<<endl<<endl;
            system("pause");
        }
        else
        {
            return numPersonas;
        }
    }
}

int operationsMenu()
{
        int decision;
        system("cls");
        cout<<"___Menu:___"<<endl<<endl;
        cout<<"1. Follow"<<endl;
        cout<<"2. Unfollow"<<endl;
        cout<<"3. Imprimir seguidores"<<endl;
        cout<<"4. Camino mas corto"<<endl;
        cout<<"5. Salir"<<endl<<endl;
        cout<<"Ingrese una opcion: ";cin>>decision;
        return decision;
}