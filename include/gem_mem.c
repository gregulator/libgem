/*
 * gem_mem.c -- GL buffer management routines.
 *
 * Copyright Gregory Prisament 2014
 */
#include <gem_mem.h>

typedef struct
{
    GLuint gl_name;
} GemBufferStruct;

GemBuffer gemAlloc(size_t size)
{
    // TODO: error checking
    GemBufferStruct *obj;

    obj = malloc(sizeof(GemBufferStruct));

    glGenBuffers(1, &obj->gl_name);

    /* We have to bind the buffer to a GL target to create it.  For the time
     * being, it does not matter which GL target we use, so let's pick
     * GL_COPY_WRITE_BUFFER for the heck of it.
     */
    glBindBuffer(GL_COPY_WRITE_BUFFER, obj->gl_name);

    glBufferStorage(
        GL_COPY_WRITE_BUFFER, 
        size, 
        NULL, 
        GL_DYNAMIC_STORAGE_BIT | GL_MAP_READ_BIT | GL_MAP_WRITE_BIT
    );

    return obj;
}

GemBuffer gemCalloc(size_t size)
{
    GemBuffer buf;
    buf = gemAlloc(size);
    if (buf)
    {
        gemMemset(0x0, buf, 0, size);
    }
    return buf;
}


/*void gemMemset(char value, GemBuffer destBuffer, size_t destOffset, size_t size)
{
}*/

void gemCopyHostToDevice(void *source, GemBuffer destBuffer, size_t destOffset, size_t size)
{
    glBindBuffer(GL_COPY_WRITE_BUFFER, destBuffer->gl_name);
    glBufferSubData(GL_COPY_WRITE_BUFFER, destOffset, size, source);
}

void gemCopyDeviceToDevice(GemBuffer sourceBuffer, size_t sourceOffset, GemBuffer destBuffer, size_t destOffset, size_t size)
{
    glBindBuffer(GL_COPY_READ_BUFFER, sourceBuffer->gl_name);
    glBindBuffer(GL_COPY_WRITE_BUFFER, destBuffer->gl_name);
    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, sourceOffset, destOffset, size);
}

void gemCopyDeviceToHost(GemBuffer sourceBuffer, size_t sourceOffset, void * dest, size_t size)
{
    glBindBuffer(GL_COPY_READ_BUFFER, sourceBuffer->gl_name);
    glGetBufferSubData(GL_COPY_READ_BUFFER, sourceOffset, size, dest);
}

void gemFree(GemBuffer buffer)
{
    glDeleteBuffers(1, &buffer->gl_name);
}

size_t gemBufferSize(GemBuffer buffer)
{
    /* TODO: should return int for error handling purposes? */
    int64_t size = -1;
    glBindBuffer(GL_COPY_READ_BUFFER, buffer->gl_name);
    glGetBufferParameteri64v(GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &size)
    return (size_t)size;
}


