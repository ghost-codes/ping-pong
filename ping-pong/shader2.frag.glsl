
#version 410 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

// uniform sampler2D ourTexture;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

struct Material {
  vec3 ambient;
  sampler2D diffuse;
  sampler2D specular;
  float shininess;
};

struct Light {
  // code for directional light
  // uncomment to use directional
  vec3 direction;
  vec3 position;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;

  float constant;
  float linear;
  float quadratic;

  float cutoff;
  float outerCutOff;
};

uniform Light light;
uniform Material material;

void main() {
  // Working with ambiance
  vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoord));

  // work with difuse
  vec3 norm = normalize(Normal);

  // when working with meshlights or points
  // vec3 lightDir = normalize(light.position - FragPos);
  // -----> Computing Attenuation
  // float theta = dot(lightDir, normalize(-light.direction));
  // float epsilon = light.cutoff - light.outerCutOff;
  // float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
  //
  // if (theta > light.cutoff) {
  // float distance = length(light.position - FragPos);
  // float attenuation = 1.0 / (light.constant + light.linear * distance +
  //                            light.quadratic * (distance * distance));
  // -----> Uncomment to use directional lights
  vec3 lightDir = normalize(-light.direction);

  float diffImpact = max(dot(lightDir, norm), 0.0);
  vec3 diffuse = light.diffuse *
                 (diffImpact * vec3(texture(material.diffuse, TexCoord).rgb));

  // work with specular
  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectedLight = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectedLight), 0.0), material.shininess);
  vec3 specular =
      light.specular * (spec * vec3(texture(material.specular, TexCoord)));

  // diffuse *= attenuation;
  // specular *= attenuation;
  // ambient *= attenuation;
  // diffuse *= intensity;
  // specular *= intensity;
  FragColor = vec4(ambient + diffuse + specular, 1.0);
  // FragColor = texture(material.diffuse, TexCoord);
  // } else {
  //   FragColor =
  //       vec4(light.ambient * texture(material.diffuse, TexCoord).rgb, 1.0);
  // }
}
