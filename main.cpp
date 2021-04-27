#include <cstdlib>
#include <vector>
#include <climits>
#include <math.h>
#include <matplot/matplot.h>

using point = std::pair<double, double>;
using namespace std;

#include<iostream>
#include <cstring>
#include <ctime>
#include <bits/stdc++.h>

#define tamMatriz 5

#include<map>


class binarySearhTree {
    struct node {
        int data;
        node *left;
        node *right;
    };

    node *root;

    node *raizVazia(node *t) {
        if (t == NULL)
            return NULL;
        {
            raizVazia(t->left);
            raizVazia(t->right);
            delete t;
        }
        return NULL;
    }
//Inserção		caso médio: O(log n)	 pior caso: O(n)
/**
A inserção começa com uma busca, procurando pelo valor, mas se não for encontrado, procuram-se as subárvores da esquerda ou direita, como na busca.
 Eventualmente, alcança-se a folha, inserindo-se então o valor nesta posição. Ou seja, a raiz é examinada e introduz-se um nó novo na subárvore
 da esquerda se o valor novo for menor do que a raiz, ou na subárvore da direita se o valor novo for maior do que a raiz.
 */
    node *insert(int no, node *tree) {
        if (tree == NULL) // se a arvore é vazia
        {
            tree = new node; // cria um nó e insere. se não
            tree->data = no;
            tree->left = tree->right = NULL;
        } else if (no < tree->data) // faz as comparações
            tree->left = insert(no, tree->left);
        else if (no > tree->data)
            tree->right = insert(no, tree->right);
        return tree;
    }

