#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 textureCoord;

out vec2 TextureCoord;
out vec3 v_normal;
out vec3 v_fragPosition;

uniform mat4 u_transform;
uniform mat4 u_viewMatrix;
uniform mat4 u_projectionMatrix;
uniform mat4 u_normalMatrix;
void main() {
    gl_Position = u_projectionMatrix * u_viewMatrix * u_transform * vec4(position, 1.0);
    v_fragPosition = vec3(u_transform * vec4(position, 1.0));
    TextureCoord = textureCoord;
    v_normal = mat3(u_normalMatrix) * a_normal;
}  