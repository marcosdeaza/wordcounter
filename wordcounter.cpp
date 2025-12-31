//21 dic. 2025; wordcounter simple con fstream

#include <iostream>
#include <fstream>  // Para ver directorios y rutas de archivo
#include <string>   // Necesaria para usar variables tipo string

using namespace std;

int main() {
    string palabraBuscada;
    string palabraLeida;
    int contador = 0;

    // 1. Pedir la palabra al usuario
    cout << "Introduce la palabra que quieres buscar en el Quijote: ";
    cin >> palabraBuscada;

    // 2. Abrir el archivo
    ifstream archivo("Quijote_cap_1.txt");

    // 3. Leer palabra por palabra
    while (archivo >> palabraLeida) {
        
        // Tenemos que quitar comas y puntos para comparar bien.
        // Ejemplo: Si "Mancha," se busca "Mancha".
        
        string palabraLimpia = "";
        
        // Recorrer la palabra leida letra por letra
        for (int i = 0; i < palabraLeida.length(); i++) {
            char letra = palabraLeida[i];
            
            // Si la letra NO es un signo de puntuación básico, la guardamos.
            if (letra != '.' && letra != ';' && letra != ',' && letra != ':' && letra != '(' && letra != ')') {
                palabraLimpia += letra;
            }
        }

        // 4. Comparar
        if (palabraLimpia == palabraBuscada) {
            contador++;
        }
    }

    // 5. Cerrar archivo y mostrar resultado
    archivo.close();

    cout << "La palabra '" << palabraBuscada << "' aparece " << contador << " veces en el capitulo." << endl;

    return 0;
}