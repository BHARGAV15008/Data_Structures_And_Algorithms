#include <stdio.h>

int **addMatrix(int mat1[][], int mat2[][], int size) {
    int matrix[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = mat1[i][j] + mat1[i][j];
    return matrix;
}

int **createSubMatrix (int matrix[][], int i, int j, int size) {
    int subMatrix[size/2][size/2];
    int x = 0, y = 0;
    if (i == 0 && j == 0){
        for (int index = i; index < size/2; index++){
            for (int index1 = j; index1 < size/2; index1++)
                subMatrix[x++][y++] = matrix[index][index1];
        }
    }
    else if (i == 0 && j == size/2+1) {
        for (int index = i; index < size/2; index++){
            for (int index1 = j; index1 < size; index1++)
                subMatrix[x++][y++] = matrix[index][index1];
        }
    }
    else if (i == size/2+1 && j == size/2+1) {
        for (int index = i; index < size; index++){
            for (int index1 = j; index1 < size; index1++)
                subMatrix[x++][y++] = matrix[index][index1];
        }
    }
    else {
        for (int index = i; index < size; index++){
            for (int index1 = j; index1 < size; index1++)
                subMatrix[x++][y++] = matrix[index][index1];
        }
    }
    return subMatrix;
}

void DACMatrixMultiplication(int mat1[][], int mat2[][], int n) {
    int res[2][2];
    if (n <= 2){
        res[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0]; 
        res[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1]; 
        res[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0]; 
        res[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1]; 
    } else {
        int mat1_11[][] = createSubMatrix (mat1, 0, 0, n);
        int mat1_12[][] = createSubMatrix (mat1, 0, n\2+1, n);
        int mat1_21[][] = createSubMatrix (mat1, n/2+1, 0, n);
        int mat1_22[][] = createSubMatrix (mat1, n/2+1, n\2+1, n);
        int mat2_11[][] = createSubMatrix (mat2, 0, 0, n);
        int mat2_12[][] = createSubMatrix (mat2, 0, n\2+1, n);
        int mat2_21[][] = createSubMatrix (mat2, n/2+1, 0, n);
        int mat2_22[][] = createSubMatrix (mat2, n/2+1, n\2+1, n);
        int **c11 = (DACMatrixMultiplication(mat1_11, mat2_11, n/2), DACMatrixMultiplication(mat1_12, mat2_21, n/2));
        int **c12 = (DACMatrixMultiplication(mat1_11, mat2_12, n/2), DACMatrixMultiplication(mat1_22, mat2_22, n/2));
        int **c21 = (DACMatrixMultiplication(mat1_21, mat2_21, n/2), DACMatrixMultiplication(mat1_22, mat2_21, n/2));
        int **c22 = (DACMatrixMultiplication(mat1_21, mat2_22, n/2), DACMatrixMultiplication(mat1_22, mat2_22, n/2));
    }
}

int main (){
    
    
    return 0;
}