/*
Pseduo code:

Struct{   DESCRIVE UN ARCO, A B componenti che collega, R pioggia sopportabile
    int a;
    int b;
    int r;
}

ARCO S[MAXM]; Sort di tuttgli gli array di struct

INT RAPP[MAXM]; n sono i nodi e il valore è il rappresentante (Componente a cui è connessa, all'inizio ognuno è rappresentante di se stesso)


int FINDR(n){
    IF(RAPP[n] == n)
        return n;
    ELSE{
        RAPP[n] = FINDR(RAPP[n]);
        return RAPP[n];
    }
}


int KRUSKAL(){
    for(int i = 0; i < N, i++){
        RAPP[i]=i;
    }
    SORT(S) // Decresente sul valore R, Da R piu grande a R piu piccolo  (Non usare bubble sort, meglio quick sort)
    INT FloodLevel;
    INT NConnection;

    for(int i = 0; i < M, i++){
        IF(NConnection == N-1) break;
        RAPPA = FINDR(A);
        RAPPB = FINDR(B);
        IF(RAPPA!=RAPPB){
            NConnection++;
            FloodLevel = S[i].r
            RAPP[RAPPA] = RAPPB;
        }
    }

    return FloodLevel;
}

main{
    for(int i = 0; i < M, i++){
        scanf("%d%d%d", &S[i].a, &S[i].b, &S[i].r)
    }

    INT FloodLevel = KRUSKAL di S
    Print(FloodLevel);
}

*/