#include <iostream>
#include <array>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

void plano() {
    int xycero[2] = { 100,500 };
    int xytop[2] = { 100,100 };
    int xyfin[2] = { 800,500 };
    line(xycero[0], xycero[1], xytop[0], xytop[1]);
    line(xycero[0], xycero[1], xyfin[0], xyfin[1]);
}
void puntos(int A[], int i, int x, int div)
{
    line(x, 500 - (A[i] / div), x + 1, 500 - (A[i + 1] / div));
}
void texto(int x, int y, int A) {
    ostringstream str1;
    str1 << A;
    string str2 = str1.str();
    char* str = &str2[0u];
    //settextstyle(DEFAULT_FONT, 0, 3);
    outtextxy(x, y, str);

}
void putText(int A[]) {
    texto(90, 500, 0);
    texto(80, 400, A[(700 / 4)]);
    texto(80, 300, A[(700 / 2)]);
    texto(80, 200, A[(700 / 4) * 3]);
    texto(80, 100, A[699]);
    for (int i = 0; i < 8; i++)
        texto(((700 / 8) * i) + 100, 500, (700 / 8) * i);
    texto(800, 500, 700);
}
void grafico(int A[]) {
    plano();
    int x = 100;
    int tope = A[699];
    int div = tope / 400;
    for (int i = 0; i < 699; x++, i++) {
        puntos(A, i, x, div);
    }
    putText(A);
}

int funcion1(int N) {	//(n+1) + n + n/2   ->   O(n)
    int cont = 0;
    for (int i = 0; i <= N; i++, cont++) { //n+1
        cont++;
        if (i % 2 == 0) {	////n
            //cout << "I=" << i << endl; //(n/2)+1
            cont++;
        }

    }
    //cont++;  a la hora de hacer con un for no es necasario poner el cont++ al final
    return cont;
}

int funcion2(int N) {	// n^2
    int cont = 0;
    for (int i = 0; i <= N; i++, cont++) {	// n
        for (int j = i; j <= N; j++, cont++) {	// n^2
            //cout << i << "," << j << endl;	//
            cont++;
        }
    }
    return cont;
}

int funcion3(int A[], int B[]) {	//la multiplicacion de A*B
    int cont = 0;
    for (int i = 0; i < sizeof(A) / sizeof(*A); cont++, i++) {
        for (int j = 0; j < sizeof(B) / sizeof(*B); cont++, j++) {
            cout << A[i] << "," << B[j] << endl;
            cont++;
        }
    }
    return cont;
}

void valores(int (*f)(int), int A[700]) {
    for (int i = 1; i <= 700; i++) {
        //cout << f(i) << endl;
        A[i - 1] = f(i);
    }
}

void valores2(int (*f)(int[], int[]), int A[700], int a[], int b[]) {
    for (int i = 1; i <= 700; i++) {
        //cout << f(i) << endl;
        A[i - 1] = f(a, b);
    }
}


void make(int (*f)(int), int A[]) {
    valores(f, A);
    grafico(A);
}

void make2(int (*f)(int[], int[]), int A[], int a[], int b[]) {
    valores2(f, A, a, b);
    grafico(A);
}
void llenarConCeros(int arr1[], int arr2[]) {
    for (int i = 0; i < 700; i++) {
        arr1[i] = 0;
        arr2[i] = 0;
    }
}


int main()
{
    
    initwindow(900, 600,"Graficos");
    //int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int A[700] = { 0 };
    //int B[700] = { 0 };
    //llenarConCeros(A, B);
    make(funcion2,A);
    //make2(funcion3, A,A,B);
    //cout << funcion3(A, B);
    getch();
    closegraph();
    return 0;

}
