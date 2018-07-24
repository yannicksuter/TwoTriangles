#version 330 core

precision highp float;

in vec2 PositionNDC;
out vec2 TexCoord;

void main() {
	gl_Position = vec4(PositionNDC, 0.0, 1.0);
	TexCoord = PositionNDC * 0.5 + 0.5;
}