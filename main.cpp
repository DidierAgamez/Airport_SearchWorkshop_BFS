#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

int minimodeconexionesparatodaslasconexiones(const vector<string>& lista_aeropuerto, const vector<pair<string, string>>& vuelos, const string& aeropuerto_inicio) {
    unordered_map<string, vector<string>> grafi;
    for (const auto& vuelos : vuelos) {
        const string& fuen = vuelos.first;
        const string& dest = vuelos.second;
        grafi[fuen].push_back(dest);
    }

    deque<string> col;
    unordered_set<string> visit;
    string conexion_adicional = ""; 

    col.push_back(aeropuerto_inicio);
    visit.insert(aeropuerto_inicio);

    int step = 0; // 

    while (!col.empty()) {
        cout << "Recorrido " << step << ":" << endl;
        cout << "Espera: ";
        for (const string& aeropuerto : col) {
            cout << aeropuerto << " ";
        }
        cout << endl;
        cout << "Aeropuertos visitados: ";
        for (const string& aeropuerto : visit) {
            cout << aeropuerto << " ";
        }
        cout << endl;

        string aeropuerto_ubicado = col.front();
        col.pop_front();

        cout << "Aerupuerto actual: " << aeropuerto_ubicado << endl; // Mostrar el aeropuerto visitado

        if (grafi.find(aeropuerto_ubicado) != grafi.end()) {
            for (const string& cercano : grafi[aeropuerto_ubicado]) {
                if (visit.find(cercano) == visit.end()) {
                    visit.insert(cercano);
                    col.push_back(cercano);
                    
                    conexion_adicional = aeropuerto_ubicado + " hacia " + cercano;
                }
            }
        }

        step++;
    }

    int totaldeaeropuertos = lista_aeropuerto.size();
    int aeropuertosvisitados = visit.size();
    int min_conexiones = totaldeaeropuertos - aeropuertosvisitados;

    cout << "Conexión adicional necesaria: " << conexion_adicional << endl; 

    return min_conexiones;
}

int main() {
    vector<string> lista_aeropuerto = {"Perú", "Ecuador", "Colombia", "Panama", "Bolivia"};
    vector<pair<string, string>> vuelos = {{"Perú", "Ecuador"}, {"Ecuador", "Colombia"}, {"Colombia", "Panama"}, {"Panama", "Perú"}, {"Bolivia", "Panama"}};
    string aeropuerto_inicio = "Perú";

    cout << "El paso a paso del recorrido sería:" << endl;
    int result = minimodeconexionesparatodaslasconexiones(lista_aeropuerto, vuelos, aeropuerto_inicio);
    cout << "Número mínimo de conexiones adicionales necesarias: " << result << endl;

    return 0; 
}