    node *findMin(node *t) {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node *findMax(node *tree) {
        if (tree == NULL)
            return NULL;
        else if (tree->right == NULL)
            return tree;
        else
            return findMax(tree->right);
    }

//caso médio: O(log n)	 pior caso: O(n)
    node *remove(int x, node *tree) {
        node *temp;
        if (tree == NULL)
            return NULL;
        else if (x < tree->data)
            tree->left = remove(x, tree->left);
        else if (x > tree->data)
            tree->right = remove(x, tree->right);
        else if (tree->left && tree->right) {
            temp = findMin(tree->right);
            tree->data = temp->data;
            tree->right = remove(tree->data, tree->right);
        } else {
            temp = tree;
            if (tree->left == NULL)
                tree = tree->right;
            else if (tree->right == NULL)
                tree = tree->left;
            delete temp;
        }

        return tree;
    }

    // imprime em ordem crescente
    void inorder(node *t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    //caso médio: O(log n)	 pior caso: O(n)
    node *find(node *t, int x) {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    binarySearhTree() {
        root = NULL;
    }

    ~binarySearhTree() {
        root = raizVazia(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

/*
  A busca começa examinando o nó raiz. Se a árvore está vazia, o valor procurado não pode existir na árvore.
  Caso contrário, se o valor é igual a raiz, a busca foi bem sucedida.
  Se o valor é menor do que a raiz, a busca segue pela subárvore esquerda, se não, pela direita.

  Esse processo é repetido até o valor ser encontrado ou a subárvore ser nula (vazia).
  Se o valor não for encontrado até a busca chegar na subárvore nula, então o valor não deve estar presente na árvore.
 */
    void search(int x) {
        root = find(root, x);
    }
};


template<class T>
void printVector(std::vector<T> &v) {
    for (auto i = v.begin(); i != v.end(); ++i) {
        std::cout << *i << " | ";
    }
    std::cout << endl;
}

template<class T>
std::vector<T> ordenaVetorSort(std::vector<T> &v) {
    sort(v.begin(), v.end());
    return v;
}


template<class T>
int binarySearch(std::vector<T> v, int K) {


    int n = v.size();
    int l = 0;
    int r = n - 1;
    int m;
    while (l <= r) {
        m = ceil((l + r) / 2);
        if (K == v[m]) {
            return m;
        } else if (K < v[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

// A classificação por inserção é uma aplicação direta da técnica de diminuir (em um) e conquistar ao problema de classificação.
// É um algoritmo O (n²) nos piores casos e no médio, mas é cerca de duas vezes mais rápido em média do que no pior caso.
// A vantagem notável do algoritmo é um bom desempenho em matrizes quase classificadas..
template<class T>
vector<T> insertSort(std::vector<T> &v) {
    vector<T> vetor(v.size());
    vetor = v;
    for (int i = 0; i < (int) vetor.size(); i++) {
        int v = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > v) { // operação básica
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
    //int tam = sizeof(v) / sizeof(int);
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
    printArray(v, n);
    //  return v;
}

std::vector<int> inicializaVector(int n) {
    std::vector<int> v;
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

std::vector<int> inicializaVectorRandom(int t) {
    unsigned seed = time(0);
    srand(seed);
    vector<int> nums;

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

/*
 A pesquisa de interpolação é um algoritmo de pesquisa para um determinado valor de chave em um array que foi  ordenado pelos valores da chave.
 A pesquisa de interpolação pode ir para locais diferentes de acordo com o valor da chave que está sendo pesquisado.
 Por exemplo, se o valor da chave estiver mais próximo do último elemento, a pesquisa de interpolação provavelmente iniciará a pesquisa
 em direção ao lado final.


 A complexidade média do tempo de caso da pesquisa de interpolação é O(logn (logn)) comparações.
 Na pior caso, ele pode fazer até comparação O(n), que é equivalente à pesquisa linear.

 O programa possui um vetor de tamanho N, já inicializada com N valores. E retorna o índice do elemento, se encontrado e
 -1 se não encontrado.


 */
template<typename T>
int interpolation_search(std::vector<T> &v, int k) {

    int l = 0;
    int r = v.size() - 1;
    int mid;


    while (v[l] <= k && v[r] >= k) {
        mid = l + ((k - v[l]) * (r - l)) / (v[r] - v[l]);
        if (v[mid] < k) {
            l = mid + 1;

        } else if (v[mid] > k) {
            l = mid - 1;
        } else {
            return mid;
        }
    }
    if (v[l] == k) {
        return l;
    } else {
        return -1;
    }
}

template<typename T>
void geraSubjconjunto(std::vector<T> &str, int inicio, int fim) {
    std::vector<vector<T>> v;


    if (inicio == fim) {
        printVector(str);
    } else {

        for (int i = inicio; i <= fim; i++) {
            //    swap(str[inicio], str[i]);
            T a = str[inicio];
            str[inicio] = str[i];
            str[i] = a;
            //    v.push_back(str);

            geraSubjconjunto(str, inicio + 1, fim);

            //backtrack
            //      swap(str[inicio], str[i]);
            a = str[inicio];
            str[inicio] = str[i];
            str[i] = a;
            //   v.push_back(str);
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

    //  print_permutations(permutations); // descomentar, para poder imprmir
    return permutations;
}
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------
// ------------------------------ johnTrotter ------------------------------------------------------------------------

//  O( n!)
std::vector<vector<int>> johnTrotter(std::vector<int> &array, bool *direcao, int k, std::vector<vector<int>> mv) {
    for (int i = 1; i < k; i++) {
        int n = array.size();
        int maiorMovel = 0;
        int pegaPosicaoMaiorMovel = 0;
        std::vector<int> temp;

        //   encontrar o maior  inteiro móvel.
        for (int i = 0; i < n; i++) {
            // maiorMovel direita para array esquerda
            if (direcao[array[i] - 1] == false && i != 0) { //  n= 1 e 2
                if ((array[i] > array[i - 1]) && (array[i] > maiorMovel)) {
                    maiorMovel = array[i];
                    pegaPosicaoMaiorMovel = i + 1; //pega  posição do elemento, antes da mudança de maiorMovel
                }
            }

            // maiorMovel esquerda  para array direita
            if ((direcao[array[i] - 1] == true) && (i != n - 1)) {
                if ((array[i] > array[i + 1]) && (array[i] > maiorMovel)) {
                    maiorMovel = array[i];
                    pegaPosicaoMaiorMovel = i + 1;//pega  posição do elemento, antes da mudança de maiorMovel
                }
            }
        }


        // swap k with the adjacent element k’s arrow points to
        // trocando os elementos de acordo com array direção, ou seja, direcao [].
        if (direcao[array[pegaPosicaoMaiorMovel - 1] - 1] == false) {
            swap(array[pegaPosicaoMaiorMovel - 1], array[pegaPosicaoMaiorMovel - 2]);
        } else if (direcao[array[pegaPosicaoMaiorMovel - 1] - 1] == true) {
            swap(array[pegaPosicaoMaiorMovel], array[pegaPosicaoMaiorMovel - 1]);
        }
        //  reverse(array.begin(),array.end());

        // alterando as direções dos elementos maior que o maior número inteiro móvel.
        for (int i = 0; i < n; i++) {
            if (array[i] > maiorMovel) {
                //reverse the direction of all the elements that are larger than
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

    int k = factorial(n); // O(n!)
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

// Particiona o subarray pelo algoritmo de Lomuto usando o primeiro elemento como pivô
// Entrada: Um subarrayA [l..r] de arrayA [0..n − 1], definido por sua esquerda e direita
// indices l and r (l≤r)
// Saída: Partição de A [l..r] e a nova posição do pivô
int lomutoPartition(int *arr, int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

// melhor caso: teta - Θ(n)
// pior   caso:  Θ(n^2)
int quickSelect(int *arr, int l, int r, int k) {
    // If k is smaller than number of
    // elements in array
    if (k > 0 && k <= r - l + 1) {

        // Particionar o array em torno do último
        // elemento e obtém a posição do pivô
        // elemento na matriz classificada
        int index = lomutoPartition(arr, l, r);

        // Se a posição for igual a k
        if (index - l == k - 1)
            return arr[index];

        // Se a posição for maior, volte a ocorrer
        // para subarray esquerdo
        if (index - l > k - 1)
            return quickSelect(arr, l, index - 1, k);

        // Caso contrário, recorre para o subarray direito
        return quickSelect(arr, index + 1, r,
                           k - index + l - 1);
    }

    // Se k for maior  do que um número de
    // elementos na matriz
    return INT_MAX;
}

void print_subsets(const std::vector<std::vector<int>> &power_set) {
    for (size_t i = 0; i < power_set.size(); i++) {
        for (size_t j = 0; j < power_set[0].size(); j++) {
            if (power_set[i][j] == 1) {
                std::cout << "e" << power_set[0].size() - j << ", ";
            }
        }
        std::cout << std::endl;
    }

}

void print_bit_strings(std::vector<std::vector<int>> &power_set) {
    for (size_t i = 0; i < power_set.size(); i++) {
        for (size_t j = 0; j < power_set[0].size(); j++) {
            std::cout << power_set[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

/*
 The correctness of the algorithm stems from the fact that it generates 2^n bit strings and all of them are distinct.
 Both these assertions are easy to check by mathematical induction.
 */
std::vector<std::vector<int>> BRGC_Recursivo(int n) {
    std::vector<std::vector<int>> power_set;
    if (n == 1) {
        power_set.push_back({0});
        power_set.push_back({1});
    } else {
        std::vector<std::vector<int>> L1 = BRGC_Recursivo(n - 1);
        std::vector<std::vector<int>> L2 = L1;
        std::reverse(L2.begin(), L2.end());

        for (std::vector<int> &str : L1) {
            str.emplace(str.begin(), 0);
        }

        for (std::vector<int> &str : L2) {
            str.emplace(str.begin(), 1);
        }

        L2.insert(L2.begin(), L1.begin(), L1.end());
        power_set = L2;
    }

    return power_set;

}

std::vector<string> BRGC(int n) {
    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    vector<string> temp;
    for (int i = 2; i <= n; ++i) {
        for (auto x: ans) {
            temp.push_back(x + "0");
            temp.push_back(x + "1");
        }
        ans = temp;
        temp.clear();
    }
    return ans;
}

void printsubset(int arr[], std::vector<string> &s) {

    for (auto x:s) {
        for (int j = 0; j < x.size(); ++j) {
            if (x[j] == '1') {
                cout << arr[j] << " ";
            }
            cout << "\n";
        }

    }
}

 // compara o peso da balança e retorna o conunto mais leve.
 // executado n/2
int pesaMoeda(std::vector<int> listaEsquerda, std::vector<int> listaDireita) {
    if (listaEsquerda.size() != listaDireita.size())
        cout << "Balança com peso  diferente " << endl;

    int pesoEsquerdo = 0.0;
    for (int aLeft : listaEsquerda)
        pesoEsquerdo += aLeft;

    int pesoDireito = 0.0;
    for (int aRight : listaDireita)
        pesoDireito += aRight;

    if (pesoEsquerdo == pesoDireito) {
        cout << "Balança com pesos iguais: " << pesoEsquerdo << endl;
        return 0;
    } else if (pesoEsquerdo < pesoDireito) {
        cout << "Peso balança esquerda menor: " << pesoEsquerdo << endl;
        return 1;
    } else if (pesoEsquerdo > pesoDireito) {
        cout << "Peso balança direita menor:  " << pesoDireito << endl;
        return -1;
    }

}

// moeda falsa
// tamanho de entrada: n
//
// Operação básica: divisão
//
// Eficiência: O(log2 n) de n no pior caso e base logarítmica 3 de n para a melhor eficiência
//
// Melhor caso: se n = 2
//
// Pior caso: n = número realmente grande
// C(n) = (n/2) + 1 (numero de operação basica 'pesagem'   c(1)= 0
// n= 3
//C(n) = (n/3) + 3 (numero de operação basica 'pesagem'   c(1)= 0.  O(log3 n)
int procuraMoeda(std::vector<int> &coins) {
    if (coins.size() == 0) {
        cout << "Balança vazia " << endl;
        return -1;
    } else if (coins.size() == 1) { // se possue uma moeda, ela é falsa
        return 0;
    } else {
        //calcula o tamanhoh de cada pilha
        int metade = floor(coins.size() / 2);
        bool impar = coins.size() % 2 == 1;
        std::vector<int> arrayEsquerda;
        std::vector<int> moedaExtra;
        std::vector<int> arrayDireita;

        //  -----------------------// xxxxxxxxxxxxxxxxxxxxxxxx//
        for (int i = 0; i < metade; i++) {
            arrayEsquerda.push_back(coins[i]);
        }
        // xxxxxxxxxxxxxxxxxxxxxxxx//  -----------------------
        for (int i = metade; i < metade * 2; i++) {
            arrayDireita.push_back(coins[i]);
        }
        if (impar) {
            for (int i = metade * 2; i < coins.size(); i++) {
                moedaExtra.push_back(coins[i]);
            }
        }
        //operação basica é numero de pesagem da moeda
        int result = pesaMoeda(arrayEsquerda, arrayDireita);

        if (result == 0) {
            cout << "Procurando na moeda extra " << endl;
            return 0;// procuraMoeda(moedaExtra);
        } else if (result == 1) {
            return procuraMoeda(arrayEsquerda);
        } else if (result == -1) {
            return procuraMoeda(arrayDireita);
        }
    }
}

std::vector<int> inicializaMoeda(int num) {
    //inicializa as moedas, com o peso 2
    vector<int> moeda;
    for (int i = 0; i < num; i++) {
        moeda.push_back(2);
    }
    //escolhe aleatoriamente uma moeda falsa, com o peso=1
    int pos_fake = ceil(rand() % num);
    moeda[pos_fake] = 1;
    return moeda;
}


int main() {
    //  11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
    //  --------------------------------------------------------------------------------------------------------------
    //  --------------------------------------------------------------------------------------------------------------
    //  ---------------------- INSERTION SORT ------------------------------------------------------------------------
    //  ---------------------- INSERTION SORT ------------------------------------------------------------------------
    //  --------------------------------------------------------------------------------------------------------------
    //  --------------------------------------------------------------------------------------------------------------

    /*
     Insertion Sort ou ordenação por inserção é o método que percorre um vetor de elementos da esquerda para a direita e
     à medida que avança vai ordenando os elementos à esquerda. Possui complexidade C(n) = O(n) no melhor caso e C(n) = O(n²)
     no caso médio e pior caso. É considerado um método de ordenação estável.
    Um método de ordenação é estável se a ordem relativa dos itens iguais não se altera durante a ordenação.

    O funcionamento do algoritmo é bem simples: consiste em cada passo a partir do segundo elemento selecionar o próximo item
     da sequência e colocá-lo no local apropriado de acordo com o critério de ordenação.
    */
//    int tam_v=20;
//    std::vector<int> nums;
//    std::vector<int> numsV = inicializaVectorRandom(tam_v);
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
    // -----------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------


    //int n = 4;
    // inicializaJohn(n);



    // 33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
    // 33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
    // -----------------------------------------------------------------------------------------------------------------
    // ------------------------------------------geraSubjconjunto---------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------

//
//    std::vector<int> ns({ 2,4,5,6,7,9,10});
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
//    matplot::plot(ns,time, "-s")
//            ->line_width(5)
//            .marker_size(10)
//            .marker_color("g")
//            .marker_face_color({.5,.5,.5});
//
//    matplot::show();


    //444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
    //444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
    // -------------------------------------------ALGORITHM BRGC(n)------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------

    //  std::vector<std::vector<int>> power_set = BRGC_Recursivo(2);

//     print_bit_strings(power_set);

    //  print_subsets(power_set);


// 555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
// 555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
//----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------binarySearch-----------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------

//
/*
 Algoritmo    é  teta Θ(log n) para o caso médio e O(log n) para o pior caso.
 Contaremos as chamadas comparações de três fatores. Isso pressupõe que, após uma
 comparação de K com A [m], o algoritmo pode determinar se K é menor, igual ou maior que A [m].
 Embora a pesquisa binária seja um algoritmo de pesquisa ideal se restringirmos nossas operações apenas a comparações
 entre chaves, existem algoritmos de pesquisa com uma melhor eficiência de tempo médio de caso, e um deles (hashing)
 nem mesmo exige que o array seja ordenado. Esses algoritmos requerem alguns cálculos especiais, além de comparações
 de chave. Finalmente, a ideia por trás da pesquisa binária tem várias aplicações além da pesquisa.
 Além disso, pode ser aplicado para resolver equações não lineares em uma incógnita;

  */

//    int n = 20;
//    cout << "Tamanho do Vetor: " << n << endl;
//    std::vector<int> str = inicializaVectorRandom(n);
//
//    cout << "Vetor não ordenado: " ;
//    printVector(str);
//
//
//    int x = str[0];
//
//    ordenaVetorSort(str); //O(n log n).
//    cout << "Vetor  ordenado: " ;
//    printVector(str);
//
//    cout << endl;
//
//    cout << "Elemento procurado: " << x << endl;
//
//    int pos = binarySearch(str, x);
//    if (pos != -1) {
//        cout << "Elemento " << x << " encontrado na posição: " << pos << endl;
//    } else {
//        cout << "Elemento " << x << " não encontrado no vector " << endl;
//    }

//6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
//6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
//----------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------- interpolation search --------------------------------------
// --------------------------------------------------------- interpolation search --------------------------------------
// ---------------------------------------------------------------------------------------------------------------------

//    int n = 20;
//    cout << "Tamanho do Vetor: " << n << endl;
//    std::vector<int> str = inicializaVectorRandom(n); // O(n)
//
//    cout << "Vetor não ordenado: " << endl;
//    printVector(str);
//
//
//    int x = str[0];
//
//    ordenaVetorSort(str);       //O(n log n).
//    cout << "Vetor  ordenado: " ;
//    printVector(str);
//
//    cout << endl;
//
//    cout << "Elemento procurado: " << x << endl;
//    int pos = interpolation_search(str, x );  //yO(logn (logn))
//
//
//    if (pos != -1) {
//        cout << "Elemento " << x << " encontrado na posição: " << pos << endl;
//    } else {
//        cout << "Elemento " << x << " não encontrado no vector " << endl;
//    }

//7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
//7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
// --------------------------------------------------------- FakeCoin --------------------------------------------------
// --------------------------------------------------------- FakeCoin --------------------------------------------------

//
//    vector<int> coins = inicializaMoeda(9);
//    int fakeCoinPosition = procuraMoeda(coins);
//
//    if (fakeCoinPosition == 0) {
//        cout << "Moeda encontrada  " << endl;
//    } else {
//        cout << "Moeda não encontrada  " << endl;
//    }




//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//-------------------------------------------- mediana -----------------------------------------------------------------
//-------------------------------------------- mediana -----------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//    int arr[] = {4 , 1, 10, 8, 7, 12, 9, 2, 15 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int k = ceil(n/2);
//    cout << "K: " << k << endl;
//    cout << "K-th smallest element is "
//         << quickSelect(arr, 0, n - 1, k);
//



// 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
// 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
// --------------------------------------- binary search tree ---------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
//altura log2 n, pioraso O(n)
    binarySearhTree t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    t.remove(30);
    t.display();
    t.search(30);
    t.display();
    return 0;

}