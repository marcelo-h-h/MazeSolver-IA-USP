#include <vector>
#include <priority_queue>
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;


typedef struct grafo{
	int** table;
	int largura, altura;
}GRAFO;


typedef struct vertice{
	int x,y;
	long heuristica, custo;
}VERTICE;


bool isEqual( VERTICE one, VERTICE two ){
	if( one.x == two.x && one.y == two.y )
		return true;
	return false;
}


class COMPARE {
	public:
	bool operator() (VERTICE a, VERTICE b) {
		if( a.heuristica + a.custo > b.heuristica + b.custo )
			return true;
		return false;
	}
};


int manhattan( VERTICE one, VERTICE two ){

	return abs( one.x - two.x ) + abs( one.y - two.y );

}

//TODO
stack<pair<int,int>> reconstruir( GRAFO grafo, int fim_x, int fim_y ){

	int ajacente[4][2] = { {1,0},{0,-1},{-1,0},{0,1} }
	stack<pair<int,int>> answer;
	x_atual = fim_x;
	y_atual = fim_y;
	peso_atual = grafo.table[fim_x][fim_y];
	
	while(peso_atual != 2){
		for( int i=0; i<4; i++ ){
			//se o passo anterior era aqui...
			if( grafo[x_atual+adjacente[i][0]][y_atual+adjacente[i][1]] == peso_atual-1 ){
				answer.push( make_pair(x_atual, y_atual) );
				peso_atual--;
				x_atual = x_atual+adjacente[i][0];
				y_atual = y_atual+adjacente[i][1];
				break;
			}
		}
	}

}

GRAFO a_estrela ( GRAFO grafo, VERTICE inicio, VERTICE fim ){

	int ajacente[4][2] = { {1,0},{0,-1},{-1,0},{0,1} }
	priority_queue< VERTICE, vector<VERTICE>, COMPARE > heap;
	heap.push( inicio );
	grafo.table[inicio.x][inicio.y] = 2;

	while() {
		VERTICE atual = heap.top();
		int peso_atual = grafo.table[atual.x][atual.y];
		heap.pop();
		if( isEqual( atual, fim ) ){
			break;
		}
		for(int i=0; i<4;i++){
			if(grafo.table[atual.x+adjacente[i][0]][atual.y+adjacente[i][1]] == 0){
				grafo.table[atual.x+adjacente[i][0]][atual.y+adjacente[i][1]] = peso_atual+1;
				VERTICE novo;
				novo.x = atual.x+adjacente[i][0];
				novo.y = atual.y+adjacente[i][1];
				novo.heuristica = manhattan( novo, fim );
				novo.custo = peso_atual+1;
			}
		}
	}

	return grafo;
}


void imprimir_caminho( stack<pair<int,int>> caminho, file* saida ){
	while(!caminho.empty()){
		pair<int,int> prox = caminho.top();
		fprintf( saida, "%d %d\n", prox->first, prox->second );
		caminho.pop();
	}
}


int main(int argc, char* argv){

	entrada = argv[1];
	saida = argv[2];

	

return 0;
}
