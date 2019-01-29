// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

varying vec4 out_color;
varying vec3 frag_pos;
varying vec3 out_normal;

vec4 light_ambient_color;
vec4 light_diffuse_color;
vec4 light_specular_color;
float light_specular_strength;
vec3 light_position;
vec3 view_position;

varying mediump vec2 tex_coord;
uniform sampler2D texture0;

void main(void)
{
    light_diffuse_color = vec4(0,0,0,0);
    light_specular_color = vec4(0,0,0,0); // init ?
    light_ambient_color = vec4(0,0,0,0);
    light_specular_strength = 300.0;
    light_position = vec3(4,4,0);

    //calcul de la composante ambiante
    vec4 ambient = texture2D(texture0, tex_coord) * light_ambient_color;
    //calcul de la composante diffuse
    vec3 norm = normalize(out_normal);
    vec3 lightdir = normalize(light_position - frag_pos);
    float coeff_diffusion = max(dot(lightdir, norm), 0.0);
    vec4 diffuse = (coeff_diffusion * light_diffuse_color); //parametre color enlevé ici
    //calcul de la composante spéculaire
    vec3 viewdir = normalize(frag_pos - view_position);
    vec3 reflectdir = reflect(lightdir, norm);
    float coeff_specular = pow(max(dot(viewdir, reflectdir), 0.0), light_specular_strength);
    vec4 specular = (coeff_specular * light_specular_color) * texture2D(texture0, tex_coord);

    //couleur finale
    gl_FragColor = ambient + diffuse + specular;
}

// ajouter la composante alpha
