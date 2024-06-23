#include <iostream>
#include <vector>
#include <chrono>

// Função de busca linear
int buscaLinear(const std::vector<int>& array, int elemento, int& passos) {
    for (int i = 0; i < array.size(); ++i) {
        passos++; // Incrementa os passos a cada iteração
        if (array[i] == elemento) {
            return i;
        }
    }
    return -1;
}

// Função de busca binária recursiva
int buscaBinariaRecursiva(const std::vector<int>& array, int elemento, int inicio, int fim, int& passos) {
    if (inicio > fim) {
        return -1; // O elemento não foi encontrado
    }

    int meio = inicio + (fim - inicio) / 2;
    passos++;

    if (array[meio] == elemento) {
        return meio; // O elemento foi encontrado
    } else if (array[meio] > elemento) {
        return buscaBinariaRecursiva(array, elemento, inicio, meio - 1, passos);
    } else {
        return buscaBinariaRecursiva(array, elemento, meio + 1, fim, passos);
    }
}

int main() {
    std::vector<int> paginas(400);
    for (int i = 0; i < 400; ++i) {
        paginas[i] = i + 1;
    }

    int paginaDesejada;
    std::cout << "Digite o número da página desejada: ";
    std::cin >> paginaDesejada;

    // Busca linear
    int passosLinear = 0; // Inicializa o contador de passos para busca linear
    auto inicioLinear = std::chrono::high_resolution_clock::now(); // Inicia a contagem do tempo
    int indiceLinear = buscaLinear(paginas, paginaDesejada, passosLinear); // Passa o contador por referência
    auto fimLinear = std::chrono::high_resolution_clock::now(); // Termina a contagem do tempo
    std::chrono::duration<double, std::milli> duracaoLinear = fimLinear - inicioLinear;

    if (indiceLinear != -1) {
        std::cout << "Busca Linear: A página " << paginaDesejada << " foi encontrada no índice " << indiceLinear << ".\n";
        std::cout << "Foram necessários " << passosLinear << " passos para encontrar a página.\n";
    } else {
        std::cout << "Busca Linear: A página " << paginaDesejada << " não foi encontrada.\n";
        std::cout << "Foram necessários " << passosLinear << " passos.\n";
    }
    std::cout << "Tempo de execução da busca linear: " << duracaoLinear.count() << " ms\n";

    // Busca binária
    int passosBinaria = 0;
    auto inicioBinaria = std::chrono::high_resolution_clock::now();
    int indiceBinaria = buscaBinariaRecursiva(paginas, paginaDesejada, 0, paginas.size() - 1, passosBinaria);
    auto fimBinaria = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracaoBinaria = fimBinaria - inicioBinaria;

    if (indiceBinaria != -1) {
        std::cout << "Busca Binária: A página " << paginaDesejada << " foi encontrada no índice " << indiceBinaria << ".\n";
        std::cout << "Foram necessários " << passosBinaria << " passos para encontrar a página.\n";
    } else {
        std::cout << "Busca Binária: A página " << paginaDesejada << " não foi encontrada.\n";
        std::cout << "Foram necessários " << passosBinaria << " passos.\n";
    }
    std::cout << "Tempo de execução da busca binária: " << duracaoBinaria.count() << " ms\n";

    return 0;
}
