// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19
//

attribute vec3 pos;
attribute vec3 tex;
attribute vec3 normal;

varying mediump vec3 frag_pos;
varying mediump vec3 out_normal;

varying mediump vec2 out_tex; // utile ?
varying mediump vec2 tex_coord; // utile ?

uniform vec4 u_view;
uniform vec4 u_model;
uniform vec4 u_projection;

void main(void)
{
   gl_Position = u_projection * u_view * u_model * vec4(pos, 1);
   frag_pos = vec3(u_view * u_model * vec4(pos, 1));
   out_normal = vec3(u_view * u_model * vec4(normal,0));
   tex_coord = tex.st;
}
