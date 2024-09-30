/******************************************************************************
NOMBRES:
Sebastian Lopez  
Constanza Olivos
Eduardo Santana 

Profesor: Leonardo Bravo 
Seccion: 413 

*******************************************************************************/
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//******************************FUNCION 1: BNF*********************************// 

int noesletra(char bnf)
{
  string letra="abcdefghijklmnñopqrstuvwxyz0123456789";
  for (int j=0;j<38;j++)
    {
      char le=letra[j];
      if (bnf==le)
        return 0;
    }
  return 1;
}
int es_num(char bnf)
{
  string nu="1234567890";
      for(int j=0;j<10;j++)
        {
          char n=nu[j];
          if(bnf==n)
            return 1;
        }
    
  return 0;
}
void BNF()
{
  string num="1234567890";
  string bnf;
  cout<<"Ingrese la secuencia que desea evaluar para las reglas sintácticas:"<<endl;
  cin>>bnf;
  int tamaño= bnf.size();
  for(int i=0;i<tamaño;i++)
    {
    char bnf_=bnf[i];
    if(es_num(bnf_))
    {
      char bnf__=bnf[i-1];
      if (es_num(bnf__))
      {
        goto L1;
       

      }
      
    }
    }
  for (int j=0;j<tamaño;j++)
    {
    char bnf_2=bnf[j];
    if(noesletra(bnf_2))
    {
      goto L1;
    }
    
    }
  goto L2;
  L1:cout<<"La expresión no cumple con las reglas bnf"<<endl;
  return;
  L2:cout<<"La expresión sí cumple con las reglas sintácticas"<<endl;
}
int fhash(int dato)
{
  return dato%8;
}
struct Nodo{
int n;
Nodo* link;
};
class Tabla_Hash{
private:
Nodo* Arreglo[8];
public:
Tabla_Hash()
{
  for (int i=0; i<32; i++)
    Arreglo[i]=nullptr;
}
void Push(int dato)
{
  int indice=fhash(dato);
  Nodo* nuevoNodo= new Nodo;
  nuevoNodo->n=dato;
  nuevoNodo->link=nullptr;
  if(Arreglo[indice]==nullptr)
  {
    Arreglo[indice]=nuevoNodo;
  }
  else{
    Nodo* aux=aux=Arreglo[indice];
    while(aux->link!=nullptr)
      {
        aux=aux->link;
      }
    aux->link=nuevoNodo;
  }
}
int buscar(int dato)
{
  int indice=fhash(dato);
  Nodo* aux= Arreglo[indice];
  while(aux!=nullptr)
    {
      if (aux->n==dato)
        return 1;
      aux=aux->link;
    }
  return 0;
}
void despliegue()
{
  for(int i=0; i<8; i++)
    {
      Nodo* aux=Arreglo[i];
      while(aux!=nullptr)
        {
          cout<<aux->n<<"   ";
          aux=aux->link;
        }
      cout<<endl;
    }
}
};



//************************FUNCION 2: Tabla Hash********************************//

void Menu_TH(Tabla_Hash& tabla)
{
  
  int opc, datos;
  do{
  cout<<"Seleccione una opción:"<<endl;
  cout<<"1. Ingresar datos"<<endl<<"2. Buscar un dato"<<endl<<"3. Mostrar los datos de la estructura"<<endl<<"4. Salir"<<endl;
    cin>>opc;
    switch(opc){
      case 1:
        
  cout<<"Ingrese los 32 valores que desea agregar a la estructura"<<endl;
  for(int i=0 ; i<32; i++)
    {
      cin>>datos;
      tabla.Push(datos);}
    break;
      case 2: 
        cout<<"Ingrese el dato que desea buscar"<<endl;
        int dato_b;
        cin>>dato_b;
      if(tabla.buscar(dato_b))
        cout<<"Se ha encontrado el dato"<<endl;
      else
        cout<<"El dato buscado no se presenta en la estructura"<<endl;
      break;
      case 3:
      tabla.despliegue();
      break;
     
      
    }
      
  }while(opc!=4);
  
}


