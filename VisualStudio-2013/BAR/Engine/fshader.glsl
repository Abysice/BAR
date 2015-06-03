#version 150 //use opengl version 3.2/glsl version 1.5

out vec4  fColor; //output the fragment color to the frame buffer

void main()
{
    fColor = vec4( 1.0, 0.0, 0.0, 1.0 ); //no extra input needed since we can output constant color
}