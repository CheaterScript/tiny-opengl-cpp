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
uniform float u_specularStrength;
uniform vec3 u_cameraPosition;
void main() {
    // vec3 u_lightPosition = vec3(10.0, 10.0, 0.0);
    // vec3 u_lightColor = vec3(0.11, 0.91, 0.41);

    vec3 ambient = u_ambientStrength * u_lightColor;

    vec3 norm = normalize(v_normal);
    vec3 lightDir = normalize(u_lightPosition - v_fragPosition);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * u_lightColor;

    vec3 viewDir = normalize(u_cameraPosition - v_fragPosition);
    vec3 reflectDir = reflect(-lightDir, norm);

    float specRatio = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = u_specularStrength * specRatio * u_lightColor;

    frag_color = vec4((ambient + diffuse + specular) * vec3(1.0, 1.0, 1.0), 1.0);
}