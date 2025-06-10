


# Teclado de Membrana
Lista de Materiais

- 01 Placa Arduino Uno R3;
- 01 Cabo USB;
- 01 Teclado Matricial de Membrana 16 teclas;
- 08 Jumpers Macho-Macho;
- 01 Notebook;
- Software Arduino IDE.

![Image](https://private-user-images.githubusercontent.com/125823124/453244785-c7c501da-f872-4829-9bf4-9cd2aec28441.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDk1MTg0MTYsIm5iZiI6MTc0OTUxODExNiwicGF0aCI6Ii8xMjU4MjMxMjQvNDUzMjQ0Nzg1LWM3YzUwMWRhLWY4NzItNDgyOS05YmY0LTljZDJhZWMyODQ0MS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjEwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYxMFQwMTE1MTZaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05OTViYzJhZTgwYWQzN2IyYjNlYTFmY2FkODM5ZWMyZWIzYjY3ZDliOWQ2MzBiZTBkMTUwN2UyYTMxOGZhODYyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.hhy9jMXqJ-EMAmNzRR9A5VOVyh6iaAmF72cAr9HckY4)


### Codigo em C para arduino uno 
```c
/* Inclui a biblioteca Keypad */
#include  <Keypad.h>

/* Define o número de linhas e colunas do teclado */
const byte qtdLinhas = 4;
const byte qtdColunas = 4;

/* Construção da matriz de caracteres */
char  matriz_teclas[qtdLinhas][qtdColunas] = {
	{ '1', '2', '3', 'A' },
	{ '4', '5', '6', 'B' },
	{ '7', '8', '9', 'C' },
	{ '*', '0', '#', 'D' }
};

/* Pinos utilizados pelas linhas e colunas do teclado */
byte PinosqtdLinhas[qtdLinhas] = { 9, 8, 7, 6 };
byte PinosqtdColunas[qtdColunas] = { 5, 4, 3, 2 };

/* Inicializa o teclado */
Keypad meuteclado = Keypad(makeKeymap(matriz_teclas),
PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas);

void  setup() {
	/* Define a velocidade de comunicação serial em 9600 bauds */
	Serial.begin(9600);
	/* Imprime no monitor serial o texto entre aspas */
	Serial.println("Aperte uma tecla...");
	/* Quebra uma linha no monitor serial */
	Serial.println();
}

void  loop() {
	/* Armazena o caractere referentente a tecla pressionada */
	char tecla_pressionada = meuteclado.getKey();
	/* Se a variável "tecla_pressionada" receber um novo valor,faz... */
	if (tecla_pressionada) {
	/* Imprime o texto entre aspas no monitor serial */
	Serial.print("Tecla pressionada : ");
	/* Imprime o caractere no monitor serial e quebra uma linha */
	Serial.println(tecla_pressionada);
 }
}
```
- [Video de montagem](https://www.youtube.com/watch?v=FSXoBCX9hKY)
- [PDF do material](https://aluno.escoladigital.pr.gov.br/sites/alunos/arquivos_restritos/files/documento/2021-07/aula15_teclado_matricial_membrana_m2.pdf)
- [Sketch Teclado Membrana](https://sketchfab.com/3d-models/aula-15-teclado-matricial-de-membrana-5614e07ae5a240ff9e892802dd9f9571?authuser=0&hl=pt-BR)
### Professor: Richardson Schawarski.
