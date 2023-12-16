#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in float a_TexIndex;
layout(location = 4) in float a_TilingFactor;

uniform mat4 u_ViewProjection;

out vec4 v_Color;
out vec2 v_TexCoord;
out float v_TexIndex;
out float v_TilingFactor;

void main()
{
	v_Color = a_Color;
	v_TexCoord = a_TexCoord;
	v_TexIndex = a_TexIndex;
	v_TilingFactor = a_TilingFactor;
	gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_Color;
in vec2 v_TexCoord;
in float v_TexIndex;
in float v_TilingFactor;

uniform sampler2D u_Textures[32];

void main()
{
	vec4 texColor = v_Color;
	//to invert the y coord i used 1-v_TexCoord.y
	vec2 texCoord = vec2(v_TexCoord.x, 1-v_TexCoord.y);
	switch(int(v_TexIndex))
	{
		case  0: texColor *= texture(u_Textures[ 0], texCoord*v_TilingFactor); break;
		case  1: texColor *= texture(u_Textures[ 1], texCoord*v_TilingFactor); break;
		case  2: texColor *= texture(u_Textures[ 2], texCoord*v_TilingFactor); break;
		case  3: texColor *= texture(u_Textures[ 3], texCoord*v_TilingFactor); break;
		case  4: texColor *= texture(u_Textures[ 4], texCoord*v_TilingFactor); break;
		case  5: texColor *= texture(u_Textures[ 5], texCoord*v_TilingFactor); break;
		case  6: texColor *= texture(u_Textures[ 6], texCoord*v_TilingFactor); break;
		case  7: texColor *= texture(u_Textures[ 7], texCoord*v_TilingFactor); break;
		case  8: texColor *= texture(u_Textures[ 8], texCoord*v_TilingFactor); break;
		case  9: texColor *= texture(u_Textures[ 9], texCoord*v_TilingFactor); break;
		case 10: texColor *= texture(u_Textures[10], texCoord*v_TilingFactor); break;
		case 11: texColor *= texture(u_Textures[11], texCoord*v_TilingFactor); break;
		case 12: texColor *= texture(u_Textures[12], texCoord*v_TilingFactor); break;
		case 13: texColor *= texture(u_Textures[13], texCoord*v_TilingFactor); break;
		case 14: texColor *= texture(u_Textures[14], texCoord*v_TilingFactor); break;
		case 15: texColor *= texture(u_Textures[15], texCoord*v_TilingFactor); break;
		case 16: texColor *= texture(u_Textures[16], texCoord*v_TilingFactor); break;
		case 17: texColor *= texture(u_Textures[17], texCoord*v_TilingFactor); break;
		case 18: texColor *= texture(u_Textures[18], texCoord*v_TilingFactor); break;
		case 19: texColor *= texture(u_Textures[19], texCoord*v_TilingFactor); break;
		case 20: texColor *= texture(u_Textures[20], texCoord*v_TilingFactor); break;
		case 21: texColor *= texture(u_Textures[21], texCoord*v_TilingFactor); break;
		case 22: texColor *= texture(u_Textures[22], texCoord*v_TilingFactor); break;
		case 23: texColor *= texture(u_Textures[23], texCoord*v_TilingFactor); break;
		case 24: texColor *= texture(u_Textures[24], texCoord*v_TilingFactor); break;
		case 25: texColor *= texture(u_Textures[25], texCoord*v_TilingFactor); break;
		case 26: texColor *= texture(u_Textures[26], texCoord*v_TilingFactor); break;
		case 27: texColor *= texture(u_Textures[27], texCoord*v_TilingFactor); break;
		case 28: texColor *= texture(u_Textures[28], texCoord*v_TilingFactor); break;
		case 29: texColor *= texture(u_Textures[29], texCoord*v_TilingFactor); break;
		case 30: texColor *= texture(u_Textures[30], texCoord*v_TilingFactor); break;
		case 31: texColor *= texture(u_Textures[31], texCoord*v_TilingFactor); break;
	}
	color = texColor;
}