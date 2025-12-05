
# ATOMBIOSReader
Parser simples das vBIOS ATOM, que extrai e lista os offsets e tamanhos
das tabelas de comando e de dados presentes num arquivo ROM (normalmente extraído via GPU-Z).
Basicamente uma adaptação do ATOMBIOSReader original, porém funcional no macOS (não testado em Linux (ainda)).


**Requisitos**
- Compilador C++ com suporte a C++17 (por exemplo `clang++`).


**Como compilar:**
Use o comando abaixo para compilar o projeto:

```bash
clang++ -o atombios_reader main.cpp -std=c++17
```

**Como utilizar:**
O executável espera como argumento o caminho para um arquivo vBIOS (.rom).
Aqui segue um exemplo de execução (enviando a saída para um arquivo de texto):

```bash
./atombios_reader vbios.rom > vbios.txt
```

Podemos também executá-lo sem argumentos, sendo exibindo os resultados do arquivo processado no console.

