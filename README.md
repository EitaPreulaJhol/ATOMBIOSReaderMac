
# ATOMBIOSReaderMac
Parser simples das vBIOS ATOM, que extrai e lista os offsets e tamanhos
das tabelas de comando e de dados presentes num arquivo ROM (normalmente extraído via GPU-Z).
Basicamente uma adaptação do [ATOMBIOSReader](https://github.com/kizwan/ATOMBIOSReader), funcional no macOS (não testado no Linux).


**Requisitos:**

- Compilador C++ com suporte a C++17 (por exemplo `clang++`).


**Como compilar:**

Use o comando abaixo para compilar o projeto:

```bash
clang++ -o atombiosreadermac main.cpp -std=c++17
```

**Como utilizar:**

O executável espera como argumento o caminho para um arquivo vBIOS (.rom).
Aqui segue um exemplo de execução (enviando a saída para o console):

```bash
./atombiosreadermac vbios.rom
```

Caso precise de um dump de cada tabela de dados (Data Table) encontrada na ROM, adicione um `--hex` ao final do prompt.
O dump final será salvo com o nome da função, em um arquivo .txt:

```bash
./atombiosreadermac vbios.rom --hex
```

Extremamente útil para dumpar a tabela do PowerPlay e injetarmos via Opencore, para termos mais controle sobre a curva das fans no macOS.

**Créditos:**
Autor original da ferramenta ATOMBIOSReader - [kizwan](https://github.com/kizwan)


