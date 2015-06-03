#version 150 //use opengl version 3.2/glsl version 1.5

in vec4 vPosition; //takes in the vertex data from the main program

void main()
{
    gl_Position = vPosition; // sends them into the rasterizer as gl_position (gl_position is a built in output)
}

//attribute: same as in for vertex shader
//varying: same as out for vertex shader, same as in for fragment shader