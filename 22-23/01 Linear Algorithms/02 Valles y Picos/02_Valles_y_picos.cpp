// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(const std::vector<int>& v,int & picos, int & valles) {
    int k=2;
    while(k<v.size()){
        if (v[k - 1] > v[k] && v[k - 2] < v[k - 1]) {
			picos++;
		}
		else if (v[k - 1] < v[k] && v[k - 2] > v[k - 1]) {
			valles++;
		}
		k++;
    }

    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin>>n;
    std::vector<int> v(n);

    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    int valles=0, picos=0;
    resolver(v,picos,valles);
    // escribir sol
    std::cout << picos << " " << valles << "\n";
    
}

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