#include <iostream>
#include <malloc.h>
#include <cstdlib>

using namespace std;

struct datos
{
char caracteres[10];
float n_timp;
};


struct nodos
{
 struct datos corredores;
 int val = 0;
 nodos *sig;
};

 nodos *cab, *aux, *aux2;

float s = 0;
float temporizador = 1;
int cantidad_corredores;

void lista_c();
void registro();

void registro(){
float tiempo = 0, p = 0; 

 cout<<"cuantos corredores hay en el maraton..... ";
 cin>>cantidad_corredores;
do
{

 if(cab == NULL)
 {

  cab = (struct nodos *) malloc(sizeof(struct nodos));
  cout<<"ingrese el nombre del corredor..... ";
  cin>>cab->corredores.caracteres;
  cab->sig = NULL;
  cout<<"ingrese el tiempo que tardo el corredor..... ";
  cin>>tiempo;
  cab->corredores.n_timp = tiempo;
  cab->sig = NULL;
  s = tiempo;
  
 }else{
  temporizador++;
 aux = (struct nodos *) malloc(sizeof(struct nodos));
 cout<<"ingrese el nombre del corredor.... ";
 cin>>aux->corredores.caracteres;
 aux->sig = NULL;
 aux2=cab;
 while (aux2->sig!=NULL)
    aux2 = aux2->sig;
  aux2->sig = aux;

 cout<<"ingrese el tiempo que tardo el corredor.... ";
 cin>>p;
 aux->corredores.n_timp = p;
 s = s + p;
 if ((aux->corredores.n_timp) < tiempo)
    {
     cout<<"El tiempo del corredor debe ser mayor......";
         return;
    } 
 aux->sig = NULL;
 aux2 = aux = NULL;

 free(aux);
 free(aux2);

    


 } 

}while (temporizador<cantidad_corredores);


}


void lista_c(){

s = s / temporizador;
cout<<"el promedio de los corredores es..... "<<s<<"\n";

for (aux=cab; aux!=NULL; aux=aux->sig)

{


cout<<"el nombre del correrdor-> "<<aux->corredores.caracteres<<" y el tiempo-> "<<aux->corredores.n_timp<<"\n";


}





}


void registro();


int main() {



int opc=0;
    do{
        cout<<"bienvenido al Menu de corredores"<<endl;
        cout<<"1. registrar corredores"<<endl;        
        cout<<"2. lista de corredores"<<endl;
        cout<<"3. salir"<<endl;
        cin>>opc;

        switch (opc)
        {

        case 1:
            
            registro();
            
        break;
        
        case 2:
            
            lista_c();
            
        break;    
        
        case 3:
        
            cout<<"goodbye...";
        
        break;


        default: 
            
            
            cout<<"opcion no valida";
            
            
        break;
        }


    }while (opc!=3);

    


    

}