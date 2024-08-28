#version 330 core

out vec4 FragColor;

in vec2 TextureCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
    FragColor = mix(texture(texture1, TextureCoord), texture(texture2, vec2(1.0 - TextureCoord.x, TextureCoord.y)), 0.2);
}