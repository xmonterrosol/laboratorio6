#include<iostream>
#include <string>

using namespace std;

// Clase base: Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    double precio;

public:
    Vehiculo(string marca, string modelo, double precio) {
        this->marca = marca;
        this->modelo = modelo;
        this->precio = precio;
    }

    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Precio: " << precio << endl;
    }

    string getMarca() { return marca; }
    void setMarca(string marca) { this->marca = marca; }

    string getModelo() { return modelo; }
    void setModelo(string modelo) { this->modelo = modelo; }

    double getPrecio() { return precio; }
    void setPrecio(double precio) { this->precio = precio; }
};

// Clase derivada: Automovil
class Automovil : public Vehiculo {
private:
    int numPuertas;

public:
    Automovil(string marca, string modelo, double precio, int numPuertas)
        : Vehiculo(marca, modelo, precio) {
        this->numPuertas = numPuertas;
    }

    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << "Número de puertas: " << numPuertas << endl;
    }

    int getNumPuertas() { return numPuertas; }
    void setNumPuertas(int numPuertas) { this->numPuertas = numPuertas; }
};

// Clase derivada: Motocicleta
class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string marca, string modelo, double precio, int cilindrada)
        : Vehiculo(marca, modelo, precio) {
        this->cilindrada = cilindrada;
    }

    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }

    int getCilindrada() { return cilindrada; }
    void setCilindrada(int cilindrada) { this->cilindrada = cilindrada; }
};

// Clase derivada: Camioneta
class Camioneta : public Vehiculo {
private:
    double capacidadCarga;

public:
    Camioneta(string marca, string modelo, double precio, double capacidadCarga)
        : Vehiculo(marca, modelo, precio) {
        this->capacidadCarga = capacidadCarga;
    }

    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << "Capacidad de carga: " << capacidadCarga << " kg" << endl;
    }

    double getCapacidadCarga() { return capacidadCarga; }
    void setCapacidadCarga(double capacidadCarga) { this->capacidadCarga = capacidadCarga; }
};

// Clase: Cliente
class Cliente {
private:
    string nombre;
    int edad;

public:
    Cliente(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }

    void comprarVehiculo(Vehiculo* vehiculo) {
        cout << nombre << " ha comprado un " << vehiculo->getMarca() << " " << vehiculo->getModelo() << endl;
    }

    string getNombre() { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    int getEdad() { return edad; }
    void setEdad(int edad) { this->edad = edad; }
};

int main() {
    Cliente cliente("Juan", 30);
    Automovil automovil("Toyota", "Corolla", 20000, 4);
    Motocicleta motocicleta("Honda", "CBR500R", 8000, 500);
    Camioneta camioneta("Ford", "F-150", 40000, 2000);

    cliente.comprarVehiculo(&automovil);
    automovil.mostrarInfo();

    cout << endl;

    cliente.comprarVehiculo(&motocicleta);
    motocicleta.mostrarInfo();

    cout << endl;

    cliente.comprarVehiculo(&camioneta);
    camioneta.mostrarInfo();

    return 0;
}

