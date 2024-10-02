/*attribute vec4 a_position;
attribute vec3 a_normal;
uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_modelMatrix;
varying vec4 v_position;
varying vec3 v_normal;


void main(void){
    gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * a_position;
    v_normal = normalize(a_normal);
    v_position = u_modelMatrix * a_position;
}
*/
attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec3 a_normal;
uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_modelMatrix;
uniform bool u_use_texture;
varying vec4 v_position;
varying vec2 v_texCoord;
varying vec3 v_normal;


void main(void){
    gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * a_position;
    if (u_use_texture) v_texCoord = a_texCoord;        // передача в фрагментный шейдер
    v_normal = normalize(a_normal);
    v_position = u_modelMatrix * a_position;
}
