/*

Pseduo code per algoritmo di Dijkstra

dijkstra(){
    DIST[] = infinito, nel senso cammino di costo infinito
    S, D, MAT S=sorgente, D=destinazione, MAT=matrice di adiacenza
    VISITED[] = false
    CurrentNode = S
    DIST[S] = 0 La distanza da S a S in questo momento è di 0
    boolean terminate = false
    while(!terminate){
        for(int i=0, i < N, i++){
            if(MAT[CurrentNode][i] == 0){
                Cost = DIST[CurrentNode] + MAT[CurrentNode][i]
                if(Cost < DIST[i]){
                    DIST[i] = Cost
                }
            }
        }
        VISITED[CurrentNode] = true
        CurrentNode = FindNext(N, DIST, VISITED)
        if(CurrentNode == D || CurrentNode == -1){
            terminate = true;
        }
    }
    return DIST[D];
}
*/