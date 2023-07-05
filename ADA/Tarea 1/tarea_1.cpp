#include <iostream>
using namespace std;

//variables globales para vector fijo
int gVect[100]; //vector de tamaño fijo
int gnCount=0; //contador de elementos

//funcion para llenar el vector de tamaño fijo
void Insert(int elem){
    if(gnCount<100) //siempre que no esté lleno se puede continuar llenando
        gVect[gnCount++] = elem; //llena en el último elemento en el que el contador dice que tenemos espacio
}

//variables globales para vector dinamico
int *gpVect = NULL; //vector de tamaño dinamico
int gnCount = 0; //contador de elementos-espacios utilizados 
int gnMax = 0; //tamaño de la memoria asignada al vector dinamico

//funcion para cambiar el tamaño del vector dinamico
void Resize_(){
    const int delta = 10; //un valor definido con el que aumentamos memoria del vector
    realloc(gpVect, sizeof(int) * (gnMax + delta)); //reasigna el espacio de memoria de gpVect
    //como otra opcion se tiene el siguiente codigo:
    // int *pTemp, i;
    // pTemp = new int[gnMax + delta]; //crea un vector temporal con la memoria reasignada
    // for(i = 0 ; i < gnMax ; i++) //copia los elementos del primer vector
    // pTemp[i] = gpVect[i]; //copia en su posicion correspondiente
    // delete [ ] gpVect; //elimina el vector anterior
    // gpVect = pTemp; //actualiza el puntero al nuevo temporal
    gnMax += delta; //la memoria máxima se actualiza
}

//funcion para llenar el vector de tamaño dinamico
void Insert_(int elem){
    if(gnCount==gnMax) //cuando el iterador es igual al máximo de elementos
        Resize_(); //cambiar el tamaño del vector antes de insertar
    gVect[gnCount++] = elem; //llena en el último elemento en el que el iterador se encuentra
}

//funcion que reasigna memoria en el vector no global
void Resize_1(int *& rpVect, int& rnMax){
    const int delta = 10; //constante de aumento de tamaño del vector
    realloc(rpVect, sizeof(int) * (rnMax + delta));
    rnMax += delta; //incrementa el máximo del tamaño del vector
}

//funcion insertar para más de un vector no global
void Insert_1(int *& rpVect, int& rnCount, int& rnMax, int elem){
    if( rnCount == rnMax ) //compara que no haya más espacio
        Resize_1(rpVect, rnMax); //cambia el tamaño de la memoria asignada del vector rpVect
    rpVect[rnCount++] = elem; //inserta el elemento al final del vector
}

//agrupamiento de los datos de un vector en una estructura
struct Vector{
    int *m_pVect, //puntero al vector
    m_nCount, //contador de elementos insertados
    m_nMax, //cantidad de memoria asignada al vector
    m_nDelta; //control de crecimiento de la memoria en caso de exceso
};

//funcion que recibe datos de la estructura vector para redimensionar el vector
void Resize_2(Vector *pThis){
    realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    //incrementa el maximo en delta
    pThis->m_nMax += pThis->m_nDelta;
}

//funcion que recibe datos dela estructura vector para insertar elementos
void Insert_2(Vector *pThis, int elem){
    if( pThis->m_nCount == pThis->m_nMax ) //comprueba que no queden espacios libres
        Resize_2(pThis); //aumenta el tamaño antes de insertar el elemento
    //inserta el elemento al final del vector
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

//Clase CVector
class CVector{
    private:
        int *m_pVect, //puntero al vector
        m_nCount, //contador de elementos usados
        m_nMax, //contador de elementos máximos
        m_nDelta; //constante de aumento del vector
        void Init(int delta); //inicia las variables privadas
        void Resize_3(); //cambia el tamaño del vector cuando no queda memoria
    public:
        CVector(int delta = 10); //constructor
        void Insert_3(int elem); //inserta nuevos elementos
        //aqui van el resto de métodos a agregar
};

//método de la clase CVector
void CVector::Insert_3(int elem){
    if( m_nCount == m_nMax ) //comprueba que no haya espacios
        Resize_3(); //cambia el tamaño del vector
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

//clase CVector genérica 
typedef int Type;
class CVector_{
    private:
        Type *m_pVect; //puntero al vector genérico
        //más atributos
    public:
        void Insert(Type elem); //inserta un elemento genérico
        //más métodos
};

//clase CVector_1 usando templates
template <typename Type> class CVector_1{
    private:
        Type*m_pVect; //puntero al vector de tipo Type
        int m_nCount, //contador de elementos usados
        m_nMax, //contador el elementos máximos
        m_nDelta; //constante de aumento de memoria
        void Init(int delta); //inicializa las variables privadas
        void Resize(); //aumenta la asignacion de memoria cuando no queda espacios libres
    public:
        CVector_1(int delta = 10); //Constructor
        void Insert(Type &elem); //Inserta nuevo elemento
        //más métodos
};

//Implementacion de la clase CVector_1 genérica
template <typename Type> CVector_1<Type>::CVector_1(int delta){
    Init(delta); //inicializa las variables privadas
}
template <typename Type> void CVector_1<Type>::Insert(Type &elem){
    if( m_nCount == m_nMax ) //comprueba que no haya mas espacios libres
        Resize(); //asigna más memoria al vector antes de insertar
    m_pVect[m_nCount++] = elem; //inserta un elemento al final del vector
}

#include <vector> //sin ".h"
#include <list>

//funcion para imprimir e iterar a través de un contenedor de tipo genérico
template <typename Container> void Write(Container &ds, ostream &os){
    Container::iterator iter = ds.begin();
    for( ; iter != ds.end() ; iter++ )
        os << *iter << "\n"; 
}
//se prueba en un main con una dos clases de la librería estandar con list y vector
int main(int argc, char* argv[]){
    list<float> mylist;
    vector<float> myvector;
    for( int i = 0 ; i < 10 ; i++ ){
        mylist .push_back( i );
        myvector.push_back(i+50);
    }
    Write(mylist, cout);
    Write(myvector, cout);
    return 0;
}

class CMyComplexDataStructure{
    vector<float> m_container;
    public:
    void Insert(float fVal) { m_container.push_back(fVal); }
    template <typename objclass>
    void sumone(objclass funobj){
        vector<float>::iterator iter = m_container.begin();
        for (; iter != m_container.end() ; iter++)
            funobj(*iter);
    }
};
template <typename objclass>
class funcobjclass{
    public:
    void operator  ()(objclass& objinstance){
        objinstance++;
    }
};
int main(int argc, char* argv[])
{
CMyComplexDataStructure ds;
ds.Insert(3.5);
ds.Insert(4.5);
ds.Insert(6.5);
ds.Insert(3.9);
funcobjclass<float> x;
ds.sumone(x);
return 0;
}
