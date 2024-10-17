#version 330 core

out vec4 frag_color;

in vec2 TextureCoord;
in vec3 v_normal;
in vec3 v_fragPosition;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec3 u_lightPosition;
uniform vec3 u_lightColor;
uniform float u_ambientStrength;

void main() {
    // vec3 u_lightPosition = vec3(10.0, 10.0, 0.0);
    // vec3 u_lightColor = vec3(0.11, 0.91, 0.41);

    vec3 ambient = u_ambientStrength * u_lightColor;

    vec3 norm = normalize(v_normal);
    vec3 lightDir = normalize(u_lightPosition - v_fragPosition);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * u_lightColor;

    frag_color = vec4((ambient+diffuse)*vec3(1.0f,1.0f,1.0f), 1.0);
}