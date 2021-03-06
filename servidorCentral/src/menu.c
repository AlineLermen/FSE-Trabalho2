// #include <curses.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "menu.h"
#include "comunicacao.h"

void atualizaDispositivo(int dispNum, int novoStatus, int serv){
  unsigned short int porta = serv ? 10230 : 10130;

  enviaDistribuido(dispNum, novoStatus, porta);
}

char * verificaOnOff(int estadoSensorAparelho) {
    if(estadoSensorAparelho == 1)
        return "ON";
    else
        return "OFF";

}

void mostraMenu() {

    printf(" ----- STATUS DAS ENTRADAS -----\n\n");

    printf(" -- ANDAR TERREO --\n");
    printf("  Sensor de presenca: %s\n", verificaOnOff(sensores.presencaTerreo));
    printf("  Sensor de fumaca: %s\n", verificaOnOff(sensores.fumacaTerreo));
    printf("  Sensor janela T01: %s\n", verificaOnOff(sensores.janelaT1));
    printf("  Sensor janela T02: %s\n", verificaOnOff(sensores.janelaT2));
    printf("  Sensor porta de entrada: %s\n", verificaOnOff(sensores.portaTerreo));
    printf("  Sensor de contagem de pessoas entrando:\n");
    printf("  Sensor de contagem de pessoas saindo:\n");

    printf(" -- ANDAR 1 --\n");
    printf("  Sensor de presenca: %s\n", verificaOnOff(sensores.presencaAndar));
    printf("  Sensor de fumaca: %s\n", verificaOnOff(sensores.fumacaAndar));
    printf("  Sensor janela 101: %s\n", verificaOnOff(sensores.janela101));
    printf("  Sensor janela 102: %s\n", verificaOnOff(sensores.janela102));
    printf("  Sensor de contagem de pessoas entrando:\n");
    printf("  Sensor de contagem de pessoas saindo:\n");


    printf(" ----- STATUS DAS SAIDAS -----\n\n");

    printf(" -- Codigo | ANDAR TERREO\n");
    printf("       0   | Lampada sala T01: %s\n", verificaOnOff(aparelhos.lampadaT01));
    printf("       1   | Lampada sala T02: %s\n", verificaOnOff(aparelhos.lampadaT02));
    printf("       2   | Lampada corredor: %s\n", verificaOnOff(aparelhos.lampadaCorrTerreo));
    printf("       3   | Ar-condicionado: %s\n", verificaOnOff(aparelhos.arCondicionadoTerreo));
    printf("       4   | Aspersores de ??gua: %s\n", verificaOnOff(aparelhos.aspersores));

    printf(" -- Codigo | ANDAR 1\n");
    printf("       5   | Lampada sala 101: %s\n", verificaOnOff(aparelhos.lampada101));
    printf("       6   | Lampada sala 102: %s\n", verificaOnOff(aparelhos.lampada102));
    printf("       7   | Lampada corredor: %s\n", verificaOnOff(aparelhos.lampadaCorrAndar));
    printf("       8   | Ar-condicionado: %s\n", verificaOnOff(aparelhos.arCondicionadoAndar));

}

