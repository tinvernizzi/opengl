#version 330 core
// Cours de Realite Virtuelle
// leo.donati@unice.fr
//
// 2018_2019
//
// Fragment Buffer Très Simple

in vec4 out_color;
out vec4 fragColor;

void main(void)
{
    fragColor = out_color.rgba;
}