//*************************** FUNCION 3 Nº3= CONJUNTOS************************* //

void conjuntos(){
int n;
int arregloalm[n];

//******************************LLENADO DE ARREGLOS*****************************//
  
   cout << "ingrese tamaño para los conjuntos A y B \n ";
  cin>> n;
 while(n<1 || n>15){
  cout<< "numero sobrepasa el maximo permitido, ingrese entre 1 y 15  \n";

  cin>> n;
  
     
 }
  int arregloA[n];
  int ArregloB[n];
  int arregloC[n];
  
  cout << "LLENADO DEL CONJUNTO A" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese un número para el conjunto A: ";
        int valorArregloA;
        cin >> valorArregloA;

        while (valorArregloA < 1 || valorArregloA > 15) {
            cout << "Numero inválido,ingrese otro numero (entre 1 y 15): ";
            cin >> valorArregloA;
        }
        
        arregloA[i] = valorArregloA;
    }
    
cout << "LLENADO DEL CONJUNTO B" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese un número para el conjunto B: ";
        int valorArregloB;
        cin >> valorArregloB;

        while (valorArregloB < 1 || valorArregloB > 15) {
            cout << " Ingrese otro número (entre 1 y 15): ";
            cin >> valorArregloB;
        }
        ArregloB[i] = valorArregloB;
    }
    
    
// ********************INTERSECCION**************************************************//
  
  cout << "los valores que se intersectan entre los arreglos son:" ;
  for (int i = 0; i < n; i++) {
      
   int valorArregloA = arregloA[i];
    
    for (int j = 0; j < n; j++){
     int valorArregloB = ArregloB[j];
      
      if (valorArregloA == valorArregloB) {
        cout<< arregloA[i] << " ";
      }
    }
  }
  


//*********************************UNION********************************************
 cout << endl << "la union entre los arreglos es: ";
  for (int i=0; i < n; i++)
  {
    int valorArregloA = arregloA[i];
    for (int j = 0; j < n; j++){
      int valorArregloB = ArregloB[j];
      if (valorArregloA != valorArregloB) {
        arregloC[j] = valorArregloB;
      }
    }
        cout<< arregloC[i] << " ";
  }
  for (int i=0; i < n; i++)
  {
    int valorArregloB = ArregloB[i];
    for (int j = 0; j < n; j++){
      int valorArregloA = arregloA[j];
      if (valorArregloA != valorArregloB) {
        arregloC[j] = valorArregloA;
      }
    }
    cout<< arregloC[i] << " ";
  }
  
  
//**********************DIFERENCIA*******************************************
   
  cout << endl << "la diferencia A-B  es:";
  for (int i=0; i < n; i++)
  {
    int valorArregloA = arregloA[i];
    for (int j = 0; j < n; j++){
      int valorArregloB = ArregloB[j];
      if (valorArregloA != valorArregloB) {
     
       arregloalm[j]= valorArregloA;
      }
    }
    cout<< arregloalm[i] << "";
  }


cout << endl << "la diferencia B-A  es:";
  for (int i=0; i < n; i++)
  {
    int valorArregloB = ArregloB[i];
    for (int j = 0; j < n; j++){
      int valorArregloA = arregloA[j];
      if (valorArregloB != valorArregloA) {
     
       arregloalm[j]= valorArregloB;
      }
    }
    cout<< arregloalm[i] << "";
  }
}

 
//**************************************************************************************
//************************************************************************************
 
 //FUNCION 4 = MATRIZ TRIANGULAR
 
 
 
void CrearM(int a[10][10], int tamaño)
{
  int valor;
  int aux=tamaño-2;
  int auxx=tamaño-1;
  for(int i=0;i<=tamaño-2;i++)
    {
    for(int j=0; j<=aux;j++)
      {
      a[i][j]=0;
      }
    aux=aux-1;
    }
  for(int k=0;k<tamaño;k++)
    {
    for (int l=tamaño-1;l>=auxx;l--)
      {
      L2:
      cout<<"Ingrese un valor"<<endl;
      cin>>valor;
      if(valor==0)
      {
        cout<<"Por favor vuelva a ingresar un valor distinto a 0"<<endl;
        goto L2;
      }
      a[k][l]=valor;
      }
    auxx=auxx-1;
    }
}
void Desplegar(int a[10][10], int tamaño)
{
  for(int i=0; i<tamaño; i++){
    for (int j=0;j<tamaño;j++)
    {
    cout<<a[i][j]<<" ";
    }
  cout<<endl;
  }
  
}