void menuAtivaDesativa() {
    system("clear");

    printf("\n  Qual dos dispositivos deseja ativar/desativar? Digite o c??digo respectivo\n\n");
    printf("   CODIGO   |     DISPOSITIVO     |   STATUS ATUAL\n");
    printf("------------|---------------------|------------------\n");
    printf("                    TERREO       \n");
    printf("------------|---------------------|------------------\n");
    printf("     0      | Lampada sala T01    |      %s\n", verificaOnOff(aparelhos.lampadaT01));
    printf("     1      | Lampada sala T02    |      %s\n", verificaOnOff(aparelhos.lampadaT02));
    printf("     2      | Lampada corredor    |      %s\n", verificaOnOff(aparelhos.lampadaCorrTerreo));
    printf("     3      | Ar-condicionado     |      %s\n", verificaOnOff(aparelhos.arCondicionadoTerreo));
    printf("     4      | Aspersores de ??gua  |      %s\n", verificaOnOff(aparelhos.aspersores));

    printf("------------|---------------------|------------------\n");
    printf("                    ANDAR 1    \n");
    printf("------------|---------------------|------------------\n");
    printf("     5      | Lampada sala 101:   |      %s\n", verificaOnOff(aparelhos.lampada101));
    printf("     6      | Lampada sala 102:   |      %s\n", verificaOnOff(aparelhos.lampada102));
    printf("     7      | Lampada corredor:   |      %s\n", verificaOnOff(aparelhos.lampadaCorrAndar));
    printf("     8      | Ar-condicionado:    |      %s\n", verificaOnOff(aparelhos.arCondicionadoAndar));

    
    __fpurge(stdin);
    char comando = getchar();

    if(comando == '0') {
        printf("COMANDO 0\n");
        aparelhos.lampadaT01 = !aparelhos.lampadaT01;
        atualizaDispositivo(4,aparelhos.lampadaT01,0);
    } 
    else if(comando == '1') {
        printf("COMANDO 1\n");
        aparelhos.lampadaT02 = !aparelhos.lampadaT02;
        atualizaDispositivo(17,aparelhos.lampadaT02,0);
    }
    else if(comando == '2') {
        printf("COMANDO 2\n");
        aparelhos.lampadaCorrTerreo = !aparelhos.lampadaCorrTerreo;
        atualizaDispositivo(27,aparelhos.lampadaCorrTerreo,0);
    }
    else if(comando == '3') {
        printf("COMANDO 3\n");
        aparelhos.arCondicionadoTerreo = !aparelhos.arCondicionadoTerreo;
        atualizaDispositivo(7,aparelhos.arCondicionadoTerreo,0);
    }
    else if(comando == '4') {
        printf("COMANDO 4\n");
        aparelhos.aspersores = !aparelhos.aspersores;
        atualizaDispositivo(16,aparelhos.aspersores,0);
    }
    else if(comando == '5') {
        printf("COMANDO 5\n");
        aparelhos.lampada101 = !aparelhos.lampada101;
        atualizaDispositivo(22,aparelhos.lampada101,1);
    }
    else if(comando == '6') {
        printf("COMANDO 6\n");
        aparelhos.lampada102 = !aparelhos.lampada102;
        atualizaDispositivo(25,aparelhos.lampada102,1);
    }
    else if(comando == '7') {
        printf("COMANDO 7\n");
        aparelhos.lampadaCorrAndar = !aparelhos.lampadaCorrAndar;
        atualizaDispositivo(8,aparelhos.lampadaCorrAndar,1);
    }
    else if(comando == '8') {
        printf("COMANDO 8\n");
        aparelhos.arCondicionadoAndar = !aparelhos.arCondicionadoAndar;
        atualizaDispositivo(12,aparelhos.arCondicionadoAndar,1);
    }
    else if(comando == '9') {
        printf("COMANDO 9\n");
    }
    else {
        printf("Comando inv??lido\nAperte 'ENTER' para tentar novamente.\n");
        // __fpurge(stdin);
        // getchar();
        sleep(2);
        system("clear");

    }
}

void trata_SIGTSTP(int signum) {

    menuAtivaDesativa();

}

void* menuFunc() {
    signal(SIGTSTP, trata_SIGTSTP);
    // system("clear");
    while(1) {
        system("clear");
        mostraMenu();
        sleep(2);
        // leTempUmidade();
        __fpurge(stdin);

    }

}

void trataSensores(int comando) {
  
  switch (comando)
  {
    case 1:
      sensores.presencaAndar = !sensores.presencaAndar;
      break;
    case 2:
      sensores.fumacaAndar = !sensores.fumacaAndar;
      break;
    case 3:
      sensores.janela101 = !sensores.janela101;
      break;
    case 4:
      sensores.janela102 = !sensores.janela102;
      break;
    case 5:
      sensores.presencaTerreo = !sensores.presencaTerreo;
      break;
    case 6:
      sensores.fumacaTerreo = !sensores.fumacaTerreo;
      break;
    case 7:
      sensores.janelaT1 = !sensores.janelaT1;
      break;
    case 8:
     sensores.janelaT2 = !sensores.janelaT2;
      break;
    case 9:
      sensores.portaTerreo = !sensores.portaTerreo;
      break;
    case 10:
      break;
    case 11:
      break;
    default:
      break;
  }
}