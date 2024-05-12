#include <iostream>
using namespace std;

struct nodo{
	int nro;
	struct nodo *sgte;
};
typedef struct nodo *TpLista;//Crea tipo de dato struct nodo


//Funciones lista enlazada simple
TpLista  CrearNodo(int n){
	TpLista q=new(struct nodo );
	q->nro=n;
	q->sgte = NULL;
	return q;
}
void VerLista(TpLista lista){
	TpLista t=lista;
	while(t != NULL ){
		cout<<"nr = "<<t->nro<<" --> ";
		t=t->sgte;
	}
	cout<<" NULL"<<endl;
}
void InsertarInicio(TpLista &lista, TpLista nodo){
	TpLista w= nodo;
	w->sgte=lista;
	lista=w;
}
void InsertarFinal(TpLista &lista,TpLista nodo){
	if (lista == NULL) {
        lista = nodo;
        return;
    }

	TpLista w=nodo,t=lista;

	while(t->sgte != NULL)
		t=t->sgte;
	t->sgte=w;
}
void InsertarPosicion(TpLista &lista,TpLista nodo, int pos){
	TpLista w=nodo,t=lista, s=NULL;
	int x=1;
	bool flag=false;
	if(pos ==1)
		InsertarInicio(lista,nodo);
	else{
		while( x != pos &&  t->sgte != NULL){
			s=t;
			t=t->sgte;
			x++;
			if(x==pos)
				flag=true;
		}

		if(flag ==false){
			cout<<" Error, posicion ingresada no existe..."<<endl;

		}else{
			s->sgte=w;
			w->sgte=t;
		}
	}

}
void EliminarInicio(TpLista &lista){
	TpLista w=lista;
	lista=lista->sgte;
	delete(w);

}
void EliminarFinal(TpLista &lista){
 	TpLista t=lista, s=NULL;
 	while(t->sgte != NULL){
 		s=t;
 		t=t->sgte;
	 }
 	s->sgte=NULL;
 	delete(t);
}
void EliminarPosicion(TpLista &lista, int pos){
	TpLista t=lista, s=NULL;
	int x=1;
	bool flag=false;
	if(pos==1){
		EliminarInicio(lista);
		return;
	}
	while(	x!= pos && t->sgte != NULL ){
		s=t;
		t=t->sgte;
		x++;
		if(x==pos)
			flag=true;
	}
	if(flag == false){
		cout<<"Error, Posicion ingresada NO EXISTE.."<<endl;

	}else{
		s->sgte=t->sgte;
		delete(t);

	}
}
//


//Opciones
void opcion1(TpLista &lista){
    int num;
    do{
        cout<<"\nIngresar numero--> ";cin>>num;
        if(promedioLista(lista)==-1){
        	break;
		}

		cout<<"\nEl promedio es:"<<promedioLista(lista)<<endl;
    }while(num>promedioLista(lista));

	InsertarFinal(lista,CrearNodo(num));
	
}
void opcion2(TpLista &lista){
	int num,x=0,pos;
	do{
        cout<<"\nIngresar numero impar: ";cin>>num;
    }while(num%2==0);

    TpLista t=lista;
    while(t!= NULL){
		t=t->sgte;
		x++;
	}
	if(x%2==0){
		pos=x/2;
		pos= pos+1;
	}
	else{
		pos=(x+1)/2;
	}
	
	InsertarPosicion(lista,CrearNodo(num),pos);
}
void opcion3(TpLista &lista){
	TpLista t=lista;
	int x=0, menor=t->nro, menorPos=1;

	if(t!=NULL){
		while(t!= NULL){
			x++;
			if(t->nro<menor){
				menor=t->nro;
				menorPos=x;
			}
			t=t->sgte;
		}
		EliminarPosicion(lista,menorPos);
	}
	else{
		cout<<"Lista esta vacia."<<endl;
	} 
}
//


//Helper
int promedioLista(TpLista lista){
    TpLista t=lista;
    int suma=0, n=0, promediov;
	while(t != NULL ){
		suma= suma+t->nro;
		t=t->sgte;
		n++;
	}
	
	
	if(n==0){
		return(-1);
	}
	
	promediov=suma/n;
	return(promediov);
}
//


void menu(){
	system("CLS");
	cout<<"\n\t LISTA ENLAZADA SIMPLE\n\n";
	cout<<"1.- Insertar nodo menor a promedio al final "<<endl;
	cout<<"2.- Insertar nodo impar en el medio "<<endl;
	cout<<"3.- Eliminar minimo valor"<<endl;
	cout<<"4.- Mostrar lista "<<endl;
	cout<<"0.- Salir "<<endl<<endl;

	cout<<"Ingresar Opcion--->  "<<endl;
}
int main() {

	int posicion,opc, busca, reemp;
	TpLista lista=NULL;// variable gusrada el inicio de la lista

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
				opcion1(lista);
				VerLista(lista);
				system("pause");
				break;
				}

			case 2:{
				opcion2(lista);
				VerLista(lista);
				system("pause");
				break;
				}

			case 3:
			{
				opcion3(lista);
				VerLista(lista);
				system("pause");
				break;
				}
			case 4:{

				VerLista( lista);
				system("pause");
				break;
				}
		}

	}while(opc !=0);
	system("pause");
	return 0;
}

