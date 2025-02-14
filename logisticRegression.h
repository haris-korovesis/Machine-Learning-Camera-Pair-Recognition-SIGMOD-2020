#ifndef LOGISTICREGRESSION
#define LOGISTICREGRESSION


#include <stdio.h>
#include "metrics.h"
#include "hashTable.h"
#include "sparce.h"

typedef struct bucket Bucket;

typedef struct logistic_reg
{
    double bias;

    double *weights;

    sparceMatrix **x;

    int *y;

    double learning; 

    int lineSize;

    int arraySize;

    int error;
    

}logistic_reg;

double** shuffleArray(double** array, int *array2, int size, char **, char **);
logistic_reg * create_logistic_reg(int lineSize);
void fit(logistic_reg * cur,sparceMatrix **x,int* y, int lineSize,int array_size);
logistic_reg* logisticRegretionAlgorithm(logistic_reg *cls, int limit, Bucket **ht, int HTsize, word_ht *wordHash,sparceMatrix **x, int *y,int x_size,int batchSize, Bucket **trHash, int trSize,int thread_num);
double cost_function(logistic_reg *cls);
// double logisticRegrationTest(logistic_reg *cls, double *data, char *left, char *right, int y, FILE *fp);
double logisticRegrationTest(logistic_reg *cls, sparceMatrix *data, char *left, char *right, int y, FILE *fp,positiveMetrics *P_metrics, negativeMetrics *N_metrics);    
trainData *predictHashTable(logistic_reg *cls, Bucket ** ht, int HTsize, double threshold, word_ht *wordHash, Bucket **trHash, int trSize, int lim, trainData *trainSet,int *size_x);
// void resolveTransitivity(treeNode *root, Bucket **hashTable, int trSize, sparceMatrix **X, int *Y, SparceList *spList);
void printClassifier(logistic_reg *cls);
void freeLogisticRegressor(logistic_reg *cls);
void logisticValidationTest(logistic_reg *cls, sparceMatrix **data, int * y,int size);


#endif
