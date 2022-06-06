#include <stdio.h>
#include <stdlib.h>
#include "QueuesADT.h"
#include "wordClassifier.h"

// Function Prototypes
void wordClassifier(FILE* fPtr){
    // Local Definitions
    char token;
    char* dataPtr;
    QUEUE *QueueA, *QueueB, *QueueC, *QueueD, *QueueE, *QueueF, *QueueG, *QueueH, 
          *QueueI, *QueueJ, *QueueK, *QueueL, *QueueM, *QueueN, *QueueO, *QueueP, 
          *QueueQ, *QueueR, *QueueS, *QueueT, *QueueU, *QueueV, *QueueW, *QueueX, 
          *QueueY, *QueueZ;
    // Statements
    while ((token = fgetc (fPtr)) != EOF){
        dataPtr = (char*) malloc (25 * sizeof (char));
        //fscanf(fPtr, "%s", dataPtr);
        *dataPtr = token;
        printf("i entered here\n");
        //if (token < 'A' || token > 'z'){
                if (token == 'A' || token == 'a'){
                     printf("i entered here2\n");
                    if (emptyQueue(QueueA)){QueueA = createQueue();}
                    enqueue(QueueA, dataPtr);
                } // if
                else if (token == 'B' || token == 'b'){
                    if (emptyQueue(QueueB)){QueueB = createQueue();}
                    enqueue(QueueB, dataPtr);
                } // else if
                else if (token == 'C' || token == 'c'){
                    if (emptyQueue(QueueC)){QueueC = createQueue();}
                    enqueue(QueueC, dataPtr);
                } // else if
                else if (token == 'D' || token == 'd'){
                    if (emptyQueue(QueueD)){QueueD = createQueue();}
                    enqueue(QueueD, dataPtr);
                } // else if
                else if (token == 'E' || token == 'e'){
                    if (emptyQueue(QueueE)){QueueE = createQueue();}
                    enqueue(QueueE, dataPtr);
                } // else if
                else if (token == 'F' || token == 'f'){
                    if (emptyQueue(QueueF)){QueueF = createQueue();}
                    enqueue(QueueF, dataPtr);
                } // else if
                else if (token == 'G' || token == 'g'){
                    if (emptyQueue(QueueG)){QueueG = createQueue();}
                    enqueue(QueueG, dataPtr);
                } // else if
                else if (token == 'H' || token == 'h'){
                    if (emptyQueue(QueueH)){QueueH = createQueue();}
                    enqueue(QueueH, dataPtr);
                } // else if
                else if (token == 'I' || token == 'i'){
                    if (emptyQueue(QueueI)){QueueI = createQueue();}
                    enqueue(QueueI, dataPtr);
                } // else if
                else if (token == 'J' || token == 'j'){
                    if (emptyQueue(QueueJ)){QueueJ = createQueue();}
                    enqueue(QueueJ, dataPtr);
                } // else if
                else if (token == 'K' || token == 'k'){
                    if (emptyQueue(QueueK)){QueueK = createQueue();}
                    enqueue(QueueK, dataPtr);
                } // else if

        //} // if
    } // while
    // Print QueueA
    if (!emptyQueue(QueueA)){
        printf("The text file has %d words starting with the letter A.\n", queueCount(QueueA));
    } // if
    if (QueueB != NULL){
        printf("The text file has %d words starting with the letter B.\n", queueCount(QueueB));
    } // if
    if (QueueC != NULL){
        printf("The text file has %d words starting with the letter C.\n", queueCount(QueueC));
    } // if
    if (QueueD != NULL){
        printf("The text file has %d words starting with the letter D.\n", queueCount(QueueD));
    } // if
    if (QueueE != NULL){
        printf("The text file has %d words starting with the letter E.\n", queueCount(QueueE));
    } // if
    if (QueueF != NULL){
        printf("The text file has %d words starting with the letter F.\n", queueCount(QueueF));
    } // if
    if (QueueG != NULL){
        printf("The text file has %d words starting with the letter G.\n", queueCount(QueueG));
    } // if
    if (QueueH != NULL){
        printf("The text file has %d words starting with the letter H.\n", queueCount(QueueH));
    } // if
    if (QueueI != NULL){
        printf("The text file has %d words starting with the letter I.\n", queueCount(QueueI));
    } // if
    if (QueueJ != NULL){
        printf("The text file has %d words starting with the letter J.\n", queueCount(QueueJ));
    } // if
    if (QueueK != NULL){
        printf("The text file has %d words starting with the letter K.\n", queueCount(QueueK));
    } // if
    if (QueueL != NULL){
        printf("The text file has %d words starting with the letter L.\n", queueCount(QueueL));
    } // if
    if (QueueM != NULL){
        printf("The text file has %d words starting with the letter M.\n", queueCount(QueueM));
    } // if
    if (QueueN != NULL){
        printf("The text file has %d words starting with the letter N.\n", queueCount(QueueN));
    } // if
    if (QueueO != NULL){
        printf("The text file has %d words starting with the letter O.\n", queueCount(QueueO));
    } // if
    if (QueueP != NULL){
        printf("The text file has %d words starting with the letter P.\n", queueCount(QueueP));
    } // if
    if (QueueQ != NULL){
        printf("The text file has %d words starting with the letter Q.\n", queueCount(QueueQ));
    } // if
    if (QueueR != NULL){
        printf("The text file has %d words starting with the letter R.\n", queueCount(QueueR));
    } // if
    if (QueueS != NULL){
        printf("The text file has %d words starting with the letter S.\n", queueCount(QueueS));
    } // if
    if (QueueT != NULL){
        printf("The text file has %d words starting with the letter T.\n", queueCount(QueueT));
    } // if
    if (QueueU != NULL){
        printf("The text file has %d words starting with the letter U.\n", queueCount(QueueU));
    } // if
    if (QueueV != NULL){
        printf("The text file has %d words starting with the letter V.\n", queueCount(QueueV));
    } // if
    if (QueueW != NULL){
        printf("The text file has %d words starting with the letter W.\n", queueCount(QueueW));
    } // if
    if (QueueX != NULL){
        printf("The text file has %d words starting with the letter X.\n", queueCount(QueueX));
    } // if
    if (QueueY != NULL){
        printf("The text file has %d words starting with the letter Y.\n", queueCount(QueueY));
    } // if
    if (QueueZ != NULL){
        printf("The text file has %d words starting with the letter Z.\n", queueCount(QueueZ));
    } // if
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