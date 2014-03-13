/*
 * GEM - Low-level 3D graphics library.
 *
 * Copyright Gregory Prisament 2014
 *
 */

typedef struct {
    union {
        struct {
            float x;
            float y;
        };
        float v[2];
    }
} GemVec2f;
