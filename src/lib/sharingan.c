#include "sharingan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define PATH "src/config/sharingan.txt"

int verify (const char *buffer) {

  if ((!(strcmp(buffer, "list"))) || (!(strcmp(buffer, "List")))) {
    gaethering(buffer);
    exit(EXIT_SUCCESS);
  }
}

int gaethering (const char *buffer) {
  char db[]={0};
  data *sc = malloc(sizeof(data));
  f_file *ff = malloc(sizeof(f_file));
  
  if (sc == NULL || ff == NULL) {
    perror("Alocação de memória falhou");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(PATH, "r");
  if (!fp) return -1;  

  while (fgets(sc->database, sizeof(sc->database), fp)) {
    sc->point = strchr(sc->database, '=');
    if (sc->point) {
      *sc->point = '\0';
      sprintf(db, "%s ", sc->point + 1);
  }
 }
  printf("%s", db);
  fclose(fp);
  return 0;
}

int shell (void) {
  data *db = malloc(sizeof(data));
  
  if (db == NULL) {
    perror("memory allocation has failed.");
    exit(EXIT_FAILURE);
  }
    
  for (;;) {
    fprintf(stdout, "[sharingan]$ ");
    scanf("%s", db->buffer);
    if((!(strcmp(db->buffer, "exit"))) || (!(strcmp(db->buffer, "quit")))) break;
    verify(db->buffer);
  } 
  return 0;
}
