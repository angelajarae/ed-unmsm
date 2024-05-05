#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct nodo{
	int peso1;
	int peso2;
	int peso3;
	struct nodo *ant;
	struct nodo *sgte;

};

typedef struct nodo *TpLista;

void menu(){

	system("CLS");
	cout<<"\n\t LAB 5\n\n";
	cout<<"1.- Ingresar elemento a la pila"<<endl;
	cout<<"2.- Descargar elemento de la pila"<<endl;
	cout<<"3.- Asignar pesos a lista"<<endl;
	cout<<"4.- Eliminar elemento"<<endl;
	cout<<"5.- Mostrar pila y lista"<<endl;
	cout<<"0.- Salir"<<endl<<endl;

	cout<<"Ingresar Opcion---> "<<endl;
}

//**************GENERACION DE RANDOMS *************
int generarPeso1() {
    return rand() % 41 + 10;
}

int generarPeso2() {
    return rand() % 11 + 10;
}

int generarPeso3() {
    return rand() % 21 + 30;
}


//**************FUNCIONES DE PILAS *************
TpLista pop(TpLista &lista){
	TpLista t=lista;
	if(lista == NULL){
		cout<<"ERROR: Lista vacia.. no permite esta opcion"<<endl;
		system("pause");
		return t;
	}
	lista=lista->sgte;
	t->	sgte=NULL;
	return t;
}

void push(TpLista &lista, TpLista q){
	if(lista !=NULL){
		q->sgte=lista;
	}
	lista =q;

}

void verPila(TpLista l){
    cout<<"\nPILA"<<endl;
	TpLista lista = l;
	int i=0;
	while(lista != NULL){
		cout<< " "<<i+1<<")  "<<lista->peso1<<" - "<<lista->peso2<< " - "<<lista->peso3<<endl;
		lista=lista->sgte;
		i++;
	}

}



//**************FUNCIONES DE LISTA *************
 void InsertarFinal(TpLista &lista,TpLista nodo ){
 	TpLista q=nodo, p=lista;

	if(lista==NULL)
		lista=q;
	else{
		while(p->sgte != NULL){
			p=p->sgte;
		}

		p->sgte=q;
		q->ant=p;
	}

}




void VerLista(TpLista lista)
{
	int i=0;
	TpLista t=lista, q=NULL;
	cout<<"\nLISTA"<<endl;
	cout<<"\n Lista de IDA"<<endl<<endl;
	while(t != NULL){
		cout<< " "<<i+1<<")  "<<t->peso1<<" - "<<t->peso2<< " - "<<t->peso3<<endl;
		q=t;
		t=t->sgte;
		i++;
	}
	cout<<"************";
	i=0;
	cout<<"\n Lista de REGRESO"<<endl<<endl;
	t=q;
	while(t != NULL){
		cout<< " "<<i+1<<")  "<<t->peso1<<" - "<<t->peso2<< " - "<<t->peso3<<endl;
		t=t->ant;
		i++;
	}
}

//**************OPCIONES *************
void ingresarElementoPila(TpLista &pila, int& nElementos){
        if(nElementos<5){
            TpLista nuevo=NULL;
            nuevo=new(struct nodo);
            nuevo->peso1=generarPeso1();
            nuevo->peso2=NULL;
            nuevo->peso3=NULL;
            struct nodo *ant;
            struct nodo *sgte;
            nuevo->sgte=NULL;
            nuevo->ant=NULL;

            push(pila,nuevo);
            nElementos++;
        }
        else{
            cout<<"Pila llego a su capacidad maxima."<<endl;
        }

}

void descargarElementoPila(TpLista &pila,TpLista &lista,int &elementosPila){
    TpLista elemento=pop(pila);
    if(elemento!=NULL){
        InsertarFinal(lista,elemento);
        elementosPila--;
    }

}

void asignarPesosLista(TpLista &lista){
    int i=0;
    TpLista t=lista, q=NULL;
    cout<<"\n Lista de IDA"<<endl<<endl;
    while(t != NULL){
        t->peso2=generarPeso2();
        cout<< " "<<i+1<<")  "<<t->peso1<<" - "<<t->peso2<< " - "<<t->peso3<< endl;
        q=t;
		t=t->sgte;
        i++;
    }
    cout<<"************";
	i=0;
	cout<<"\n Lista de REGRESO"<<endl<<endl;
	t=q;
	while(t != NULL){
	    t->peso3=generarPeso3();
		cout<< " "<<i+1<<")  "<<t->peso1<<" - "<<t->peso2<< " - "<<t->peso3<< endl;
		t=t->ant;
		i++;
	}
}

void eliminarElemento(TpLista &lista){
    int i=1;
    bool nodoEliminado=false;
    TpLista t=lista;

    while (t != NULL) {
        if (t->peso1 + t->peso2 + t->peso3 > 75) {
            nodoEliminado = true;
            if (i == 1) {
                lista = t->sgte;
                delete t;

            }
            else if(t->sgte==NULL){
                 t->ant->sgte = NULL;
                 delete t;

            }
            else {
                t->ant->sgte = t->sgte;
                t->sgte->ant=t->ant;
                delete t;

            }
        }

        t = t->sgte;
        i++;
    }
    if(!nodoEliminado){
        cout<<"\nNo se ha eliminado ningun elemento."<<endl;
    }
}




int main(){
    srand(time(0));
	TpLista pila=NULL,lista=NULL;
	int elementosPila=0,opc;

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
			    ingresarElementoPila(pila,elementosPila);
			    verPila(pila);
				system("pause");
				break;
			}
			case 2:{
			    descargarElementoPila(pila,lista,elementosPila);
			    verPila(pila);
			    VerLista(lista);
				system("pause");
				break;
			}

			case 3:{
			    asignarPesosLista(lista);
				system("pause");
				break;
			}

			case 4:{
			    eliminarElemento(lista);
			    VerLista(lista);
				system("pause");
				break;
			}
			case 5:{
			    verPila(pila);
			    VerLista(lista);
				system("pause");
				break;
			}

		}//switch


	}while(opc != 0);


	return 0;
}


