// Amparo Rubio
// VJ54


#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <math.h>  
#include <cmath>

// función que resuelve el problema
void resolver(int n) {

    std::vector<int>v;
    int aux=n;

    while (aux >= 0) {
        v.push_back(aux % 10);
        aux /= 10;
        if (aux == 0) {
            aux -= 1;
        }
    }
    int m= v.size();

    int comp=9 - v[m-1];
    int inv=9-v[0];

    for(int i=1; i<v.size();i++){
        comp*=10;
        inv*=10;

        comp+= 9 - v[m-1-i];
        inv+= 9 - v[i];
    }

    std::cout << comp << " " << inv << "\n";
    
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin>>n;

    // escribir sol
    resolver(n);
    
}
#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}