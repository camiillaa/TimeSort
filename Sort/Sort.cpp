
#include "Sort.h"


void Update( int l, int p, int* tab );


void SelectionSort( int* tab, int nSize )//przez wybieranie
{

	for ( int i = 0; i < nSize - 1; i++ )
	{
		int k = i;
		int min = tab[i];

		for ( int j = i + 1; j < nSize; j++ )
		{
			if ( tab[j] < min )
			{
				min = tab[j];
				k = j;
			}
		}
		tab[k] = tab[i];
		tab[i] = min;
	}

}


void InsertionSort( int* tab, int nSize )//wstawianie
{
	for ( int i = 1; i < nSize; i++ )
	{
		int x = tab[i];
		int j = i - 1;
		while ( (j >= 0) && (tab[j] > x) )
			tab[j + 1] = tab[j--];
		tab[j + 1] = x;
	}
}

void BubbleSort( int* tab, int nSize ) //babelkowe
{
	for ( int i = 0; i < nSize - 1; i++ )
	{
		for ( int j = nSize - 1; j > i; j-- )
		{
			if ( tab[j - 1] > tab[j] )
			{
				int temp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = temp;
			}
		}
	}
}




void Polowkowe( int* tab, int nSize )
{
	for ( int i = 1; i < nSize; i++ )
	{
		int x = tab[i];
		int p = i - 1;
		int l = 0;
		while ( l <= p )
		{
			int m = (l + p) / 2;
			if ( x < tab[m] )
				p = m - 1;
			else
			l = m + 1;//l=m-1 tak bylo w Wirth'cie ale chyba jest zle

		}
		for ( int j = i-1; j >= l; j-- )
			tab[j + 1] = tab[j];
			
		tab[l] = x;
	}
}
void MixedSort( int* tab, int nSize )
{
	int l = 1;
	int p = nSize-1;
	int k = nSize-1;

	while ( l < p )
	{
		for ( int j = p; j >= l; j-- )
		{ 
			if ( tab[j - 1] > tab[j] )
			{
				int x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		l = k + l;
		for ( int j = l; j <= p; j++ )
		{
			if (tab[j - 1] > tab[j])
			{
				int x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		p = k - l;
	}
}

void QuickSort( int* tab, int l, int p )
{

	int i = l; 
	int j = p;
	int x = tab[(l + p) / 2]; 
	
	while ( i < j )
	{

		while ( tab[i] < x ) i++;
		while ( tab[j] > x ) j--;

		if ( i <= j )
		{
			int w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++;
			j--;
		}
	}
	if ( l < j ) QuickSort( tab, l, j );
	if ( i < p ) QuickSort( tab, i, p );

}

void HeapSort( int* tab, int nSize )
{
	for ( int l = nSize / 2; l >= 0; l-- )
		Update( l, nSize - 1, tab );

	for ( int p = nSize - 1; p > 0; p-- )
	{
		int x = tab[p];
		tab[p] = tab[0];
		tab[0] = x;
		Update(0, p - 1, tab);
	}
	/*int l = nSize / 2;
	while (l >= 0)
	{
		Update(l, nSize-1, tab);
		l--;
	}

	int p = nSize - 1;
	while (p > 0)
	{
		int x = tab[0];
		tab[0] = tab[p];
		tab[p] = x;
		Update(0, p - 1, tab);
	}*/
}


void Update( int l, int p, int* tab )
{
	if ( l >= p ) return;

	int i = l;
	int j = 2 * i + 1;
	int x = tab[i];

	while ( j <= p )
	{
		if ( j < p )
			if ( tab[j] < tab[j + 1] ) j++;

		if ( x >= tab[j] ) break;

		tab[i] = tab[j];
		i = j;
		j = 2 * i + 1;
	}

	tab[i] = x;
	
}



