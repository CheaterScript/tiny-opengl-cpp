#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 textureCoord;

out vec2 TextureCoord;
out vec3 v_normal;
out vec3 v_fragPosition;

uniform mat4 transform;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
void main() {
    gl_Position = projectionMatrix * viewMatrix * transform * vec4(position, 1.0);
    v_fragPosition = vec3(transform * vec4(position, 1.0));
    TextureCoord = textureCoord;
    v_normal = mat3(transpose(inverse(transform))) * a_normal;
}