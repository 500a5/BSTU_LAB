uniform sampler2D u_texture;
uniform vec4 u_objColor;
uniform bool u_use_texture;
varying vec4 v_position;
varying vec2 v_texCoord;
varying vec3 v_normal;
struct PointLight{
    vec3 pos;
    vec4 color;
    float power;
    float constant;
    float linear;
    float quadratic;
};
uniform int u_numPointLights;
uniform PointLight u_pointLights[2];

struct SpotLight{
    vec3 pos;
    vec3 direction;
    vec4 color;
    float power;
    float cutOff;
};
uniform int u_numSpotLights;
uniform SpotLight u_spotLights[32];

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos);

//------------------------------------------------------------------------------

void main(void){
    vec3 color;
    if (u_use_texture) color = texture2D(u_texture, v_texCoord).xyz;
    else color = u_objColor.xyz;
    vec3 result = vec3(0.2, 0.2, 0.2);
    for (int i = 0; i < u_numPointLights; i++)
        result += CalcPointLight(u_pointLights[i], v_normal, v_position.xyz);
    for (int i = 0; i < u_numSpotLights; i++)
        result += CalcSpotLight(u_spotLights[i], v_normal, v_position.xyz);
    gl_FragColor = vec4(result*color, 1.0f);
}

//------------------------------------------------------------------------------

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos){
    vec3 lightDir = normalize(light.pos - fragPos);  // направление света
    float diff = max(dot(normal, lightDir), 0.0f);   // диффузное освещение
    // затухание
    float distance = length(light.pos - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    vec3 ambient  = light.color.xyz * 0.1;
    vec3 diffuse  = light.color.xyz * diff;
    ambient  *= attenuation;
    diffuse  *= attenuation;
    return (ambient + diffuse)*light.power;
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos){
    vec3 lightDir = normalize(light.pos - fragPos);
    float theta = dot(lightDir, normalize(light.direction));
    vec3 diffuse = vec3(0.0, 0.0, 0.0);
    if(theta > light.cutOff){
        float diff = max(dot(normal, lightDir), 0.0f);
        diffuse = diff * light.color.xyz * light.power;
    }
    return diffuse;
}




/*uniform vec4 u_objColor;
varying vec4 v_position;
varying vec3 v_normal;
struct PointLight{
    vec3 pos;
    vec4 color;
    float power;
    float constant;
    float linear;
    float quadratic;
};
uniform int u_numPointLights;
uniform PointLight u_pointLights[2];

struct SpotLight{
    vec3 pos;
    vec3 direction;
    vec4 color;
    float power;
    float cutOff;
};
uniform int u_numSpotLights;
uniform SpotLight u_spotLights[32];

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos);

//------------------------------------------------------------------------------

void main(void){
    vec3 result = vec3(0.2, 0.2, 0.2);
    for (int i = 0; i < u_numPointLights; i++)
        result += CalcPointLight(u_pointLights[i], v_normal, v_position.xyz);
    for (int i = 0; i < u_numSpotLights; i++)
        result += CalcSpotLight(u_spotLights[i], v_normal, v_position.xyz);
    gl_FragColor = vec4(result*(u_objColor.xyz), 1.0f);
}

//------------------------------------------------------------------------------

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos){
    vec3 lightDir = normalize(light.pos - fragPos);  // направление света
    float diff = max(dot(normal, lightDir), 0.0f);   // диффузное освещение
    // затухание
    float distance = length(light.pos - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    vec3 ambient  = light.color.xyz * 0.1;
    //vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse  = light.color.xyz * diff;
    ambient  *= attenuation;
    diffuse  *= attenuation;
    return (ambient + diffuse)*light.power;
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos){
    vec3 lightDir = normalize(light.pos - fragPos);
    float theta = dot(lightDir, normalize(light.direction));
    vec3 diffuse = vec3(0.0, 0.0, 0.0);
    if(theta > light.cutOff){
        float diff = max(dot(normal, lightDir), 0.0f);
        diffuse = diff * light.color.xyz * light.power;
    }
    return diffuse;
}
*/
