#version 130

uniform vec3 lightPos;

uniform vec3 ambientColor, diffuseColor, objectColor;

in vec3 fragNormal;

in vec3 fragPos;

out vec4 fragColor;

void main(void)
{
   // Направление источника
   vec3 lightDir = normalize(lightPos - fragPos);

   // Сила света по модели Ламберта
   float power = max(dot(fragNormal, lightDir), 0.0);

   vec3 diffuse = power * diffuseColor;

   vec3 result = (ambientColor + diffuse) * objectColor;

   fragColor = vec4(result, 1.0f);
}
