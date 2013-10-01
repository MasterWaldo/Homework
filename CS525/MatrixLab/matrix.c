#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

void  matrix_print( Matrix m, int num_rows, int num_columns ) {
    int i, j;
    for ( i=0; i<num_rows; ++i ) {
        for ( j=0; j<num_columns; ++j ) {
            printf( "%4i ", m[i][j] );
        }
        printf( "\n" );
    }
}

/* Create a matrix on the given size */
Matrix matrix_create( int num_rows, int num_columns )
{
	Matrix m;
	int i;
	int * p_m;
	
	m = malloc(num_rows *  sizeof(int*));
	
	/* Allocate memory for matrix rows */
	printf("m: %p\n", m);
	if (!m)
	{
		printf("Error allocating memory\n");
		exit(0);
	}
	
	/* Allocate memory for matrix columns */
	
	for (i = 0; i < num_rows; i++)
	{
		m[i] = malloc(num_columns * sizeof(int));
		
		//m[i] = p_m + (num_columns * i);
		printf("m[%i]: %p\n", i, m[i] );
		if (!m[i])
		{
			printf("Error allocating memory\n");
			exit(0);
		}
	}
	
	return m;
}

/* Add 2 matricies */
Matrix matrix_add( Matrix m1, Matrix m2, Matrix result, int num_rows, int num_columns )
{
	int i,j;
	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_columns; j++)
		{
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
	
	return result;
}


/* Matrix transposition */
Matrix matrix_transpose(Matrix m, int num_rows, int num_columns)
{
	int i,j;
	Matrix m_t = matrix_create(num_rows, num_columns);
	for(i = 0; i < num_rows; i++)
	{
		for(j=0; j < num_columns; j++)
		{
			m_t[i][j] = m[j][i];
		}
	}
	return m_t;
}


/* Delete matrix */
void matrix_delete (Matrix m, int num_rows)
{
	int i;
	for (i = 0; i < num_rows; i++)
	{
		free (m[i]);
	}
	
	free (m);
	
	return;
}

/* Delete row of matrix */
void   matrix_delete_row( Matrix m, int r, int num_rows )
{
	int i;
	int * p_r;
	p_r = &num_rows;
	*p_r--;
	printf("numrows: %p , %i;  p_r: %p, %i\n", &num_rows, num_rows, p_r, *p_r);
	//free(m[r]);
	// set m[r] = m[r+1], do so for rest of array, delete last row pointer.
	// Maybe
	i = r;
	while(i < num_rows-1)
	{
		m[i] = m[i+1];
		i++;
	}
	free(m[num_rows]);
	return;
}

void   matrix_delete_column( Matrix m, int c, int num_rows, int num_columns )
{
	int i, j;
	/*
	for (i = 0; i < num_rows; i++)
	{
		printf("m[%i][%i]: %i   [%p];    *(*m+%i)+%i): %i   [%p]\n", i, c, m[i][c], &m[i][c], i,c, *(*(m+i)+c), (*m+i)+c);
		//free((*(m + i) + c));
		free(&m[i][num_columns]);
	}
	*/
	// set m[i][c] to m[i][c+1]
	// do so for rest of row
	// do so for all rows
	// remove last column
	
	i = 0;
	j = c;
	while (i < num_rows)
	{
		printf(" i: %i\n", i);
		while (j < num_columns-1)
		{
			printf("j: %i\n");
			m[i][j] = m[i][j+1];
			j++;
		}
		free((m+i)+num_columns);
		i++;
	}
	
	
	return;
}

