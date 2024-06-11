#include <iostream>
#include <cmath>
using namespace std;

const int INF = numeric_limits<int>::max();  

void menu(){
	system("CLS");
	cout<<"\n\t ARBOL BINARIO\n\n";
	cout<<"1.- Matriz de grafo 1"<<endl;
	cout<<"2.- Matriz de grafo 2"<<endl;
    cout<<"0.- Salir"<<endl;

	cout<<"Ingresar Opcion--->  "<<endl;
}

void inicializarMatriz(){

}



void matrizGrafo1() {
    const int nVertices = 6;
    int matriz[nVertices][nVertices];

    // Inicializar matriz
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            matriz[i][j] = INF;
        }
    }

    // Inicializar matriz de adyacencia
    for (int i = 0; i < nVertices; i++) {
        matriz[i][i] = 0;
    }

    // Pesos
    matriz[0][1] = 3;
    matriz[0][4] = 2;
    matriz[0][5] = 5;
    matriz[1][2] = 1;
    matriz[1][5] = 3;
    matriz[2][3] = 3;
    matriz[2][5] = 2;
    matriz[4][3] = 2;
    matriz[5][3] = 2;
    matriz[5][4] = 3;

    // Algoritmo Floyd-Warshall
    for (int k = 0; k < nVertices; k++) {
        for (int i = 0; i < nVertices; i++) {
            for (int j = 0; j < nVertices; j++) {
                if (matriz[i][k] != INF && matriz[k][j] != INF && matriz[i][j] > matriz[i][k] + matriz[k][j]) {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                }
            }
        }
    }

    // Mostrar matriz
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            if (matriz[i][j] == INF) {
                cout << "INF  ";
            } else {
                cout << matriz[i][j] << "    ";
            }
        }
        cout << endl;
    }
}


void matrizGrafo2(){
    int nVertices=5;
    int matriz[nVertices][nVertices];

    // Inicializar matriz
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            matriz[i][j] = INF;
        }
    }

    // Inicializar matriz de adyacencia
    for (int i = 0; i < nVertices; i++) {
        matriz[i][i] = 0;
    }

    //Pesos
    matriz[0][1]=3;
    matriz[0][2]=8;
    matriz[0][4]=4;
    matriz[1][3]=1;
    matriz[1][4]=7;
    matriz[2][1]=4;
    matriz[3][0]=2;
    matriz[3][2]=6;
    matriz[4][3]=6;

    // Algoritmo Floyd-Warshall
    for (int k = 0; k < nVertices; k++) {
        for (int i = 0; i < nVertices; i++) {
            for (int j = 0; j < nVertices; j++) {
                if (matriz[i][k] != INF && matriz[k][j] != INF && matriz[i][j] > matriz[i][k] + matriz[k][j]) {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                }
            }
        }
    }

    // Mostrar matriz
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            if (matriz[i][j] == INF) {
                cout << "INF  ";
            } else {
                cout << matriz[i][j] << "    ";
            }
        }
        cout << endl;
    }
}



int main() {
	int opc;

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
                matrizGrafo1();
				system("pause");
				break;
			}

			case 2:{
                matrizGrafo2();
				system("pause");
				break;
			}
		}

	}while(opc !=0);
	system("pause");
	return 0;
}