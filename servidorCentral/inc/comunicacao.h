#ifndef COMUNICACAO_H_
#define COMUNICACAO_H_

typedef struct {
  float temperature;
  float humidity;
} DHT22;

#define SERVER_DISTRIBUTED_IP "192.168.0.52"
#define SERVER_CENTRAL_PORT 10030
#define SERVER_DISTRIBUTED_PORT 10130


void acionaDistribuido();
void *recebeDistribuido();
void leTempUmidade();
int enviaDistribuido(int item, int status, unsigned short int porta);

#endif /* COMUNICACAO_H_ */