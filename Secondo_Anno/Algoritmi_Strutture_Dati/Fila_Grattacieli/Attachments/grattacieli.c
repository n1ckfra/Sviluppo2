#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int osserva(int N, int H[]) {
    int maxSx, maxDx, max = 0;

    // We find the maximum height
    for (int i = 0; i < N; i++)
    {
        if (H[i] > max)
        {
            max = H[i];
        }
        
    }
    
    // We check from each builing having height equal to max
    for (int i = 0; i < N; i++)
    {
        int counter = 0;
        if (H[i] < max)
        {
            counter++;
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
