/* ManejoDeArgumentos.c */

#include <stdio.h>
#include <unistd.h>

void uso(const char* progname, int valor_retorno);

int
main(int argc, char *argv[]) {

  extern char *optarg;
  extern int optind, opterr, optopt;
  int option;
  int tipo_saludo = 0; // 0: Saludar 1: Despedir

  /* 
   * Verificando los argumentos
   */

  while ((option = getopt(argc, argv, ":sdh")) != -1) {

    switch (option) {      
    case 's':
      tipo_saludo = 0;
      break;

    case 'd':
      tipo_saludo = 1;
      break;

    case 'h':
      uso(argv[0], 0);
      break;
      
    case '?':
    default:
      uso(argv[0], 1);
      break;
    }
  }

  if (optind == (argc - 1)) {
    switch(tipo_saludo) {
    case 0:
      printf("Hola %s\n", argv[optind]);
      break;
    case 1:
      printf("Adios %s\n", argv[optind]);
      break;
    }
  }
  else {
    printf("Poner un argumento\n");
    uso(argv[0], 1);
  }
 

  return 0;
}

void uso(const char* nombre_programa, int valor_retorno) {
  fprintf(stdout, "Uso: %s -h\n", nombre_programa);
  fprintf(stdout, "     %s [-s] [-d] <nombre>\n", nombre_programa);
  _exit(valor_retorno);
}
