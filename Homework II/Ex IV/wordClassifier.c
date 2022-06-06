#include <stdio.h>
#include <stdlib.h>
#include "QueuesADT.h"
#include "wordClassifier.h"

// Function Prototypes
// Prints the contents of a queue that contains strings
void printQueue(QUEUE* queue){
    void* dataPtr;
    while (!emptyQueue(queue)){
        dataPtr = (char*) malloc (25*sizeof (char));
        dequeue(queue, (void**)&dataPtr);
        printf("%s\n", (char**)dataPtr);
        free(dataPtr);
    } // while
 } // printQueue

// Classifies text file words by its inicial letter and print how many words are in each letter
void wordClassifier(FILE* fPtr){
// Local Definitions
    char token;
    char* dataPtr;
    QUEUE *QueueA, *QueueB, *QueueC, *QueueD, *QueueE, *QueueF, *QueueG, *QueueH, 
          *QueueI, *QueueJ, *QueueK, *QueueL, *QueueM, *QueueN, *QueueO, *QueueP, 
          *QueueQ, *QueueR, *QueueS, *QueueT, *QueueU, *QueueV, *QueueW, *QueueX, 
          *QueueY, *QueueZ;

// Statements
    QueueA = createQueue();
    QueueB = createQueue();
    QueueC = createQueue();
    QueueD = createQueue();
    QueueE = createQueue();
    QueueF = createQueue();
    QueueG = createQueue();
    QueueH = createQueue();
    QueueI = createQueue();
    QueueJ = createQueue();
    QueueK = createQueue();
    QueueL = createQueue();
    QueueM = createQueue();
    QueueN = createQueue();
    QueueO = createQueue();
    QueueP = createQueue();
    QueueQ = createQueue();
    QueueR = createQueue();
    QueueS = createQueue();
    QueueT = createQueue();
    QueueU = createQueue();
    QueueV = createQueue();
    QueueW = createQueue();
    QueueX = createQueue();
    QueueY = createQueue();
    QueueZ = createQueue();

 
    dataPtr = (char*) malloc (25*sizeof (char));
    while (fscanf(fPtr, "%s", dataPtr) == 1){
        token = dataPtr[0];
                if (token == 'A' || token == 'a'){
                    enqueue(QueueA, dataPtr);
                } // if
                else if (token == 'B' || token == 'b'){
                    enqueue(QueueB, dataPtr);
                } // else if
                else if (token == 'C' || token == 'c'){
                    enqueue(QueueC, dataPtr);
                } // else if
                else if (token == 'D' || token == 'd'){
                    enqueue(QueueD, dataPtr);
                } // else if
                else if (token == 'E' || token == 'e'){
                    enqueue(QueueE, dataPtr);
                } // else if
                else if (token == 'F' || token == 'f'){
                    enqueue(QueueF, dataPtr);
                } // else if
                else if (token == 'G' || token == 'g'){
                    enqueue(QueueG, dataPtr);
                } // else if
                else if (token == 'H' || token == 'h'){
                    enqueue(QueueH, dataPtr);
                } // else if
                else if (token == 'I' || token == 'i'){
                    enqueue(QueueI, dataPtr);
                } // else if
                else if (token == 'J' || token == 'j'){
                    enqueue(QueueJ, dataPtr);
                } // else if
                else if (token == 'K' || token == 'k'){
                    enqueue(QueueK, dataPtr);
                } // else if
                else if (token == 'L' || token == 'l'){
                    enqueue(QueueL, dataPtr);
                } // else if
                else if (token == 'M' || token == 'm'){
                    enqueue(QueueM, dataPtr);
                } // else if
                else if (token == 'N' || token == 'n'){
                    enqueue(QueueN, dataPtr);
                } // else if
                else if (token == 'O' || token == 'o'){
                    enqueue(QueueO, dataPtr);
                } // else if
                else if (token == 'P' || token == 'p'){
                    enqueue(QueueP, dataPtr);
                } // else if
                else if (token == 'Q' || token == 'q'){
                    enqueue(QueueQ, dataPtr);
                } // else if
                else if (token == 'R' || token == 'r'){
                    enqueue(QueueR, dataPtr);
                } // else if
                else if (token == 'S' || token == 's'){
                    enqueue(QueueS, dataPtr);
                } // else if
                else if (token == 'T' || token == 't'){
                    enqueue(QueueT, dataPtr);
                } // else if
                else if (token == 'U' || token == 'u'){
                    enqueue(QueueU, dataPtr);
                } // else if
                else if (token == 'V' || token == 'v'){
                    enqueue(QueueV, dataPtr);
                } // else if
                else if (token == 'W' || token == 'w'){
                    enqueue(QueueW, dataPtr);
                } // else if
                else if (token == 'X' || token == 'x'){
                    enqueue(QueueX, dataPtr);
                } // else if
                else if (token == 'Y' || token == 'y'){
                    enqueue(QueueY, dataPtr);
                } // else if
                else if (token == 'Z' || token == 'z'){
                    enqueue(QueueZ, dataPtr);
                } // else if
        dataPtr = (char*) malloc (25*sizeof (char));
    } // while

    // Print not empty queues
    if (!emptyQueue(QueueA)){
        printf("The text file has %d words starting with the letter A.\n", queueCount(QueueA));
        printQueue(QueueA);
    } // if
    if (!emptyQueue(QueueB)){
        printf("The text file has %d words starting with the letter B.\n", queueCount(QueueB));
        printQueue(QueueB);
    } // if
    if (!emptyQueue(QueueC)){
        printf("The text file has %d words starting with the letter C.\n", queueCount(QueueC));
        printQueue(QueueC);
    } // if
    if (!emptyQueue(QueueD)){
        printf("The text file has %d words starting with the letter D.\n", queueCount(QueueD));
        printQueue(QueueD);
    } // if
    if (!emptyQueue(QueueE)){
        printf("The text file has %d words starting with the letter E.\n", queueCount(QueueE));
        printQueue(QueueE);
    } // if
    if (!emptyQueue(QueueF)){
        printf("The text file has %d words starting with the letter F.\n", queueCount(QueueF));
        printQueue(QueueF);
    } // if
    if (!emptyQueue(QueueG)){
        printf("The text file has %d words starting with the letter G.\n", queueCount(QueueG));
        printQueue(QueueG);
    } // if
    if (!emptyQueue(QueueH)){
        printf("The text file has %d words starting with the letter H.\n", queueCount(QueueH));
        printQueue(QueueH);
    } // if
    if (!emptyQueue(QueueI)){
        printf("The text file has %d words starting with the letter I.\n", queueCount(QueueI));
        printQueue(QueueI);
    } // if
    if (!emptyQueue(QueueJ)){
        printf("The text file has %d words starting with the letter J.\n", queueCount(QueueJ));
        printQueue(QueueJ);
    } // if
    if (!emptyQueue(QueueK)){
        printf("The text file has %d words starting with the letter K.\n", queueCount(QueueK));
        printQueue(QueueK);
    } // if
    if (!emptyQueue(QueueL)){
        printf("The text file has %d words starting with the letter L.\n", queueCount(QueueL));
        printQueue(QueueL);
    } // if
    if (!emptyQueue(QueueM)){
        printf("The text file has %d words starting with the letter M.\n", queueCount(QueueM));
        printQueue(QueueM);
    } // if
    if (!emptyQueue(QueueN)){
        printf("The text file has %d words starting with the letter N.\n", queueCount(QueueN));
        printQueue(QueueN);
    } // if
    if (!emptyQueue(QueueO)){
        printf("The text file has %d words starting with the letter O.\n", queueCount(QueueO));
        printQueue(QueueO);
    } // if
    if (!emptyQueue(QueueP)){
        printf("The text file has %d words starting with the letter P.\n", queueCount(QueueP));
        printQueue(QueueP);
    } // if
    if (!emptyQueue(QueueQ)){
        printf("The text file has %d words starting with the letter Q.\n", queueCount(QueueQ));
        printQueue(QueueQ);
    } // if
    if (!emptyQueue(QueueR)){
        printf("The text file has %d words starting with the letter R.\n", queueCount(QueueR));
        printQueue(QueueR);
    } // if
    if (!emptyQueue(QueueS)){
        printf("The text file has %d words starting with the letter S.\n", queueCount(QueueS));
        printQueue(QueueS);
    } // if
    if (!emptyQueue(QueueT)){
        printf("The text file has %d words starting with the letter T.\n", queueCount(QueueT));
        printQueue(QueueT);
    } // if
    if (!emptyQueue(QueueU)){
        printf("The text file has %d words starting with the letter U.\n", queueCount(QueueU));
        printQueue(QueueU);
    } // if
    if (!emptyQueue(QueueV)){
        printf("The text file has %d words starting with the letter V.\n", queueCount(QueueV));
        printQueue(QueueV);
    } // if
    if (!emptyQueue(QueueW)){
        printf("The text file has %d words starting with the letter W.\n", queueCount(QueueW));
        printQueue(QueueW);
    } // if
    if (!emptyQueue(QueueX)){
        printf("The text file has %d words starting with the letter X.\n", queueCount(QueueX));
        printQueue(QueueX);
    } // if
    if (!emptyQueue(QueueY)){
        printf("The text file has %d words starting with the letter Y.\n", queueCount(QueueY));
        printQueue(QueueY);
    } // if
    if (!emptyQueue(QueueZ)){
        printf("The text file has %d words starting with the letter Z.\n", queueCount(QueueZ));
        printQueue(QueueZ);
    } // if

    // Free memory
    free(dataPtr);

    // Destroy all queues
    destroyQueue(QueueA);
    destroyQueue(QueueB);
    destroyQueue(QueueC);
    destroyQueue(QueueD);
    destroyQueue(QueueE);
    destroyQueue(QueueF);
    destroyQueue(QueueG);
    destroyQueue(QueueH);
    destroyQueue(QueueI);
    destroyQueue(QueueJ);
    destroyQueue(QueueK);
    destroyQueue(QueueL);
    destroyQueue(QueueM);
    destroyQueue(QueueN);
    destroyQueue(QueueO);
    destroyQueue(QueueP);
    destroyQueue(QueueQ);
    destroyQueue(QueueR);
    destroyQueue(QueueS);
    destroyQueue(QueueT);
    destroyQueue(QueueU);
    destroyQueue(QueueV);
    destroyQueue(QueueW);
    destroyQueue(QueueX);
    destroyQueue(QueueY);
    destroyQueue(QueueZ);  
 } // wordClassifier

 