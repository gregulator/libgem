/*
 * GEM - Low-level 3D graphics library.
 *
 * Copyright Gregory Prisament 2014
 *
 * The OpenGL API routines are based on implicit state.
 * GEM, on the other hand, strives to be explicit.
 */

typedef void * GemBuffer;

/*
 * Allocate device memory
 */
GemBuffer gemMalloc(size_t size);
GemBuffer gemCalloc(size_t size);
//void gemMemset(char value, GemBuffer destBuffer, size_t destOffset, size_t size);
void gemCopyHostToDevice(void *source, GemBuffer destBuffer, size_t destOffset, size_t size);
void gemCopyDeviceToDevice(GemBuffer sourceBuffer, size_t sourceOffset, GemBuffer destBuffer, size_t destOffset, size_t size);
void gemCopyDeviceToHost(GemBuffer sourceBuffer, size_t sourceOffset, void * dest, size_t size);
void gemFree(GemBuffer buffer);
size_t gemBufferSize(GemBuffer buffer);
