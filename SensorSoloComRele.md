# SENSOR DE CHUVA
Lista de Materiais
- 01 Placa Protoboard;
- 01 Placa Arduino Uno R3;
- 01 Cabo USB;
- 01 Módulo Sensor de Umidade do Solo Higrômetro;
- 01 Motor DC;
- 01 Módulo Relé 5V;
- 01 Bateria de 9V;
- 01 Clipe para bateria;
- 05 Jumpers Fêmea-Fêmea;
- 05 Jumpers Macho-Macho;
- 50 cm Fio Paralelo de 0,5mm;
- 01 Recipiente (copo descartável) com água;
- 01 Recipiente (copo descartável) com terra seca;
- 01 Notebook;
- Software Arduino IDE.

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
