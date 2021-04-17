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

std::vector<int> inicializaVectorRandom(vector<int> &nums, int t) {
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < t; i++) {
        nums.push_back(1 + rand() % 1000);
    }
    return nums;
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

            for (int k = i; k < n; k++) {
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
void lexicographicPermute(string str, int inicio, int fim) {
    std::vector<int> v;
    for (int i = 1; i < fim + 1; i++) {
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


void print_permutations(std::vector<std::vector<int>> &permutations) {

    for (std::vector<int> p : permutations) {
        for (int el : p) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

}

std::vector<std::vector<int>> lexic_permute(int n) {
    std::vector<std::vector<int>> permutations;
    std::vector<int> permutation;

    for (int i = 1; i < n + 1; i++) {
        permutation.push_back(i);
    }

    permutations.push_back(permutation);

    bool decreasing_order = false;

    do {
        int i = -1;

        for (int k = 0; k < n - 1; k++) {
            if (permutation[k] < permutation[k + 1]) {
                i = k;
            }
        }

        decreasing_order = (i == -1);

        if (!decreasing_order) {
            int j = i;

            for (int k = i; k < n; k++) {
                if (permutation[i] < permutation[k]) {
                    j = k;
                }
            }

            std::swap(permutation[i], permutation[j]);

            std::reverse(permutation.begin() + (i + 1), permutation.end());

            permutations.push_back(permutation);
        }

    } while (!decreasing_order);

    print_permutations(permutations);
    return permutations;
}
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------

//  O( n * n!)
std::vector<vector<int>> johnTrotter(std::vector<int> &array, bool *direcao, int k, std::vector<vector<int>> mv) {
    for (int i = 1; i < k; i++) {
        int n = array.size();
        int maiorMovel = 0;
        int pegaPosicaoMaiorMovel = 0;

        //   encontrar o maior  inteiro móvel.
        for (int i = 0; i < n; i++) {
            // maiorMovel direita para array esquerda
            if (direcao[array[i] - 1] == false && i != 0) { //  n= 1 e 2
                if ((array[i] > array[i - 1]) && (array[i] > maiorMovel)) {
                    maiorMovel = array[i];
                }
            }

            // array direção 1 representa da ESQUERDA PARA A DIREITA.
            if ((direcao[array[i] - 1] == true) && (i != n - 1)) {
                if ((array[i] > array[i + 1]) && (array[i] > maiorMovel)) {
                    maiorMovel = array[i];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (array[i] == maiorMovel)
                pegaPosicaoMaiorMovel = i + 1; //pega array posução do elemento, antes da mudança de maiorMovel
        }

        // trocando os elementos de acordo com array direção, ou seja, direcao [].
        if (direcao[array[pegaPosicaoMaiorMovel - 1] - 1] == false) {
            swap(array[pegaPosicaoMaiorMovel - 1], array[pegaPosicaoMaiorMovel - 2]);
        } else if (direcao[array[pegaPosicaoMaiorMovel - 1] - 1] == true) {
            swap(array[pegaPosicaoMaiorMovel], array[pegaPosicaoMaiorMovel - 1]);
        }

        // alterando as direções dos elementos maior que o maior número inteiro móvel.
        for (int i = 0; i < n; i++) {
            if (array[i] > maiorMovel) {
                if (direcao[array[i] - 1] == true)
                    direcao[array[i] - 1] = false;
                else if (direcao[array[i] - 1] == false)
                    direcao[array[i] - 1] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << array[i];
        }
        cout << endl;
        mv.push_back(array);
    }

    return mv;
}


int factorial(int n) {
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}


void inicializaJohn(int n) {

    std::vector<int> v;
    std::vector<vector<int>> mv;
    bool direcao[n];

    int k = factorial(n);
    cout << "Número de permutação: " << k << endl;

    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
        cout << v[i];
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        direcao[i] = false;
    }

    mv.push_back(v);
    johnTrotter(v, direcao, k, mv);
}
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------

int main() {


    //  11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
    //  --------------------------------------------------------------------------------------------------------------
    //  --------------------------------------------------------------------------------------------------------------
    //  ---------------------- INSERTION SORT ------------------------------------------------------------------------
    //  ---------------------- INSERTION SORT ------------------------------------------------------------------------
    //  --------------------------------------------------------------------------------------------------------------
    //  --------------------------------------------------------------------------------------------------------------

//    int tam_v=20;
//    std::vector<int> nums;
//    std::vector<int> numsV = inicializaVectorRandom(nums,tam_v);
//
//    cout << "Vector antes da ordenação: \n";
//    printVector(numsV);
//
//    cout << "Vector depois da ordenação: \n";
//    numsV=insertSort(nums);
//    printVector(numsV );



    //222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
    // -----------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------
    // ----------------------------- Johnson-Trotter -------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------
    //222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
    //222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

    // int n = 3;
    // inicializaJohn(n);



    // 33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
    // 33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
    // -----------------------------------------------------------------------------------------------------------------
    // ------------------------------------------lexicographicPermute---------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------


    //    std::vector<int> ns({3});
//    //  std::vector<int> ns({ 2,4,5,6,7,9,10});
//    std::vector<double> time({});
//
//    for (int n : ns) {
//        auto start = std::chrono::system_clock::now();
//        lexic_permute(n);
//        auto finish = std::chrono::system_clock::now();
//
//        std::chrono::duration<double> elapsed = finish - start;
//        std::cout << "N = " << n << " : " << elapsed.count() << std::endl;
//
//        time.push_back(elapsed.count());
//    }


    //444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
    //444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
    // -----------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------

//    string str;
//    cout << "Insira a sequencia de string: ";
//    getline(cin, str);
//    int n = str.size();
//    lexicographicPermute(str, 0, n - 1);
    return 0;

}
