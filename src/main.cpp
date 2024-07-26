#include <iostream>
#include "../src/model/person.h"
#include "../src/class/graph/graph.cpp"
using namespace std;

int main()
{   
    system("cls");
    int numPersonas;
    cout << "Ingrese el numero de personas: ";
    cin >> numPersonas;

    Graph<Persona> grafo(numPersonas);

    for (int i = 0; i < numPersonas; ++i) {
        Persona p;
        cout<< "Ingrese el nombre y apellido de la persona "<<i + 1<<": ";
        cin>>p.nombre>>p.apellido;
        grafo.addVertex(p);
    }

    int opcion;
    do {
        system("cls");
        cout<<"___Menu:___"<<endl<<endl;
        cout<<"1. Follow"<<endl;
        cout<<"2. Unfollow"<<endl;
        cout<<"3. Imprimir seguidores"<<endl;
        cout<<"4. Camino mas corto"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin>>opcion;

        if (opcion == 1) 
        {
            system("cls");
            string nombreFollower, apellidoFollower;
            string nombreFollowed, apellidoFollowed;
            cout<<"Ingrese el nombre y apellido de la persona que sigue: ";
            cin>>nombreFollower>>apellidoFollower;
            cout<<"Ingrese el nombre y apellido de la persona a la que sigue: ";
            cin>> nombreFollowed >>apellidoFollowed;

            Persona follower = {nombreFollower, apellidoFollower};
            Persona followed = {nombreFollowed, apellidoFollowed};

            grafo.follow(follower, followed);
            cout<<"Proceso satisfactorio."<<endl<<endl;
            system("pause"); 
        } 
        else if (opcion == 2) 
        {
            system("cls");
            string nombreFollower, apellidoFollower;
            string nombreFollowed, apellidoFollowed;
            cout<<"Ingrese el nombre y apellido de la persona que deja de seguir: ";
            cin>>nombreFollower >> apellidoFollower;
            cout<<"Ingrese el nombre y apellido de la persona que deja de ser seguida: ";
            cin>>nombreFollowed >> apellidoFollowed;

            Persona follower = {nombreFollower, apellidoFollower};
            Persona followed = {nombreFollowed, apellidoFollowed};

            grafo.unfollow(follower, followed);
            cout<<"Proceso satisfactorio."<<endl<<endl;
            system("pause");             
        }
        else if (opcion == 3)
        {
            system("cls");
            grafo.printFollowers();cout<<endl;
            system("pause"); 
        } 
        else if (opcion == 4)
        {
            system("cls");
            string nombreStart, apellidoStart;
            string nombreEnd, apellidoEnd;
            cout<<"Ingrese el nombre y apellido de la persona de inicio: ";
            cin>>nombreStart >> apellidoStart;
            cout<<"Ingrese el nombre y apellido de la persona final: ";
            cin>>nombreEnd >> apellidoEnd;

            Persona inicio = {nombreStart, apellidoStart};
            Persona final = {nombreEnd, apellidoEnd};

            grafo.shortestPath(inicio, final);
            system("pause");
        }
    } while (opcion != 5);
    

    return 0;
}