/*
 * GEM - Low-level 3D graphics library.
 *
 * Copyright Gregory Prisament 2014
 *
 */

GemVec3

typedef struct GemVertexDataStruct GemVertexData;

GemVertexData gemCreateVertexData(
        GemBuffer buffer, 
        GemVertexDataType type, 
        size_t offset, 
        size_t strideInBytes,
        size_t numVertices);

/* EXMAMPLE */

int main(void)
{
    GemContext gem = gemInit();
    float verts[] = {
        0, 0, 0,
        1, 1, 1,
        0, 1, 0
    };
    GemVec3 normals[] = {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 0}
    };
    GemRGBAf colors[] = {
        {0, 0, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 1}
    };

    GemBuffer gpuVerts, gpuNormals;
    gpuVerts = gemCopyHostToDevice(gem, verts, sizeof(verts));
    gpuNormals = gemCopyHostToDevice(gem, normals, sizeof(normals));
    gpuColors = gemCopyHostToDevice(gem, colors, sizeof(colors));

    GemVertexData vdPos, vdNorm, vdColor;
    vdPos = gemCreateVertexData(gpuVerts, GEM_VERTEX_3F, 0, 0, sizeof(verts));
    vdNorm = gemCreateVertexData(gpuNormals, GEM_VERTEX_VEC3, 0, 0, sizeof(normals));
    vdColor = gemCreateVertexData(gpuColors, GEM_VERTEX_RGBAF, 0, 0, sizeof(colors));

    /*
     * Specify:
     * - Shader uniforms.
     * - Vertex attributes
     * - Render mode (LOGIC OP, PRIMITIVE TYPE, etc)
     */
}

