# 🏡 Projeto Casa Inteligente com Arduino: Sistema de Segurança Residencial 🔒

Este repositório contém o código-fonte, diagramas de circuito e documentação para o projeto de um sistema de segurança residencial inteligente desenvolvido com Arduino, com funcionalidades de automação e comunicação remota via aplicativo.

---

## 📋 Índice

* [🌟 Introdução](#-introdução)
* [✨ Funcionalidades](#-funcionalidades)
* [🛠️ Materiais Utilizados](#%EF%B8%8F-materiais-utilizados)
* [💻 Estrutura do Software](#-estrutura-do-software)
    * [🤖 Arduino](#-arduino)
    * [🌐 NodeMCU](#-nodemcu)
* [🔌 Circuito](#-circuito)
* [🏠 Projeto Finalizado](#-projeto-finalizado)
* [🚀 Como Utilizar](#-como-utilizar)
* [🧑‍💻 Desenvolvedores](#%F0%9F%A7%91%E2%80%8D%F0%9F%92%BB-desenvolvedores)
* [📄 Licença](#-licença)

---

## 🌟 Introdução

Este projeto consiste em uma solução de automação residencial inteligente, com foco em segurança, que aplica conceitos da disciplina de Sistemas Digitais II. Ele combina sensores, alarmes e comunicação remota para resolver desafios do mundo real, utilizando conhecimentos em eletrônica e programação. O sistema foi desenvolvido para ser acessível, eficiente e personalizável para a proteção de residências.

---

## ✨ Funcionalidades

O sistema de segurança residencial oferece as seguintes funcionalidades principais:

* **Detecção de Gás:** Identifica a presença de gás no ambiente. ⛽
* **Detecção de Presença:** Detecta a movimentação no ambiente. 🚶‍♂️
* **Abertura de Porta:** Controla a abertura e fechamento de uma porta. 🚪
* **Acionamento de Ventilador:** Liga um ventilador em resposta a certas condições. 🌬️
* **Comunicação Remota:** Envia mensagens via WhatsApp para alertar sobre eventos. 💬

---

## 🛠️ Materiais Utilizados

Para a implementação do projeto, foram utilizados os seguintes componentes:

* Arduino
* Display LCD
* Sensores (Gás e presença)
* Resistores
* Módulos:
    * ESP 8266
    * NodeMCU
    * Serial I2C para Display LCD
    * Módulo WiFi ESP8266 NodeMcu Amica ESP-12E
    * Conversor de Nível Lógico 3.3V-5V Bidirecional - 4 Canais
    * Módulo WiFi Serial ESP8266 ESP-01s S Series
    * Módulo Sensor de Distância Ultrassônico HC-SR04
* Servo motor
* Protoboard
* Buzzer
* Jumpers
* Pilhas e baterias
* Suporte para 4 Pilhas AA
* Micro Servo Motor MG90S 180° Engrenagens metálicas
* Buzzer Ativo 5v
* Display LCD 16x2 com Backlight Azul
* Suporte para 3 Pilhas AA - Branco
* Transistor NPN 2N2222
* Hélice para Motor DC
* Mini Motor DC 3-6V
* Sensor de Gás MQ-5 GLP (Gás de Cozinha) e Gás Natural

---

## 💻 Estrutura do Software

O software é dividido em duas partes principais, rodando no Arduino e no NodeMCU, respectivamente:

### 🤖 Arduino

O código do Arduino gerencia a lógica principal dos sensores e atuadores:

* **Início:** Configuração de Variáveis e Bibliotecas. 📚
* **Setup:** Inicializa Sensores, Atuadores e LCD. ⚙️
* **Loop:**
    * Verifica Estado dos Interruptores. 🔄
    * Coleta Dados Sensores. 📊
    * Aciona Servo Motor. ➡️
    * Detectou Gás? Aciona Ventilador e Exibe Alerta. 🚨
    * Detectou Presença? Aciona Buzzer e Exibe Alerta. 🔔
    * Liga/Desliga Estado Segurança. 🛡️
    * Liga/Desliga Blacklight LCD. 💡
    * Desliga Buzzer e Ventilador. 🔇

### 🌐 NodeMCU

O código do NodeMCU é responsável pela conectividade à internet e comunicação remota:

* **Início:** Bibliotecas e Variáveis. 📂
* **Setup:** Conecta no wifi e Manda mensagem: "Estamos conectados". 📶
* **Loop Infinito:**
    * Se Segurança Ativada:
        * Detectou gás? Manda mensagem: "Gás detectado". 🔥
        * Detectou Presença? Manda mensagem: "Presença detectada". 🏃‍♀️

---

## 🔌 Circuito

O circuito integra todos os componentes eletrônicos. No projeto, utilizamos os módulos ESP8266 NodeMCU Amica ESP-12E e ESP-01s S Series, conversores de nível lógico, além de periféricos como o display LCD, buzzer, servo motor e os sensores de gás e presença. Você pode visualizar a montagem física nas imagens do projeto finalizado.

---
<!-- 
## 🏠 Projeto Finalizado

Confira as imagens do nosso projeto em funcionamento (disponíveis nas páginas 13, 14, 15 e 16 da apresentação original):

* [Imagem 1]
* [Imagem 2]
* [Imagem 3]
* [Imagem 4]

*(Sugestão: Adicione aqui links ou miniaturas das imagens do projeto finalizado, se possível.)*

---
-->

## 🚀 Como Utilizar

Para configurar e rodar o seu próprio sistema:

1.  **Montagem do Circuito:** Conecte todos os componentes conforme os diagramas de circuito (disponíveis em breve ou na documentação original do projeto). 🛠️
2.  **Configuração do Arduino IDE:**
    * Instale o Arduino IDE. 💻
    * Adicione as bibliotecas necessárias (Servo, LiquidCrystal I2C, ESP8266WiFi, etc.). ➕
    * Carregue o código do Arduino para a placa. ⬆️
3.  **Configuração do NodeMCU:**
    * Carregue o código do NodeMCU para a placa. ⬆️
    * Configure as credenciais da sua rede Wi-Fi no código. 🔑
4.  **Configuração do RemoteXY:**
    * Utilize o aplicativo RemoteXY para criar a interface de controle no seu celular. 📱
    * Conecte o aplicativo ao seu Arduino via Wi-Fi. 🔗

---

## 🧑‍💻 Desenvolvedores

Este projeto foi desenvolvido com dedicação por:

* **Gustavo Guimarães**
* **Tallys Freitas**
* **Vitor Gabriel**

---
<!--

## 📄 Licença

Este projeto está licenciado sob a [coloque aqui a licença, por exemplo: Licença MIT]. Sinta-se à vontade para explorar, modificar e usar o código conforme os termos da licença. Veja o arquivo `LICENSE` para mais detalhes.

---

-->