struct Nud{
  Nud *link;
  int i;
  int j;
  int k;
  int valor;
  
  };
  class Matrix{
  private: Nud* M;
  public: 
  Matrix()
{
  M=nullptr;
}
void Push(int tama, int dato, int ii, int jj, int kk)
{
  
  Nud* nuevoM= new Nud;
  nuevoM->i=ii;
  nuevoM->j=jj;
  nuevoM->valor=dato;
  nuevoM->k=kk;
  nuevoM->link=nullptr;
  if(M==nullptr)
  {
    M=nuevoM;
  }
  else{
    Nud* aux=M;
    while(aux->link!=nullptr)
      {
        aux=aux->link;
      }
    aux->link=nuevoM;
  }
}
void buscar(int ii, int jj)
{
  Nud* aux=M;
  while (aux!=nullptr)
    {
      if(aux->i==ii && aux->j==jj)
      {cout<<"El elemento se ha encontrado y su valor y dirección k corresponde a:  "<<aux->valor<<" y "<<aux->k<<endl;
      goto L1;
      }
        aux=aux->link;
    }
  cout<<"No se ha encontrado el elemento en la estrucutra de datos vectorial"<<endl;
  L1:
  return;
}
void despliegue()
{
  Nud* aux=M;
  while(aux!=nullptr)
    {
      cout<<"valor: "<<aux->valor<<" indice i: "<<aux->i<<" indice j: "<<aux->j<<" indice k: "<<aux->k<<endl;
      aux=aux->link;
    }
}

void Llenar(int a[10][10], int tama)
{
  float multi=1.5 + (tama-2.)/2.;
  int longitud=tama*multi;
  int auxx=tama-1;
  int f=1;
      for(int k=0;k<tama;k++)
    {
    for (int l=tama-1;l>=auxx;l--)
      { 
      Push(tama, a[k][l], k, l, f);
        f++;
      }
    auxx=auxx-1;
    }
    
}
void Guardar(int tama)
{
 
  ofstream archivo;
  archivo.open("Vector.txt", ios::out);
  if(archivo.fail())
  {
    cout<<"Error. No se ha podido crear el archivo."<<endl;
    exit(1);
  }
   Nud* aux=M;
  while(aux!=nullptr)
    {
      archivo<<aux->valor<<endl;
      aux=aux->link;
    }
    cout<<"Se ha creado el archivo exitosamente"<<endl;
}
void Menu(int a[10][10])
{
  
  int busqi;
  int busj;
  int opc;
  int tam;
  int b[10][10];
  do{
  cout<<"Seleccione una opción"<<endl;
  cout<<"1. Crear Matriz"<<endl;
  cout<<"2. Desplegar Matriz"<<endl;
  cout<<"3. Crear vector con datos significativos"<<endl;
  cout<<"4. Mostrar datos del vector"<<endl;
  cout<<"5. Buscar dato en el vector"<<endl;
  cout<<"6. Guardar vector en bloc de notas"<<endl;
  cout<<"7. Salir"<<endl;
  cin>>opc;
  switch (opc)
    {
      case 1:
        L3:
      cout<<"Ingrese el tamaño de la matriz (máximo 10)"<<endl;
      cin>>tam;
      if(tam>10)
      {
        cout<<"Ingrese un tamaño válido"<<endl;
        goto L3;
      }
      CrearM(b,tam);
      break;
      case 2:
        if (tam<1 && tam>10)
        {
          cout<<"No se ha ingresado una matriz"<<endl;
          return;
        }
        Desplegar(b,tam);
      break;
      case 3:
      Llenar(b,tam);
      break;
      case 4:
      despliegue();
      break;
      case 5:
        cout<<"Ingrese las coordenadas a buscar en el vector"<<endl;
        cin>>busqi;
        cin>>busj;
      buscar(busqi, busj);
      break;
      case 6:
        if(M==nullptr)
        {
          cout<<"Error. El vector está vacío"<<endl;
          break;
        }
      Guardar(tam);
      break;
      case 7:
      return;
      
    }
    }while(opc!=7);
  cout<<"Se ha finalizado el programa exitosamente"<<endl;
}
};

