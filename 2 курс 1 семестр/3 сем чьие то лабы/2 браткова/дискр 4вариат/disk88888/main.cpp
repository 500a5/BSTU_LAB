/*#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
*/
#include "dijkstra.h"

int main()
{
	int N, start;
	int** G;
	G = ReadGraph(N);
	WriteGraph(G, N);
	printf("Enter first vertex [1..%i]: ", N);
	scanf("%i",&start);
	Dijkstra(G,N,start-1);
	FreeMem(G,N);
	system("PAUSE");
	return 0;
}
