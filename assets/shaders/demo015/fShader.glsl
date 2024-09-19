#version 330 core

out vec4 FragColor;

in vec2 TextureCoord;
in vec3 v_normal;
in vec3 v_fragPosition;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
    vec3 lightPosition = vec3(10.0, 10.0, 0.0);
    vec3 lightColor = vec3(0.11, 0.91, 0.41);
    float ambientStrength = 0.3;

    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(v_normal);
    vec3 lightDir = normalize(lightPosition - v_fragPosition);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    FragColor = vec4((ambient+diffuse)*vec3(1.0f,1.0f,1.0f), 1.0);
}