# IoT - Sistema de Identificação de Som

Desenvolvido por Leonardo Cupari - leonardo.cupari@aluno.ifsp.edu.br / Classio Gabriel da Silva - classio.g@aluno.ifsp.edu.br

Projeto de Trabalho de Conclusão da Disciplina de Plataformas de Prototipação para IoT (E2PPT) - IFSP CTD

Visão Geral
Este projeto visa identificar, em tempo real, quaisquer emissões de ruídos sonoros, em um determinado ambiente. As informações são armazenadas em banco de dados (DynamoDB), sendo possível ter a visualização completa. O sistema é composto por três conjuntos principais:

    Publicação de Dados via MQTT:
    Através do ESP32 os dados do ambiente são coletados e são publicados atráves do protocolo MQTT.

    Controle de Identificação de Som (Back-End):
    Via Node-Red as informações de identificação de ruídos são recebidas e armazenados no banco de dados DynamoDB.

    Visualização dos Dados:
    As coletas podem ser visualizadas através da uma aba, onde temos o tempo real.

O código completo pode ser visualizado atráves do link abaixo: Código ESP32 - 

Componentes e Infraestrutura Utilizada
Módulo Detector Sensor de Som Palmas LM393
ESP32
Protocolo de comunicação MQTT
Node-Red (Back-end e Front-End) hospedado na AWS
Banco de Dados - AWS DynamoDB
Node-Red - Flow





Node-Red - UI
http://ec2-52-14-56-16.us-east-2.compute.amazonaws.com:1880/ui



