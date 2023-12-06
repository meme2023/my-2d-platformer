#include"raylib.h"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION            100
#endif

#define  MAX_POSTPRO_SHADERS         12
class shader {
public:
    shader();
    Shader getcurrentshader();
   
    
private:
    enum {
        FX_GRAYSCALE = 0,
        FX_POSTERIZATION,
        FX_DREAM_VISION,
        FX_PIXELIZER,
        FX_CROSS_HATCHING,
        FX_CROSS_STITCHING,
        FX_PREDATOR_VIEW,
        FX_SCANLINES,
        FX_FISHEYE,
        FX_SOBEL,
        FX_BLOOM,
        FX_BLUR,
        //FX_FXAA
    } PostproShader;


    Shader shaders[MAX_POSTPRO_SHADERS] = { 0 };


};
