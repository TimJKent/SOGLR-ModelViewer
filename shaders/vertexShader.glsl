#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 FragPos;  

uniform mat4 uProjection;
uniform mat4 uModel;
uniform mat4 uView;

void main()
{
    gl_Position =  uProjection * uView * uModel * vec4(aPos.x,aPos.y,aPos.z, 1.0);
    FragPos = vec3(uModel * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(uModel))) * aNormal;
}