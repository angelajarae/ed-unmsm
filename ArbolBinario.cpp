#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct nodo{
	int nro;
	struct nodo *hijoDerecha;
    struct nodo *hijoIzquierda;
};
typedef struct nodo *TpArbolBinario;//Crea tipo de dato struct nodo


int generarNumero() {
    return rand() % 20 + 1;
}

TpArbolBinario  CrearNodo(){
	TpArbolBinario q=new(struct nodo );
	q->nro=generarNumero();
	q->hijoDerecha = NULL;
    q->hijoIzquierda = NULL;
	return q;
}

void insertarNodo(TpArbolBinario &arbol) {
    TpArbolBinario nuevoNodo = CrearNodo();
    int nivel = 1;

    if (arbol == NULL) {
        arbol = nuevoNodo;
        cout << "Raiz ingresada: " << nuevoNodo->nro << endl;
    } 
    else {
        TpArbolBinario actual = arbol;
        TpArbolBinario padre;

        while (true) {
            padre = actual;

            if (nivel >= 3) {
                cout << "Nodo: " << nuevoNodo->nro << " no se pudo agregar al arbol porque excede la profundidad maxima de 3 niveles." << endl;
                delete nuevoNodo;
                return;
            }

            if (nuevoNodo->nro < actual->nro) {
                actual = actual->hijoIzquierda;
                if (actual == NULL) {
                    padre->hijoIzquierda = nuevoNodo;
                    cout << "Nodo ingresado: " << nuevoNodo->nro << endl;
                    return;
                }
            } else {
                actual = actual->hijoDerecha;
                if (actual == NULL) {
                    padre->hijoDerecha = nuevoNodo;
                    cout << "Nodo ingresado: " << nuevoNodo->nro << endl;
                    return;
                }
            }
            nivel++;
        }
    }

}

void preorden(TpArbolBinario nodoActual) {
    if (nodoActual != nullptr) {
        cout << nodoActual->nro << " ";
        preorden(nodoActual->hijoIzquierda);
        preorden(nodoActual->hijoDerecha);
    }
}

void inorden(TpArbolBinario nodoActual) {
    if (nodoActual != nullptr) {
        inorden(nodoActual->hijoIzquierda);
        cout << nodoActual->nro << " ";
        inorden(nodoActual->hijoDerecha);
    }
}

void postorden(TpArbolBinario nodoActual) {
    if (nodoActual != nullptr) {
        postorden(nodoActual->hijoIzquierda);
        postorden(nodoActual->hijoDerecha);
        cout << nodoActual->nro << " ";
    }
}

void menu(){
	system("CLS");
	cout<<"\n\t ARBOL BINARIO\n\n";
	cout<<"1.- Insertar nodo"<<endl;
	cout<<"2.- Recorrido preorden"<<endl;
	cout<<"3.- Recorrido inorden"<<endl;
	cout<<"4.- Recorrido postorden"<<endl;
	cout<<"0.- Salir "<<endl<<endl;

	cout<<"Ingresar Opcion--->  "<<endl;
}

int main() {
    srand(time(0));
	int opc;
	TpArbolBinario arbolBinario=NULL;

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
                insertarNodo(arbolBinario);
				system("pause");
				break;
			}

			case 2:{
                preorden(arbolBinario);
				system("pause");
				break;
			}

			case 3:{
                inorden(arbolBinario);
				system("pause");
				break;
			}
			case 4:{
                postorden(arbolBinario);
				system("pause");
				break;
			}
		}

	}while(opc !=0);
	system("pause");
	return 0;
}