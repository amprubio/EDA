﻿// Amparo Rubio Bellon
// VJ50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<math.h>

// función que resuelve el problema
bool resolver(std::vector<int> datos, int k,int ini, int fin, int it) {
	return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, k;
	std::cin >> n;
	std::cin >> k;

	if (!std::cin)
		return false;


	std::vector<int> datos(n);
	for (int i = 0; i < n; i++) {
		int j;
		std::cin >> j;
		datos.push_back(j);
	}
	// escribir sol

	if (resolver(datos, k, 0, n,0)) {
		std::cout << "SI" << "\n";
	}
	else {
		std::cout << "NO" << "\n";
	}
	return true;

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif

	return 0;
}
