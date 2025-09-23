#version 330 core
in vec3 Normal;  
in vec3 FragPos;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 lightPos2;

void main()
{
   float ambientStrength = 0.1;
   vec3 ambient = ambientStrength * lightColor;

   vec3 norm = normalize(Normal);
   vec3 lightDir = normalize(lightPos - FragPos);
   vec3 lightDir2 = normalize(lightPos2 - FragPos);

   float diff = max(dot(Normal, lightDir), 0.0);
   vec3 diffuse = diff * lightColor;

   float diff2 = max(dot(Normal, lightDir2), 0.0);
   vec3 diffuse2 = diff2 * lightColor;

   vec3 calculation = (ambient + diffuse + diffuse2) * objectColor;
    gl_FragColor = vec4(calculation, 1.0);
}  