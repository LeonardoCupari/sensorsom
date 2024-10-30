# IoT - Sistema de Identificação de Som

Desenvolvido por Leonardo Cupari - leonardo.cupari@aluno.ifsp.edu.br / Classio Gabriel da Silva - classio.g@aluno.ifsp.edu.br

Projeto de Trabalho de Conclusão da Disciplina de Plataformas de Prototipação para IoT (E2PPT) - IFSP CTD

# Visão Geral
Este projeto visa identificar, em tempo real, quaisquer emissões de ruídos sonoros, em um determinado ambiente. As informações são armazenadas em banco de dados (DynamoDB), sendo possível ter a visualização completa. O sistema é composto por três conjuntos principais:

    Publicação de Dados via MQTT:
    Através do ESP32 os dados do ambiente são coletados e são publicados atráves do protocolo MQTT.

    Controle de Identificação de Som (Back-End):
    Via Node-Red as informações de identificação de ruídos são recebidas e armazenados no banco de dados DynamoDB.

    Visualização dos Dados:
    As coletas podem ser visualizadas através da uma aba, onde temos o tempo real.

O código completo pode ser visualizado atráves do link abaixo: Código ESP32 - https://github.com/LeonardoCupari/sensorsom/blob/main/sketch_oct18a.ino

# Componentes e Infraestrutura Utilizada
Módulo Detector Sensor de Som Palmas LM393
ESP32
Protocolo de comunicação MQTT
Node-Red (Back-end e Front-End) hospedado na AWS
Banco de Dados - AWS DynamoDB

# Node-Red - Flow
![image](https://github.com/user-attachments/assets/21e5d03f-ea81-47e1-bb90-875ddd1f7835)
![image](https://github.com/user-attachments/assets/82910b12-3925-459d-b7b0-3dafe245ecbd)

# Node-Red - UI
http://ec2-3-145-147-198.us-east-2.compute.amazonaws.com:1880/ui/#!/0?socketid=UZFvOcEpKWhqXkSQAAAX

Monitoramento em tempo real via MQTT
![image](https://github.com/user-attachments/assets/3a0368ed-4ce6-4e90-9340-b05f5ffd7ef5)

Dados coletados e armazenados no banco de dados DynamoDB
![image](https://github.com/user-attachments/assets/cf072500-4a11-435e-a430-7b6de377a5c0)
Legenda: 0 para não identificação de som e 1 para identificado som

# JSONs
https://github.com/LeonardoCupari/sensorsom/blob/main/ESP32%20-%20JSON
https://github.com/LeonardoCupari/sensorsom/blob/main/TABELAS%20-%20JSON

# Simulação Wokwi

Os circuitos estão simulados na plataforma Wokwi e podem ser acessados através do link abaixo: https://wokwi.com/projects/412763205132126209

Simulação da elaboração, com sensor de presença (adaptado), visto que não encontramos a opção de som a qual compramos fisicamente.
![image](https://github.com/user-attachments/assets/5dec841c-3058-4027-9ee4-f373f4181d7a)

Simulação do projeto em execução
![image](https://github.com/user-attachments/assets/7c909d7a-8b0d-469d-9eea-2cb0496ca2dc)


    




