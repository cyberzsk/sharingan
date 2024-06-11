#ifndef _SHARINGAN_H
#define _SHARINGAN_H

/* Database */
typedef struct {
  char database[1024];  
  char buffer[1024];
  char *tbuffer;
  char *point, *spoint, *tpoint, *qpoint;
  int n_thread;                              
  int x, y;
} data;

typedef struct {
  char *bin_path;
  char *proxy;
  char *theme;
  char *n_thread;
} f_file;

/* Functions */
int shell(void);
int verify(const char *buffer);
int gaethering(const char *buffer);
#endif

