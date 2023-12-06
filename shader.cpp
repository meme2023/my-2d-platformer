#include "shader.h"



shader::shader()
{

}

Shader shader::getcurrentshader()
{
    static const char* postproShaderText[] = {
 "GRAYSCALE",
 "POSTERIZATION",
 "DREAM_VISION",
 "PIXELIZER",
 "CROSS_HATCHING",
 "CROSS_STITCHING",
 "PREDATOR_VIEW",
 "SCANLINES",
 "FISHEYE",
 "SOBEL",
 "BLOOM",
 "BLUR",
 //"FXAA"
    };
    shaders[FX_GRAYSCALE] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\grayscale.fs", GLSL_VERSION));
    shaders[FX_POSTERIZATION] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\posterization.fs", GLSL_VERSION));
    shaders[FX_DREAM_VISION] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\dream_vision.fs", GLSL_VERSION));
    shaders[FX_PIXELIZER] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\pixelizer.fs", GLSL_VERSION));
    shaders[FX_CROSS_HATCHING] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\cross_hatching.fs", GLSL_VERSION));
    shaders[FX_CROSS_STITCHING] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\cross_stitching.fs", GLSL_VERSION));
    shaders[FX_PREDATOR_VIEW] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\predator.fs", GLSL_VERSION));
    shaders[FX_SCANLINES] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\scanlines.fs", GLSL_VERSION));
    shaders[FX_FISHEYE] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\fisheye.fs", GLSL_VERSION));
    shaders[FX_SOBEL] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\sobel.fs", GLSL_VERSION));
    shaders[FX_BLOOM] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\bloom.fs", GLSL_VERSION));
    shaders[FX_BLUR] = LoadShader(0, TextFormat("C:\\Users\\memeo\\Desktop\\c++\\shaders\\glsl%i\\blur.fs", GLSL_VERSION));
    return shaders[10];
}







