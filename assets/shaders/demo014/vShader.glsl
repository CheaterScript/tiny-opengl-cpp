#version 330 core
layout (location = 0) in vec3 position;
layout (location = 2) in vec2 textureCoord;

out vec2 TextureCoord;

uniform mat4 transform;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
void main()
{
    gl_Position = projectionMatrix * viewMatrix * transform * vec4(position, 1.0f);
    TextureCoord = textureCoord;
}