#pragma once

struct collatzNodePar;
int calculateNextCollatzNumber(int inputPar);
std::pair<int, int> calculateLongestSequence(int inputPar);
int calculateCollatzSequenceLength(int inputPar);
void createCollatzSequence(collatzNodePar** head_ref);
void traversePrintCollatzSequence(collatzNodePar** head_ref);
void destroyLinkedList(collatzNodePar** head_ref);

