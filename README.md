# Exemplo para ESP32-S3 de como usar o LED RGB WS2812B da placa dela
 Exemplo de como utilizar o LED RGB do tipo WS2812B que vem nas placas do ESP32-S3 utilizando o hardware de RMT (Remote Control Transceiver) presente na ESP32-S3

## Configuração
Antes de usar o projeto é necessário executar o comando `idf.py menuconfig` com um terminal que tenha acesso às ferramentas do ESP-IDF.

## Debug do código ou rodar ele passo a passo
A ESP32-S3 tem uma USB que possibilita utilizar o hardware JTAG interno da ESP32-S3. Esse hardware pode ser utilizado para controlar o avanço do código e também para depurar o código.
Para isso, é necessário utilizar o comando `openocd -f board/esp32s3-builtin.cfg` em um terminal que tenha acesso às ferramentas do ESP-IDF.

## Como utilizar a biblioteca
Para indicar em qual GPIO o LED está conectado deve utilizar o comando `idf.py menuconfig` e navegar até o menu `Controlador do LED RGB`. Dentro deste menu há as opções para a configuração do LED.

No código deve ser utilizado a função `led_setup(RMT_LED_STRIP_GPIO_NUM);` para configuração do driver que irá controlar o LED e, em seguida é possível utilizar a função `led_color(red,green,blue);`, onde:
* `red` é o quanto de vermeho o LED deve ter, sendo os valores possíveis entre 0 e 255;
* `green` é o quanto de verde o LED deve ter, sendo os valores possíveis entre 0 e 255;
* `blue` é o quanto de azul o LED deve ter, sendo os valores possíveis entre 0 e 255.
