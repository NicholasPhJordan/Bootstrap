#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float kSpecularPower;

// Light0
uniform vec3 iDirection0;
uniform vec3 iAmbient0;
uniform vec3 iDiffuse0;
uniform vec3 iSpecular0;

// Light1
uniform vec3 iDirection1;
uniform vec3 iAmbient1;
uniform vec3 iDiffuse1;
uniform vec3 iSpecular1;

uniform vec3 cameraPosition;

out vec4 pColor;

void main() {
	//Light 0 
	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal = normalize(iDirection0);

	//Calculate ambient color
	vec3 ambientColor = (fColor.xyz + kAmbient) * iAmbient0;

	//Calculate diffuse color
	float lambertTerm = dot(kNormal, -iNormal);
	lambertTerm = max(0.0f, min(1.0f, lambertTerm));
	vec3 diffuseColor = (fColor.xyz + kDiffuse) * iDiffuse0 * lambertTerm;

	//Calculate specular color
	vec3 surfaceToView = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal = reflect(iNormal, kNormal);
	float specularTerm = dot(surfaceToView, reflectionNormal);
	specularTerm = max(0.0f, specularTerm);
	specularTerm = pow(specularTerm, kSpecularPower);
	vec3 specularColor = (fColor.xyz + kSpecular) * iSpecular0 * specularTerm;

	vec4 color0 = vec4(ambientColor + diffuseColor + specularColor, 1.0f);

	//Light 1 
	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal = normalize(iDirection1);

	//Calculate ambient color
	vec3 ambientColor = (fColor.xyz + kAmbient) * iAmbient1;

	//Calculate diffuse color
	float lambertTerm = dot(kNormal, -iNormal);
	lambertTerm = max(0.0f, min(1.0f, lambertTerm));
	vec3 diffuseColor = (fColor.xyz + kDiffuse) * iDiffuse1 * lambertTerm;

	//Calculate specular color
	vec3 surfaceToView = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal = reflect(iNormal, kNormal);
	float specularTerm = dot(surfaceToView, reflectionNormal);
	specularTerm = max(0.0f, specularTerm);
	specularTerm = pow(specularTerm, kSpecularPower);
	vec3 specularColor = (fColor.xyz + kSpecular) * iSpecular1 * specularTerm;

	vec4 color1 = vec4(ambientColor + diffuseColor + specularColor, 1.0f);

	//Final Resault
	pColor = color0 + color1;
}
