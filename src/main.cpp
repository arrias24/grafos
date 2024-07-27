#include <iostream>
#include "../src/model/person.h"
#include "../src/class/graph/graph.cpp"
#include "../src/view/menuOptions.cpp"
using namespace std;

int main()
{   
    system("cls");

    int numPersonas = ingresarNumPerson(); //Pedimos la cantidad de personas

    Graph<Persona> grafo(numPersonas); // Creamos el grafo con sus numero de vertices

    //insertamos las personas dentro del grafo

    system("cls");

    cout<<"INGRESAR LOS DATOS."<<endl<<endl;

    for (int i = 0; i < numPersonas; ++i) {
        Persona p;
        cout<<"Ingresa el nombre y apellido de la persona "<<i + 1<<": ";cin>>p.nombre>>p.apellido;
        grafo.addVertex(p);
    }

    int opcion;
    do {
        opcion = operationsMenu();
        
        if (opcion == 1) //follow
        {
            system("cls");

            string nombreFollower, apellidoFollower;
            string nombreFollowed, apellidoFollowed;

            cout<<"Ingrese el nombre y apellido de la persona que sigue: ";cin>>nombreFollower>>apellidoFollower;
            cout<<"Ingrese el nombre y apellido de la persona a la que sigue: ";cin>> nombreFollowed >>apellidoFollowed;
            
            Persona follower = {nombreFollower, apellidoFollower};
            Persona followed = {nombreFollowed, apellidoFollowed};

            bool resultado = grafo.follow(follower, followed);cout<<endl;

            if(resultado)
            {
                cout<<"Operacion exitosa"<<endl<<endl;
            }
            else
            {
                cout<<"Vuelve a intentarlo."<<endl;
            }
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
            cout<<endl<<"Proceso satisfactorio."<<endl<<endl;
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