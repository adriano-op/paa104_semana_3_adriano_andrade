#include <cstdlib>
#include <vector>
#include <climits>
#include <math.h>

using point = std::pair<double, double>;
using namespace std;

#include<iostream>
#include <cstring>
#include <ctime>
#include <bits/stdc++.h>

#define tamMatriz 5

#include<map>


void printVector(std::vector<int> &v) {
    for (auto i = v.begin(); i != v.end(); ++i) {
        std::cout << *i << " | ";
    }
    std::cout << "\n" << endl;
}

template<class T>
vector<T> insertSort(vector<T> &v) {
    vector<T> vetor(v.size());
    vetor = v;
    for (int i = 0; i < (int) vetor.size(); i++) {
        int v = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > v) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = v;
    }
    return vetor;
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}


void gp(vector<int> current_path, vector<int> to_do) {
    for (int i = 0; i < to_do.size(); i++) {
        vector<int> path(current_path);
        path.push_back(to_do[i]);
        vector<int> left_to_do(to_do);
        left_to_do.erase(left_to_do.begin() + i);

        gp(path, left_to_do);
    }


    printVector(current_path);
}

void generation(int n) {
    vector<int> current_path = {}; // tirando o 0, ele gera para todas as cidades
    vector<int> to_do;

    for (int i = 0; i < n; i++) {
        to_do.push_back(i);
    }

    gp(current_path, to_do);
}


int inicializaArray(int n) {
    int v[n];
    int tam = sizeof(v) / sizeof(int);
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
    printArray(v, tam);
    //  return v;
}

std::vector<int> inicializaVector(std::vector<int> &v, int n) {

    //  int tam = sizeof(v)/sizeof(int);
    for (int i = 1; i < n + 1; i++) {
        v.push_back(i);
    }
    printVector(v);
    return v;
}

void inicializaVetorRandom(int v[], int tam) {
    unsigned seed = time(0);
    srand(seed);

    for (int i = 0; i < tam; i++) {
        v[i] = 1 + rand() % 1000;
    }
    std::cout << " " << endl;
}

void inicializaVectorRandom(vector<int> &nums, int tam) {
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < tam; i++) {
        nums.push_back(1 + rand() % 1000);
    }
}


void nPermute(string str, long int n) {
    // Sort the string in lexicographically
    // ascending order
    sort(str.begin(), str.end());

    // Keep iterating until
    // we reach nth position
    long int i = 1;
    do {
        // check for nth iteration
        if (i == n)
            break;

        i++;
    } while (next_permutation(str.begin(), str.end()));

    // print string after nth iteration
    cout << str;
}

// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>


vector<vector<int>> lexic(int n) {
    vector<vector<int>> permutations;
    vector<int> permutation;

    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }

    permutations.push_back(permutation);
    bool dir = false;
    do {
        int i = 0;
        for (int k = 0; k < n - 1; k++) {
            if (permutation[k] < permutation[k + 1]) {
                i = k;
            }
            dir = (i == -1);
        }

        if (!dir) {
            int j = i;

            for (int k = i; k < n ; k++) {
                if (permutation[i] < permutation[k]) { // O (n * n! )
                    j = k;
                }
            }
            std::swap(permutation[i], permutation[j]);
            std::reverse(permutation.begin() + (i + 1), permutation.end());
            permutations.push_back(permutation);
        }


    } while (!dir);
}

void printmatriz(vector<vector<int>> &permutacao) {
    for (std::vector<int> p: permutacao) {
        for (int el: p) {
            std::cout << el << endl;
        }

    }
}

// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void lexicographicPermute(  string str, int inicio, int fim) {
    std::vector<int> v;
    for(int i=1; i< fim+1; i++){
        v.push_back(i);
    }

   // string str; int inicio; int fim;
    if (inicio == fim)
        cout << str << endl;
    else {
        // Permutations made
        for (int i = inicio; i <= fim; i++) {
            char aux = str[inicio];
            str[inicio] = str[i];
            str[i] = aux;

            // Recursion called
            lexicographicPermute(str, inicio + 1, fim);

            //backtrack
            // swap(str[inicio], str[i]);
            aux = str[inicio];
            str[inicio] = str[i];
            str[i] = aux;
        }
    }
}


void lexicographicPermute11(  vector<int> v, int inicio, int fim ) {
    if (inicio == fim)
        printVector(v);
        //cout << str << endl;
    else {
        for (int i = inicio; i <= fim; i++) {
//            int aux = v[inicio];
//            v[inicio] = v[i];
//            v[i] = aux;
            swap(v[inicio], v[i]);

            // Recursion called
            lexicographicPermute11(v, inicio + 1, fim);

            //backtrack

//            aux = v[inicio];
//            v[inicio] = v[i];
//            v[i] = aux;
            swap(v[inicio], v[i]);
        }
    }
}

void lexicographicPermute1( int n ) {
    int inicio=0; int fim=n;
    std::vector<int> v;

    for(int i=1; i< n+1; i++){
        v.push_back(i);
    }

    // string str; int inicio; int fim;
    if (inicio == fim)
        printVector(v);
        //cout << str << endl;
    else {
        // Permutations made
        for (int i = inicio; i <= fim; i++) {
            int aux = v[inicio];
            v[inicio] = v[i];
            v[i] = aux;

            // Recursion called
            lexicographicPermute11(v, inicio + 1, fim);

            //backtrack
            // swap(str[inicio], str[i]);
            aux = v[inicio];
            v[inicio] = v[i];
            v[i] = aux;
        }
    }
}

int main() {
    /*

    //  1 ------- INSERTION SORT -----------------------
    inicializaVectorRandom(nums,tam_v);

   cout<<"Vector antes da ordenação: \n";
   printVector(nums);

   cout<<"Vector depois da ordenação: \n";
   printVector(insertSort(nums));
   */

// funciona
//    string str;
//    cout << "Insira a sequencia de string: ";
//    getline(cin, str);
  //  int n = str.size();
  //  lexicographicPermute(str, 0, n - 1);

    // 2 ----------------------------------------------------------------------------------
    // --------------------- lexicographicPermute1 --------------------------------------
    // ----------------------------------------------------------------------------------
    lexicographicPermute1(3);

    return 0;

}
