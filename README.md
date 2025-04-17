# Calculadora_conversor

## Descrição
Calculadora conversora, faz a conversão de Hexadecimal para decimal e decimal para hexadecimal 
esse programa foi feito para quem usa a calculadora em modo programador, uma solução simples
e bastante funcional.

* Compatível com Windows e Linux
* Menu interativo com repetição até o usuário sair
* Limpeza de tela automática para melhor experiência (usando cls no Windows e clear no Linux)
* Tratamento de erros para entradas inválidas e números fora do intervalo

No Linux:
sh
g++ conversor.cpp -o conversor && ./conversor


o Windows (se usar MinGW):
sh
g++ conversor.cpp -o conversor.exe && conversor.exe
