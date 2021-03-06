# PegasusServer

## Introdução

PegasusServer é um projeto desenvolvido sobre a plataforma [Arduino](https://www.arduino.cc), mais especificamente para a placa [Ameba RTL8195](https://www.amebaiot.com/en/boards/). Possui como interface de comunicação com o usuário o aplicativo [PegasusApp](https://github.com/JoaoPauloZ/PegasusApp). A comunicação entre os dois dispositivos se dá através da __*especificação de comunicação*__, sendo esta implementada sobre protocolo de rede [UDP](https://pt.wikipedia.org/wiki/User_Datagram_Protocol). 

## Dependências

### Obrigatórias:
* [Arduino IDE](https://www.arduino.cc/en/Main/Software);
* [Ameba RTL8195](https://www.amebaiot.com/en/boards/);
* [PegasusApp](https://github.com/JoaoPauloZ/PegasusApp).

### Recomendas:
* [VSCode](https://code.visualstudio.com);
* [Visual Studio Code extension for Arduino](https://github.com/Microsoft/vscode-arduino);
* [Microsoft C/C++ extension for VS Code.](https://github.com/Microsoft/vscode-cpptools);

## Configuração

1. __Arduino IDE:__ A [Ameba RTL8195](https://www.amebaiot.com/en/boards/) necessita de configurações apropriadas para funcionar com a Arduino IDE. Estas configurações podem ser feitas seguindo os passos desse [tutorial](https://www.amebaiot.com/en/ameba-arduino-getting-started/);

2. __Rede Wi-Fi:__ No arquivo ```PegasusServer.cpp``` na função ```void PegasusServer::init()``` alterar os valores das váriaveis ```char ssid[]``` e ```char pass[]``` para os valores da sua rede Wi-Fi. É importatne salientar que o __PegasusServer__ não cria um *Access Point* próprio, sendo portanto necessário uma rede Wi-Fi já configurada para que o mesmo possa conectar-se;


## Hardware

### Componentes:

* 4 motores; 
* 4 ESCs;
* 4 hélices;
* Frame;
* Bateria

### Disposição dos motores:
Para o funcionamento do drone os motores devem respeitar a disposição da imagem abaixo, isso porque as manobras de __*pitch, yaw*__ e __*row*__ são comandadas alterando a velocidade de giro de determinados motores. Também deve-se respeitar o sentido de giro descrito, isso porque os motores tem que *se anularem*.

<img src="/Images/motors-layout.png" alt="Layout dos motores" width="500">
Fonte: xxxx

Para alterar os pinos de comando dos motores no arquivo ```PegasusFlightController.cpp``` na função ```PegasusFlightController::PegasusFlightController()``` altere os valores passados para a inicialização dos motores desejados.
