#include <stdio.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"

int
main(int argc, const char *argv[])
{
    Chunk chunk;
    initChunk(&chunk);

    int constant_index = addConstant(&chunk, 1.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant_index, 123);

    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "code");

    freeChunk(&chunk);

    return 0;
}