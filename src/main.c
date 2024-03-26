/*
   Sharingan Framework - CyberZ
*/
#include <stdio.h>
#include "lib/sharingan.h"
int main (void) {
  if (shell() != 0) {
    fprintf(stderr, "[X]: Não foi possível executar a shell corretamente.\n");
    return -1;
  }
}
