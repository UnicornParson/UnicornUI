#version 440

layout(location = 0) in vec2 texCoord;
layout(location = 0) out vec4 fragColor;

void main(void)
{
    //gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
    fragColor = vec4(texCoord, 1.0, 1.0);
}
