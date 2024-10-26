#include <WiFi.h>
#include <PubSubClient.h>

// Configurações de Wi-Fi
const char* ssid = "iPhone de Leonardo";
const char* password = "leo12345";

// Configurações do servidor MQTT
const char* mqtt_server = "18.219.56.144";  // IP do seu broker MQTT
const int mqtt_port = 1883;                 // Porta do broker MQTT
const char* mqtt_topic = "sensor/som";      // Tópico onde os dados serão publicados

WiFiClient espClient;
PubSubClient client(espClient);

// Definição dos pinos
const int pinAnalog = 34;  // Pino analógico para a leitura do nível de som

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop até conseguir conexão com o servidor MQTT
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    if (client.connect("ESP32Client")) {  // Identificador único para o cliente
      Serial.println("Conectado ao MQTT!");
    } else {
      Serial.print("Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  // Configuração Wi-Fi
  setup_wifi();
  
  // Configuração MQTT
  client.setServer(mqtt_server, mqtt_port);  // Conecta ao broker MQTT
}

void loop() {
  // Reconectar se desconectar do MQTT
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Ler o valor do sensor de som (0 a 4095)
  int nivelSom = analogRead(pinAnalog);

  // Definir limiar para detecção de som
  int limiarSom = 1000;  // Ajuste conforme necessário para seu sensor

  // Verificar se o nível de som está acima do limiar
  if (nivelSom > limiarSom) {
    client.publish(mqtt_topic, "1");  // Som detectado
    Serial.println("Som detectado! Enviando 1 para o MQTT.");
  } else {
    client.publish(mqtt_topic, "0");  // Sem som
    Serial.println("Sem som. Enviando 0 para o MQTT.");
  }

  // Aguardar 5 segundos antes de enviar o próximo dado
delay(5000);
}