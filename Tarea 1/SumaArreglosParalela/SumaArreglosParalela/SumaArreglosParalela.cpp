// SumaArreglosParalela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>
#include <cstdlib> 
#include <ctime> 

int main()
{
    //Definimos el tamaño de los arreglos mediente elección del usuario 
    std::cout << "Estableciendo el tamaño de los arreglos!\n ";
    int arr_size;
    std::cout << "Introduzca el tanaño de los arreglos: ";
    std::cin >> arr_size;
    //std::cout << "Arreglos creados, tamanio " << arr_size << std::endl;

    //Creamos los arreglos
    int* arreglo1 = new int[arr_size];
    int* arreglo2 = new int[arr_size];
    std::cout << "Arreglos creados, tamanio " << arr_size << std::endl;

    // Selección de llenado de los arreglos a mano o de manera aleatoria
    int user_option;
    std::cout << "\nSeleccione una opcion: \n";
    std::cout << "1. Insertar los valores de los arreglos automaticamente de manera aleatoria \n";
    std::cout << "2. Insertar los valores de los arreglos a mano \n";
    std::cout << "Inserte la opcion deseada: ";
    std::cin >> user_option;

    if (user_option == 1)
    {
        // Generar valores aleatorios
        std::srand(std::time(nullptr)); // Semilla para la generación aleatoria
        for (int i = 0; i < arr_size; ++i)
        {
            arreglo1[i] = std::rand() % 100; // Genera números entre 0 y 99
            arreglo2[i] = std::rand() % 100;
        }
        std::cout << "Valores generados aleatoriamente\n";
    }
    else if (user_option == 2)
    {
        // Permitir que el usuario introduzca los valores manualmente
        std::cout << "Introduce los valores para el arreglo A:\n";
        for (int i = 0; i < arr_size; ++i)
        {
            std::cout << "arreglo1[" << i << "] = ";
            std::cin >> arreglo1[i];
        }

        std::cout << "Introduce los valores para el arreglo B:\n";
        for (int i = 0; i < arr_size; ++i)
        {
            std::cout << "arreglo2[" << i << "] = ";
            std::cin >> arreglo2[i];
        }
    }
    else
    {
        std::cerr << "Opción inválida.\n";
        return 1;
    }

    // Definimos el tercer arreglo, que será la suma de los dos arreglos anteriores
    int* arreglo3 = new int[arr_size];

    //Realizamos la suma en paralelo
    #pragma omp parallel for
    for (int i = 0; i < arr_size; ++i)
    {
        arreglo3[i] = arreglo1[i] + arreglo2[i];
    }

    // Mostramos los valores de los arreglos
    std::cout << "\nValores del arreglo 1: ";
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << arreglo1[i] << " ";
    }
    std::cout << "\nValores del arreglo 2: ";
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << arreglo2[i] << " ";
    }
    std::cout << "\nValores del arreglo 3: ";
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << arreglo3[i] << " ";
    }
    std::cout << "\n";


}
