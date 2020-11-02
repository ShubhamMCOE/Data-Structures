#include<stdio.h>

void Accept(int a[][5],int row,int col) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			printf("\nEnter Matrix a[%d][%d] = ",i,j);
			scanf("%d", &a[i][j]);
		}
}

void Display(int a[][5], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("\t%d",a[i][j]);
		printf("\n");
	}
}

void Addition(int a[][5], int r1, int c1, int b[][5], int r2, int c2) {
	int sum[5][5];
	if (r1 == r2 && c1 == c2) {
		for (int i = 0; i < r1; i++)
			for (int j = 0; j < c1; j++)
				sum[i][j] = a[i][j] + b[i][j];
		printf("\nSum = \n");
		Display(sum, r1, c1);
		return;
	}
	printf("\nMatrix Addition Not Possible");
}

void Subtraction(int a[][5], int r1, int c1, int b[][5], int r2, int c2) {
	int sum[5][5],diff[5][5];
	if (r1 == r2 && c1 == c2) {
		for (int i = 0; i < r1; i++)
			for (int j = 0; j < c1; j++)
				sum[i][j] = a[i][j] - b[i][j];
		printf("\nDiff = \n");
		Display(sum, r1, c1);
		return;
	}
	printf("\nMatrix Subtraction Not Possible");
}

void Transpose(int a[][5], int row, int col) {
	int new[5][5];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			new[j][i] = a[i][j];
	printf("\nTrasposed Matrix = \n");
	Display(new, col, row);
}

void Multiply(int a[][5], int r1, int c1, int b[][5], int r2, int c2) {
	int mult[5][5] = { 0 };
	if (c1 == r2) {
		for (int i = 0; i < r1; i++)
			for (int j = 0; j < c2; j++)
				for (int k = 0; k < c1; k++)
					mult[i][j] += (a[i][k] * b[k][j]);
		Display(mult, r1, c2);
		return;
	}
	printf("\nMatrix Multiplication Not Possible");
}

void Saddle_Point(int a[][5], int row, int col) {
	int min_row,max_col;
	int new[5][5];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			new[j][i] = a[i][j];		//Transposed The Matrix for converting col to row
	for (int i = 0; i < col; i++) {
		max_col = new[i][0];
		for (int j = 0; j < row; j++) {
			if (max_col < new[i][j])
				max_col = new[i][j];
		}	//Found Max Column
		for (int i = 0; i < row; i++) {
			min_row = a[i][0];
			for (int j = 0; j < col; j++) {
				if (min_row > a[i][j])
					min_row = a[i][j];
			}	//Found Max Row
			if (max_col == min_row) {
				printf("\nSaddle Point = %d", max_col);
				return;
			}
		}
	}
	printf("\nSaddle Point Doesn't Exist");
}

int main() {
	int a[5][5],b[5][5],op,row1=0,col1=0,row2=0,col2=0;
	do {
		printf("\n\n2D Array Operations");
		printf("\n1. Accept Matrix\n2. Display Matrix\n3. Addition Of Matrix");
		printf("\n4. Subtraction Of Matrix\n5. Multiplication Of Matrix\n6. Transpose Of Matrix");
		printf("\n7. Saddle Point\n8. Exit\n");
		printf("\nEnter Your Choice = ");
		scanf("%d", &op);
		switch (op) {
		case 1:
			printf("\nMatrix A = ");
			printf("\nEnter Number Of Rows = ");
			scanf("%d", &row1);
			printf("Enter Number Of Columns = ");
			scanf("%d", &col1);
			Accept(a, row1, col1);
			printf("\nMatrix B = ");
			printf("\nEnter Number Of Rows = ");
			scanf("%d", &row2);
			printf("Enter Number Of Columns = ");
			scanf("%d", &col2);
			Accept(b, row2, col2);
			break;
		case 2:
			printf("\nMatrix A = \n");
			Display(a, row1, col1);
			printf("\nMatrix B = \n");
			Display(b, row2, col2);
			break;
		case 3:
			Addition(a, row1, col1, b, row2, col2);
			break;
		case 4:
			Subtraction(a, row1, col1, b, row2, col2);
			break;
		case 5:
			Multiply(a, row1, col1, b, row2, col2);
			break;
		case 6:
			printf("\nFor Matrix A = ");
			Transpose(a, row1, col1);
			printf("\nFor Matrix B = ");
			Transpose(b, row2, col2);
			break;
		case 7:
			printf("\nFor Matrix A = ");
			Saddle_Point(a, row1, col1);
			printf("\nFor Matrix B = ");
			Saddle_Point(b, row2, col2);
			break;
		case 8:
			printf("\nYou Have Terminated The Program");
			break;
		default:
			printf("\nYou Have Entered The Wrong Choice\nPlease Try Again\n");
		}
	} while (op != 8);
	return 0;
}