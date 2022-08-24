// Comparation.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<algorithm>
#include <random>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
 

size_t MAX = 10000;
using namespace std;
double **A;
double *x;
double *y;
void FillArrayY() {
    //Memoria Dinamica
    y = new double[MAX];
    //Inicializar con valores aleatorios 
    for (double*i = y; i < y+MAX; i++) 
        *i = 0;
}
void FillMatrixA () {
    //Memoria Dinamica
    A = new double*[MAX];
    for (int i = 0; i < MAX; ++i)
        A[i] = new double[MAX];
    //Inicializar con valores aleatorios 
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1, 1000);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            A[i][j] = dis(gen);
    }
}

void FillArrayX() {
    //Memoria Dinamica
    x = new double[MAX];
    //Inicializar con valores aleatorios 
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1, 1000);
    for (int i = 0; i < MAX; i++) {
            x[i] = dis(gen);
    }
}

void print(double* arr) {
    for (double *i = arr; i < arr+MAX; i++) 
          cout<<*i;
}
void printA() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout<<A[i][j]<<" ";
    }
    cout << endl;
}

//Antes de ejecutar estas funciones se debe tener en cuenta lo siguiente
// la matriz A y el array x deben tener valores, es de decir inicializados
// los valores del array y deben ser 0
void firstLoop() {

    chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j];
    }
    end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "first: " << elapsed_seconds.count() << "s\n";

}

void secondLoop() {
    FillArrayY();
    chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j] * x[j];
    }
    end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "second: " << elapsed_seconds.count() << "s\n"; 

}



int main(){
    //cout << "Array x" << endl;
    FillArrayX();
    //print(x);
    //cout << "Array y" << endl;
    FillArrayY();
    //print(y);
    //cout << "Matrix A" << endl;
    FillMatrixA();
    //printA();
    firstLoop(); cout << endl;
    //cout << "y FL" << endl;
    //print(y); cout << endl;
    secondLoop(); cout << endl;
    //cout << "y SL" << endl;
    //print(y); 

    /// Deletes por la memoria dinamica
    for (int i = 0; i < MAX; ++i)
        delete[] A[i];
    delete[] A;
    delete[] x;
    delete[] y;
   
}


