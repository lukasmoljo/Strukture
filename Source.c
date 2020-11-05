#include<stdio.h>
#include<string.h>
#include<math.h>


typedef struct ucenik {
    char ime[50], prez[50];
    int bod;
} ucenik;

int main() {
    FILE* f = fopen("file.txt", "r");
    ucenik tmp;
    int n;     
    for (n = 0; fscanf(f, "%s %s %d", tmp.ime, tmp.prez, &tmp.bod) != 0; n++) {} 

    int tot = 0; 

    ucenik* ucenici = (ucenik*)malloc(n * sizeof(ucenik));
    f = fopen("file.txt", "r"); 
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s %s %d", ucenici[i].ime, ucenici[i].prez, &ucenici[i].bod);
        tot += ucenici[i].bod;
        
    }

    printf("apsolutni broj bodova je %d", tot);
    printf("prosjecni broj bodova je %f", (float)tot / n);

    return 0;

}
