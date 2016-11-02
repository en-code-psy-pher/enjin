#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in VS_OUT {
    vec2 texCoords;
    vec3 fragPos;
} gs_in[];

out GS_OUT {
    vec2 texCoords;
    vec3 fragPos;
    vec3 normal;    
} gs_out;

uniform float _time;
uniform float _explodeBias;

vec4 Explode(vec4 position, vec3 normal);
vec3 GetNormal();

vec4 Explode(vec4 position, vec3 normal)
{
    float magnitude = 2.0f * _explodeBias;
    vec3 direction = normal * ((sin(_time) + 1.0f) / 2.0f) * magnitude; 
    return position + vec4(direction, 0.0f);
}

vec3 GetNormal()
{
    vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
    return normalize(cross(a, b));
}

void main() {    
    gs_out.normal = GetNormal();
    
    gl_Position = Explode(gl_in[0].gl_Position, gs_out.normal);
    gs_out.fragPos = gs_in[0].fragPos;
    gs_out.texCoords = gs_in[0].texCoords;
    EmitVertex();

    gl_Position = Explode(gl_in[1].gl_Position, gs_out.normal);
    gs_out.fragPos = gs_in[1].fragPos;
    gs_out.texCoords = gs_in[1].texCoords;    
    EmitVertex();

    gl_Position = Explode(gl_in[2].gl_Position, gs_out.normal);
    gs_out.fragPos = gs_in[2].fragPos;
    gs_out.texCoords = gs_in[2].texCoords;
    EmitVertex();

    EndPrimitive();
}