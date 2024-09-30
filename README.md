# Matrix Calculator C


> [!IMPORTANT]
> **AI Free**


Calcolatrice Matriciale sviluppata in C per tutte le operazioni con le matrici ed anche algoritmo di Laplace e calcolo della matrice inversa



> [!NOTE]
> Progetto scolastico


> [!TIP]
> Algoritmi di calcolo matriciale corretti e funzionanti

> [!WARNING]
> Corretto funzionamento dell'UI non garantito

#### Support Me


[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/P5P012BC8U)


## Snippet Laplace Algorithm

```c

float calcolaLaplaceDeterminanteMatriceNxN(float matElemAlg[][MAXCL], int dim) {
  float det = 0.0;
  float matCompl[MAXRG][MAXCL];
  int i;
  int j = 0;
  int k;
  int colonne = 0;
  if (dim == 2) return matElemAlg[0][0] * matElemAlg[1][1] - matElemAlg[0][1] * matElemAlg[1][0];
  else {
    for (k = 0; k < dim; k++) {
      for (i = 1; i < dim; i++) {
        for (j = 0; j < dim; j++) {
          if (j < colonne) matCompl[i - 1][j] = matElemAlg[i][j];
          else if (j > colonne) matCompl[i - 1][j - 1] = matElemAlg[i][j];
        }
      }
      if (k % 2 == 1) matElemAlg[0][k] = -matElemAlg[0][k];
      det += calcolaLaplaceDeterminanteMatriceNxN(matCompl, dim - 1) * matElemAlg[0][k];
      colonne++;
    }
  }
  return det;
}

```

## Licenze

| Componente         | Versione  | Copyright                         | Licenza                                                       |
|--------------------|-----------|-----------------------------------|---------------------------------------------------------------|
| [MatrixCalculator](https://github.com/vittorioPiotti/MatrixCalculator-C) | [v1.0.0](https://github.com/vittorioPiotti/MatrixCalculator-C/releases/tag/v1.0.0)    | 2024 Vittorio Piotti [(GitHub page)](https://github.com/vittorioPiotti) [(Personal page)](https://vittoriopiotti.altervista.org/)            | [GPL-3.0 ](https://github.com/vittorioPiotti/MatrixCalculator-C/blob/main/LICENSE.md) |