//******************************************************************************

/* FUNCION Nº5= Obtener el producto de Wallis: 


A)Implementación recursiva que muestre claramente en forma gráfica, la evolución del 
 stack de ejecución en cada una de las etapas de llamada y retorno. Comprobar la 
 ejecución detallada con n=60.
 
*/

float wallis(int n){

    float aux;
    
    if(n==0){
        
        cout<<"Lugar = "<<n;
        cout<<" -> ";
        cout<<"Valor = 1"<<endl;
        return 1;

    }
    
    
    
    else{
        
        if(n%2==0){ //par
        
            aux=(((float)(n)/(n+1))*wallis(n-1));
            cout<<"Lugar = "<<n;
            cout<<" -> ";
            cout<<"Valor = "<<aux<<endl;
            return aux;
           
        }

        if(n%2==1){ //impar
            
            aux=(((float)(n)+1)/(float)(n))*wallis(n-1);
            cout<<"Lugar = "<<n;
            cout<<" -> ";
            cout<<"Valor = "<<aux<<endl;
            return aux;

            
        }
    }
    
    
    return n;
}

/* FUNCION Nº5= Obtener el producto de Wallis: 

B) Mostrar una segunda versión de la función implementada, pero esta vez utilizando
la estrategia de recursividad de cola.
*/



float wallisCola(int n, float aux){

    
    if(n==0){
        return aux;
    }
    
    else{
 
        if(n%2==0){ //par
            
            return wallisCola(n-1,((float)(n)/(n+1))*aux);
        }

        if(n%2==1){ //impar
         
            return wallisCola(n-1,(((float)(n)+1)/(float)(n))*aux);
        }
    }
    
    
    return n;
}



int main() {
  Tabla_Hash tablita;
  int opc;
  int opk;
  Matrix M;
  int a[10][10];
  int n=60;
  float aux=1;
  do{
  cout<<"\nBienvenido al Menú: Escoge la opción que deseas:\n"<<endl;
  cout<<"1. Reconocer secuencias mediantes las reglas BNF:"<<endl;
  cout<<"<S> ::= <D> | <D> <E>| <E>"<<endl;
  cout<<"<E> ::= <L> | <L> <S>"<<endl;
  cout<<"<D> ::= 0 | 1 | 2 | … | 9"<<endl;
  cout<<"<L> ::= a | b | c | … | z"<<endl<<endl;
  cout<<"2. Utilizar tabla Hash de cardinalidad 32"<<endl;
  cout<<"3. Conjuntos"<<endl;
  cout<<"4. Matrices"<<endl;
  cout<<"5. Menú Productos de Wallis"<<endl;
  cout<<"6. Salir"<<endl;
    cin>>opc;
    switch(opc){
      case 1: BNF();
      break;
      case 2: Menu_TH(tablita);
      break;
      case 3: conjuntos();
      break;
      case 4:
      M.Menu(a);
      break;
      case 5:
      
        do{
          cout<<"Escoja una opción"<<endl;
          cout<<"1. Producto de Wallis sin recursividad de cola"<<endl;
          cout<<"2. Producto de Wallis con recursividad de cola"<<endl;
          cout<<"3. Salir"<<endl;
          cin>> opk;
          switch(opk)
            {
              case 1: 
              wallis(n);
                break;
              case 2:
                cout<<"Resultado final = "<<wallisCola(n, aux)<<endl;
              break;
            }
        }while(opk!=3);
      break;
      
    }
}while(opc!=6);
return 0;
}