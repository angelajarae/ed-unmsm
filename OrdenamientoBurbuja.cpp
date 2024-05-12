#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int nPaquetes=0;
int pesoTotal=0;

struct nodo{
	int nro;
	int peso;
	struct nodo *sgte;

};

typedef struct nodo *TpLista;// crear tipo de dato struct nodo

int generarNumero() {
    return rand() % 99 + 1;
}

TpLista  crearNodo(){
    nPaquetes++;
	TpLista q=new(struct nodo );

	q->nro=nPaquetes;
	q->peso=generarNumero();
	q->sgte = NULL;

	pesoTotal=pesoTotal+q->peso;
	return q;
}

/*Funciones Lista circular simple*****************/
void VerLista(TpLista lista){
	TpLista t=lista;
	do{
		cout<<"codigo = "<<t->nro<<" peso= "<<t->peso<<" --> ";
		t=t->sgte;
	}while(t != lista);

		cout<<endl;
}

void insertarFinal(TpLista &lista) {
    TpLista w = crearNodo();
    if (lista == NULL) {
        w->sgte = w;
        lista = w;
    } else {
        TpLista t = lista;
        while (t->sgte != lista)
            t = t->sgte;
        t->sgte = w;
        w->sgte = lista;
    }
}
/*a**********************************************/

//Ordenamiento burbuja
void ordenarPorPeso(TpLista &lista) {
    TpLista actual, siguiente;
    int temp;
    bool flag;

    if (lista == NULL){
        return;
    }

    do{
        flag=false;

        actual = lista;
        siguiente = lista->sgte;
        while (siguiente != lista) {
            if (actual->peso > siguiente->peso) {
                temp = actual->peso;
                actual->peso = siguiente->peso;
                siguiente->peso = temp;
                flag=true;
            }
            actual = siguiente;
            siguiente = siguiente->sgte;
        }

    }while(flag);

}




void menu(){
     system("CLS");
     cout<<"\n\t LAB Ordenamieto Burbuja\n\n";
     cout<<"1.- Registrar paquetes "<<endl;
     cout<<"2.- Ordenar paquetes seg�n peso "<<endl;
     cout<<"0.- Salir "<<endl<<endl;

     cout<<"Ingresar Opcion--->  "<<endl;
}


int main() {
    srand(time(0));

	int opc;
	TpLista lista=NULL;

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
                insertarFinal(lista);
                VerLista(lista);
                cout<<"\n\nCantidad de paquetes:"<<nPaquetes;
                cout<<"\nPeso total:"<<pesoTotal;
                cout<<"\nPeso promedio:"<<(float)pesoTotal/nPaquetes<<endl;
				system("pause");
				break;
            }

			case 2:{
                ordenarPorPeso(lista);
                VerLista(lista);
				system("pause");
				break;
            }

		}

	}while(opc !=0);
	system("pause");

	return 0;
}

