/*
 * GEM - Low-level 3D graphics library.
 *
 * Copyright Gregory Prisament 2014
 *
 * The OpenGL API routines are based on implicit state.
 * GEM, on the other hand, strives to be explicit.
 */


typedef void * GemRenderTarget;

/*
 *  TEXTURE TYPES:
 *      1D
 *      2D
 *      3D
 *      1D ARRAY
 *      2D ARRAY
 *      2D Multisample
 *      2D Multisample ARRAY
 *      CUBE MAP
 *      Rectangular texture
 *      Buffer Textures
 *
 *  BindTexture and ActiveTexture handled automatically for you.
 *
 *  TEXTUER_SAMPLING
 *      TEXTURE_BORDER_COLOR
 *      TEXTURE_COMPARE_FUNC
 *      TEXTURE_COMPARE_MODE
 *      TEXTURE_LOD_BIAS
 *      TEXTURE_MAX_LOD
 *      TEXTURE_MIN_LOD
 *      TEXTURE_MAG_FILTER
 *      TEXTURE_MIN_FILTER
 *      TEXTURE_WRAP_S
 *      TEXTURE_WRAP_T
 *      TEXTURE_WRAP_R
 *
 *  PIXEL STORE:
 *      UNPACK_SWAP_BYTES
 *      UNPACK_LSB_FIRST
 *      UNPACK_ROW_LENGTH
 *      UNPACK_SKIP_ROWS
 *      UNPACK_SKIP_PIXELS
 *      UNPACK_ALIGNMENT
 *      UNPACK_IMAGE_HEIGHT
 *      UNPACK_SKIP_IMAGES
 *      UNPACK_COMPRESSED_BLOCK_WIDTH
 *      UNPACK_COMPRESSED_BLOCK_HEIGHT
 *      UNPACK_COMPRESSED_BLOCK_DEPTH
 *      UNPACK_COMPRESSED_BLOCK_SIZE
 *
 *      PIXEL_UNPACK_BUFFER for sourcing pixel data from buffer objects.
 *
 *  MIPMAPPING
 *
 *  CopyTexImage - Specify texture using region of frame buffer.
 *  TexSubImage,CopyTexSubImage - do not change size or internal format of texture.
 *
 *  COMPRESSED TEXTURES
 *
 */

typedef void * GemTexture1D;
typedef void * GemTexture2D;
typedef void * GemTexture3D;
typedef void * GemTextureCube;
typedef void * GemTexture1DArray;
typedef void * GemTexture2DArray;
typedef void * GemTexture2DMultisample;
typedef void * GemTexture2DMultisampleArray;
typedef void * GemTextureRect;
typedef void * GemTexture1DBuffer;

GemTexture1D Gem_CreateTexture1D(GemContext ctx, GemTextureFormat fmt, uint32_t width);

int pixelStoreOptions[] = {
    GEM_UNPACK_SWAP_BYTES, true,
    NULL
}
void GemTexture1D_WriteMainData(GemTexture1D tex, void *data, int32_t *options);
void GemTexture1D_WriteDataPbo(GemTexture1D tex, void *data, int32_t *options);
void GemTexture1D_WriteMipmapData(GemTexture1D tex, int mipmapLevel, void *data, int32_t *options);
void GemTexture1D_GenerateMipmaps(GemTexture1D tex);
/*
 * Questions:
 *
 * 1) Should we define structures in this header file.  For example, for options.
 *  - Recommendation: Although it would simplify the API somewhat, there is a
 *    concern about coupling the header file with the binaries.
 *
 * 2) Do we need all the pixel pack/unpack crap, or can we require the user to
 * do that stuff ahead of time?  Does the driver perform that on the CPU?
 */
