#include <stddef.h>
#include <hfsPlus_structures.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

typedef struct File {
    long size;
    void *data;
} File;

typedef struct BTree {
    File *file;
    BTHeaderRec *header;
} BTree;

typedef struct FileSystem {
    int deviceDescriptor;
    HFSPlusVolumeHeader *volumeHeader;
    BTree *catalog;
    HFSCatalogNodeID pwd;
} FileSystem;

typedef struct Node {
    BTNodeDescriptor *descriptor;
    UInt16 *record_offsets;
} Node;

typedef struct Record {
    void *data;
    UInt16 size;
    UInt16 data_offset;
    UInt16 key_length;
} Record;

typedef struct IterationData {
    Record *record;
    SInt16 type;
    HFSCatalogNodeID parentID;
    HFSCatalogNodeID targetID;
    char nodeName[256];
    char targetName[256];
    char breakFlag;
} IterationData;

typedef struct NodeInfo {
    HFSCatalogNodeID id;
    SInt16 type;
    char nodeName[256];
    HFSPlusForkData data;
} NodeInfo;

typedef struct NodeInfoArray {
    int size;
    NodeInfo *data;
} NodeInfoArray;

BTree *openBTree(FileSystem *fileSystem, enum BTreeType type);

File *openFileFromFork(FileSystem *fileSystem, HFSPlusForkData *forkData);

void closeBTree(BTree *catalog);

void closeFile(File *file);

NodeInfo *findFileByPath(FileSystem *fileSystem, HFSCatalogNodeID parentID, char *path);

NodeInfo *findFileByName(FileSystem *fileSystem, HFSCatalogNodeID parentID, char *path);

void lsCallback(IterationData *input, void *outputPointer);

void nameByIdCallback(IterationData *input, void *output);

void parentByIdCallback(IterationData *input, void *output);

void idByNameCallback(IterationData *input, void *output);

Node *openNode(int node_num, BTree *tree);

Record *openRecord(int record_num, Node *node);

void closeRecord(Record *record);

void closeNode(Node *node);

void convertNameToString(char *output, UInt16 *rawName, int nameLength);

void catalogIteration(FileSystem *fileSystem, UInt32 nodeNumber, IterationData *data, void *output, int callback);

int copy(FileSystem *fileSystem, NodeInfo *info, char *path);

int openFileSystem(char *name);
int closeFileSystem();
char *ls();
char *cd(char *path);
char *pwd();
char *cp(char *path, char *outPath);