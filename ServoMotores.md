
# SERVOS MOTORES aula 16


# 1. Contextualização (15min): 
A robótica vem se destacando cada vez mais no século XXI como uma alternativa para a realização de atividades consideradas difíceis ou perigosas para a espécie humana, como, por exemplo, exploração espacial, desarmamento de bombas e minas terrestres, pintura em recinto fechado, carga e descarga de materiais, entre outras. Alguns movimentos produzidos por robôs, como o abrir e o fechar de uma garra, ou o girar esta garra de um lado para outro, com precisão e velocidade controladas, podem ser realizados através de dispositivo eletrônico chamado Servo Motor. Nesta aula, vamos conhecer as estruturas que formam este dispositivo, os modelos presentes no kit de robótica e exemplo de comandos enviados ao Arduino para acionar alguns movimentos no Servo Motor. Conforme mencionamos anteriormente, o Servo Motor é um dispositivo que ao receber comandos de controle, verifica a posição atual e se movimenta para a posição desejada com velocidade monitorada. Para podermos compreender como este componente eletrônico consegue realizar tais funções, vamos conhecer do que são constituídos. No kit de robótica você encontrará dois modelos de Servo Motor: o Micro Servo 9g SG90 e o Micro Servo MG 90S. A principal diferença entre ambos é que o modelo MG 90S possui engrenagens em metal, o que possibilita maior resistência em relação ao modelo SG90 (figura 1).

![enter image description here](https://private-user-images.githubusercontent.com/125823124/457895560-a800f514-027f-4a31-8097-050e26e5c646.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NTA2ODAzMDgsIm5iZiI6MTc1MDY4MDAwOCwicGF0aCI6Ii8xMjU4MjMxMjQvNDU3ODk1NTYwLWE4MDBmNTE0LTAyN2YtNGEzMS04MDk3LTA1MGUyNmU1YzY0Ni5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjIzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYyM1QxMjAwMDhaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1kMDA3OTVhNWQxOTNjYWE2Njg3YTFlNTc5M2U4NTNhMTA2M2ZjMzJkMWYxZWRhMGRhZGIwNzAzZjEzNDVkNTIyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.6YIHHX-DRTflXpR1gSDQXUHbPqd-uFuUJTj5wGK1C-M)

Em relação às estruturas internas, ambos possuem um potenciômetro que se encontra ligado ao eixo de saída e é responsável pelo monitoramento da posição deste eixo; um motor, o qual movimenta as engrenagens e o eixo principal do servo; um conjunto de engrenagens (contendo, geralmente, uma haste), cuja função é reduzir a rotação do motor, transferindo mais torque (resistência) ao eixo e indicar o ângulo posicionado; e um circuito de controle que tem a função de monitorar o potenciômetro e acionar o motor para obter uma posição pré-estabelecida. Todas estas estruturas são acondicionadas na caixa do Servo (figura 2). Os Servos Motores são acionados através de três fios: marrom (GND), vermelho (5V) e laranja (sinal) (figura 1). Os dois primeiros fios alimentam o motor, enquanto o fio laranja recebe o sinal de controle no formato PWM para determinar a posição desejada.

![enter image description here](https://private-user-images.githubusercontent.com/125823124/457895561-eec9470b-72dd-4efe-b1b6-ee97dec5c79d.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NTA2ODAzMDgsIm5iZiI6MTc1MDY4MDAwOCwicGF0aCI6Ii8xMjU4MjMxMjQvNDU3ODk1NTYxLWVlYzk0NzBiLTcyZGQtNGVmZS1iMWI2LWVlOTdkZWM1Yzc5ZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjIzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYyM1QxMjAwMDhaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xZDkyZjY2NzE5ZDNmOTA0MDk3NjIyNmVlZTMwMTFmNTI0OTlhZWRmMGFkYzNlYjM0ZGM2NzU1NzYyOGU5YjQ3JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.B8ByfajQg5IUBzmfu4a3BT9SNWOLQoc-IiEfxJQ9tWs)

# 2.Montagem e Programação (60min): 
Para montagem do protótipo, utilizaremos três componentes presentes no kit de robótica: a placa de Arduino, o Micro Servo 9g SG90 e Jumpers Macho-Macho. Interligue, utilizando 3 Jumpers Macho-Macho, a placa de Arduino com o Servo Motor respeitando a sequência: pino GND ao fio marrom; pino 5V ao fio vermelho; e pino 7 ao fio laranja, conforme mostra a figura 3.



![enter image description here](https://private-user-images.githubusercontent.com/125823124/457895563-5c911814-bc0f-4b7b-b86c-f85f8a1c2d9b.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NTA2ODAzMDgsIm5iZiI6MTc1MDY4MDAwOCwicGF0aCI6Ii8xMjU4MjMxMjQvNDU3ODk1NTYzLTVjOTExODE0LWJjMGYtNGI3Yi1iODZjLWY4NWY4YTFjMmQ5Yi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjIzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYyM1QxMjAwMDhaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0yY2UxODk2MzcwNDlhZDEzYmY3M2M5NjY4MTEzMTk5MTFiM2JlMjM5MmJmNzMyYjM4Yjc3N2VlNGJlY2Y2ODUwJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9._5o7umB43PrJDPNL5n35Ort80KV0wdmEqe-3pAsygk8)
```c++
/* Programa: Utilizando servo motor */
/* Inclui a biblioteca de controle do servo */

#include  <Servo.h>
/* Cria um objeto para controlar o servo */
Servo meuservo;
/* Define o pino de dados do servo */
int Pino_Servo = 7;
void  setup() {
/* Endereça o objeto servo ao pino de dados definido */
meuservo.attach(Pino_Servo);
}
void  loop() {
/* Posiciona o servo em 0 graus */
meuservo.write(0);
/* Aguarda 1 segundo */
delay(1000);
/* Posiciona o servo em 90 graus */
meuservo.write(90);
/* Aguarda 1 segundo */
delay(1000);
/* Posiciona o servo em 180 graus */
meuservo.write(180);
/* Aguarda 1 segundo */
delay(1000);
}
```
### Professor Richardson Schawarski
