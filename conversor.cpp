#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>

#ifdef _WIN32
    #include <windows.h> // Para system("cls") no Windows
#else
    #include <cstdlib>   // Para system("clear") no Linux/Mac
#endif

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void converterHexParaDecimal() {
    std::string hex;
    std::cout << "Digite o número hexadecimal (exemplo: 1A3 ou 0x1A3): ";
    std::cin >> hex;

    // Remover prefixo "0x" ou "0X" caso esteja presente
    if (hex.size() > 2 && (hex.substr(0, 2) == "0x" || hex.substr(0, 2) == "0X")) {
        hex = hex.substr(2);
    }

    try {
        int decimal = std::stoi(hex, nullptr, 16);
        std::cout << "O valor em decimal é: " << decimal << std::endl;
    } catch (const std::invalid_argument&) {
        std::cerr << "Erro: entrada inválida. Certifique-se de inserir um número hexadecimal válido.\n";
    } catch (const std::out_of_range&) {
        std::cerr << "Erro: número hexadecimal muito grande.\n";
    }
}

void converterDecimalParaHex() {
    int decimal;
    std::cout << "Digite o número decimal: ";
    std::cin >> decimal;

    if (std::cin.fail()) {
        std::cerr << "Erro: entrada inválida. Digite um número válido.\n";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::stringstream ss;
    ss << std::hex << std::uppercase << decimal;
    std::cout << "O valor em hexadecimal é: 0x" << ss.str() << std::endl;
}

int main() {
    int opcao;

    while (true) {
        limparTela();
        std::cout << "Conversor Hexadecimal <-> Decimal\n";
        std::cout << "1. Converter hexadecimal para decimal\n";
        std::cout << "2. Converter decimal para hexadecimal\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        if (std::cin.fail()) {
            std::cerr << "Erro: entrada inválida! Digite um número de 1 a 3.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                converterHexParaDecimal();
                break;
            case 2:
                converterDecimalParaHex();
                break;
            case 3:
                std::cout << "Saindo...\n";
                return 0;
            default:
                std::cerr << "Opção inválida! Escolha entre 1 e 3.\n";
        }

        std::cout << "\nPressione ENTER para continuar...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}


