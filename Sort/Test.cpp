#include "Sort.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG
#define N 50

typedef void ( *pFp )( int*, int ); // typ wskaznikowy na funkcje sortujace

int CreateTab( int** tab, int nSize );
void qQuickSort( int* tab, int nSize ); //quick sort
void printTab( int* tab, int nSize );//wypisanie tablicy
void copyTab( int* tabCopy, int* tabOrg, int nSize ); // kopiowanie tablicy
void randNum( int* tab, int nSize );

int main( int argc, char* argv[] )
{
	
	if ( argc != 2 ) 
	{
		printf( "Usage: %s <tab_size>", argv[0]);
		return 0;
	}
	int nSize = atoi( argv[1] );

	//tablica oryginalna na losowe liczby
	int* tabOrg = NULL;
	if ( !CreateTab( &tabOrg, nSize ) )
	{
		perror("ERROR: Allocation error - CreateTab");
		return 0;
	}

	randNum( tabOrg, nSize ); //losowe liczby w tablicy org
#ifdef DEBUG
	printf("-------------------------------------------------");
	printf( "\nWARUNKOWA KOMPILACJA:\n" );
	printf( "\nBefore Sort: \n" );
	printTab( tabOrg, nSize );
	printf("\n");
#endif

	//tablica na kopie
	int* tabCopy = NULL;
	if ( !CreateTab( &tabCopy, nSize ) )
	{
		perror("ERROR: Allocation error - tabCopy");
		return 0;
	}
	copyTab( tabCopy, tabOrg, nSize );//kopiowanie z org do copy
#ifdef DEBUG
	printf( "\nCopy tab: \n" );
	printTab( tabCopy, nSize );
	printf("\n");
#endif
	
	const char* pSortTab[] = { "SelectionSort" , "InsertionSort" , "BubbleSort" , "Polowkowe" , "MixedSort", "QuickSort", "HeapSort" }; 
	pFp tab[] = { SelectionSort , InsertionSort , BubbleSort , Polowkowe , MixedSort, qQuickSort, HeapSort };//tablica napisow

	clock_t start;
	clock_t stop;
	double time = 0;
	int size = sizeof( tab ) / sizeof( pFp );
	for ( int i = 0; i < size; i++ ) //przechodzenie po sortowaniach
	{
		
		start = clock(); // rozpoczynamy liczenie czasu
		tab[i]( tabOrg, nSize );
#ifdef DEBUG //czy sortuje prawidlowo
	printf("\nAfter Sort: \n");
	printTab( tabOrg, N );
	printf("\n");
#endif
		stop = clock(); // koñczymy liczenie czasu
		time = ( double )( stop - start );
		printf( "Time of the sort %s: %lf \n\n", pSortTab[i], time ); 
		copyTab( tabOrg, tabCopy, nSize ); 
	}
	
	free( tabOrg );
	free( tabCopy );
	tabOrg = tabCopy = NULL;

	return 0;
} 


int CreateTab( int** tab, int nSize )
{
	*tab = ( int* )malloc( sizeof(int) * nSize );
	if ( !*tab ) return 0;
	memset( *tab, 0, sizeof(int) * nSize );
	return 1;
}

void randNum( int* tab, int nSize )
{
	srand( (unsigned)time(NULL) );
	for ( int i = 0; i < nSize; i++ )
		*tab++ = rand() % nSize;
}

void copyTab( int* tabCopy, int* tabOrg, int nSize ) // kopiowanie tablicy
{
	memcpy( tabCopy, tabOrg, sizeof(int) * nSize );
}

void printTab( int* tab, int nSize )//wypisanie tablicy przy sortowaniach
{
	for ( int i = 0; i < nSize; i++ )
	{

		printf( "%d ", *tab++ );
		if ( !((i+1)%10) ) printf( "\n" );
	}
}
void qQuickSort( int* tab, int nSize ) //quick sort
{
	QuickSort( tab, 0, nSize - 1 );
}
