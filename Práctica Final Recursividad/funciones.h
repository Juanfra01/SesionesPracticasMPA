#include <string>

#define MUEVE_DERECHA       1
#define MUEVE_ABAJO         2
#define MUEVE_DERECHA_ABAJO 3


int introducirTamanyoFila();
int introducirTamanyoColumna();
int introducirValor(std::string);

void cuentaCaminosRecursivo(int*,int*,int*,int,int, int,int&);
int cuentaCaminosIterativo(int, int, int, int, int, int);
void siguienteCandidato(int*, int*, int*, int);
bool factible(int,int,int,int);

