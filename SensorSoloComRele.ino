```c
/* Código de Funcionamento para Sistema de Monitoramento e
Irrigação com Arduino */
/* Define o pino A0 como "pinoAnalog" */
#define pinoAnalog A0
/* Define o pino 8 como "pinoRele" */
#define pinoRele 8
/* Variável que armazena a leitura analógica do sensor */
int ValAnalogIn;
void setup() {
  /* Declara a velocidade da porta serial em 9600 bauds */
  Serial.begin(9600);
  /* Condfigura o pinoRele como Saída */
  pinMode(pinoRele, OUTPUT);
}
void loop() {
  /* Armazena o valor analógico recebido do sensor */
  ValAnalogIn = analogRead(pinoAnalog);
  /* Converte o valor analógico em uma escala de 0% à 100% */
  int Porcento = map(ValAnalogIn, 1023, 0, 0, 100);
  /* Imprime a porcentagem de umidade no monitor Serial */
  Serial.print(Porcento);
  /* Imprime o símbolo % junto ao valor encontrado */
  Serial.println("%");
  /* Se a porcentagem for menor ou igual à 45 */
  if (Porcento <= 45) {
    /* Imprime a frase no monitor serial */
    Serial.println("Irrigando a planta ...");
    /* Altera o estado do pinoRele para nível Alto */
    digitalWrite(pinoRele, HIGH);
  } else { /* Se não ... */
    /* Imprime a frase no monitor serial */
    Serial.println("Planta Irrigada ...");
    /* Altera o estado do pinoRele para nível Baixo */
    digitalWrite(pinoRele, LOW);
  }
  /* Aguarda 1 segundo para a próxima leitura */
  delay(1000);
}
```
