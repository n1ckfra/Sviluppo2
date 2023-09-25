#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int osserva(int N, int H[]) {
    int maxSx, maxDx, max = 0;

    for (int i = 0; i < N; i++)
    {
        // Left side cycle
        for (int j = i; j > 0 ; j--)
        {
            
        }

        // Right side cycle
        for (int k = i; k < N; k++)
        {

        }
    }
    
    
    
}


int H[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", osserva(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
