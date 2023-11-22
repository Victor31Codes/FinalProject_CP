#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

template <class T> struct Nodo {
  T info;
  Nodo<T> *sig;

  // Constructor por defecto
  Nodo() : info(), sig(nullptr) {}
};

template <class T> class Lista {
  Nodo<T> *cab;
  int tam;

public:
  Lista() {
    cab = NULL;
    tam = 0;
  };

  bool isEmpty() { return tam == 0; };

  // Método para insertar un elemento al inicio de la lista
  void startInsert(T valor) {
    Nodo<T> *nuevoNodo = new Nodo<T>;
    nuevoNodo->info = valor;
    nuevoNodo->sig = cab;
    cab = nuevoNodo;
    tam++;
  }

  // Método para insertar un elemento al final de la lista
  void endInsert(T valor) {
    Nodo<T> *nuevoNodo = new Nodo<T>;
    nuevoNodo->info = valor;
    nuevoNodo->sig = NULL;

    if (cab == NULL) {
      cab = nuevoNodo;
    } else {
      Nodo<T> *temp = cab;

      while (temp->sig != NULL) {
        temp = temp->sig;
      }

      temp->sig = nuevoNodo;
    }

    tam++;
  }

  // Método para insertar un elemento en posiciones ordenadas de la lista
  void sortedInsert(T valor) {
    Nodo<T> *nuevoNodo = new Nodo<T>;
    nuevoNodo->info = valor;
    nuevoNodo->sig = NULL;

    if (cab == NULL || cab->info >= valor) {
      nuevoNodo->sig = cab;
      cab = nuevoNodo;
    } else {
      Nodo<T> *temp = cab;

      while (temp->sig != NULL && temp->sig->info < valor) {
        temp = temp->sig;
      }

      nuevoNodo->sig = temp->sig;
      temp->sig = nuevoNodo;
    }

    tam++;
  };

  // Método para insertar un elemento en una posición determinada de la lista
  void insertByIndex(int posicion, T valor) {
    if (posicion < 0 || posicion > tam) {
      cout << "Index out of range";
    }

    if (posicion == 0) {
      startInsert(valor);
      return;
    }

    Nodo<T> *nuevoNodo = new Nodo<T>;
    nuevoNodo->info = valor;

    Nodo<T> *temp = cab;
    for (int i = 0; i < posicion - 1; i++) {
      temp = temp->sig;
    }

    nuevoNodo->sig = temp->sig;
    temp->sig = nuevoNodo;

    tam++;
  }

  // Método para obtener el tamaño de la lista
  int getTam() { return tam; }

  // Método para obtener un dato por índice
  T getByIndex(int indice) {
    if (indice < 0 || indice >= tam) {
      cout << "Index out of range";
    }

    Nodo<T> *temp = cab;
    for (int i = 0; i < indice; i++) {
      temp = temp->sig;
    }

    return temp->info;
  };

  // Método para eliminar un elemento por índice
  void removeByIndex(int indice) {
    if (indice < 0 || indice >= tam) {
      cout << "Índice fuera de rango." << endl;
      return;
    }

    Nodo<T> *temp = cab;
    Nodo<T> *anterior = NULL;

    // Mover temp al nodo en el índice especificado
    for (int i = 0; i < indice; i++) {
      anterior = temp;
      temp = temp->sig;
    }

    // Si es el primer elemento
    if (anterior == NULL) {
      cab = temp->sig;
    } else {
      anterior->sig = temp->sig;
    }

    // Liberar memoria del nodo
    delete temp;

    tam--;
  }
};

#endif

