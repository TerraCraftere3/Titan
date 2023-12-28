# Titan

![GitHub License](https://img.shields.io/github/license/TerraCrafterE3/Titan) ![GitHub repo size](https://img.shields.io/github/repo-size/TerraCrafterE3/Titan) ![Version Badge](https://img.shields.io/badge/Version-0.3.0-red?logo=github) ![MSBuild](https://github.com/TerraCraftere3/Titan/actions/workflows/msbuild.yml/badge.svg)

Titan is a game engine (framework) developed by me.
The Engine supports 2D, advanced Mathematics, Windowing, Modern OpenGL and more.
For now it does NOT support 3D Rendering.

## How to use

For now you need to clone the entire repo.

- Clone the repository in an empty folder
- Run `scripts/GenProjects`
- Open `TitanEngine.sln`
- Run the Project

## Releases

| Number | Title                   | Status |
| ------ | ----------------------- | ------ |
| 0.3.x  | Developing: Editor      | Alpha  |
| 0.2.x  | The Age of Rendering    | Alpha  |
| 0.1.x  | Window and Event System | Alpha  |
| 0.0.x  | The Beginning           | Alpha  |

## Build Status

| Title   | Status                                                                                      |
| ------- | ------------------------------------------------------------------------------------------- |
| MSBuild | ![MSBuild](https://github.com/TerraCraftere3/Titan/actions/workflows/msbuild.yml/badge.svg) |

## Features

#### Event Handling

- [x] Event System
- [x] Mouse Events
- [x] Key Events
- [x] Window Events
- [ ] Custom Events

#### Rendering

- [x] Window ([GLFW](https://github.com/glfw/glfw))
- [x] Rendering ([OpenGL](https://www.opengl.org/) and Custom API)
- [x] 2D
- [ ] 3D
- [x] Debug UI Rendering ([Vanadium ImGui](https://github.com/TerraCraftere3/vanadium-imgui))
- [ ] PBR (Physics Based Rendering)
- [ ] RayTracing
- [x] Batching

#### Templates

- [ ] Water, PBR and other Shader Templates

#### Shader

- [x] Shader
- [ ] Compute Shader

#### Textures

- [x] Texture Files
- [x] 2D Textures
- [ ] 3D Textures
- [x] Spritesheets

#### Platforms

- [x] Windows
- [ ] Linux
- [ ] Mac

#### Developing

- [x] Logging ([spdlog](https://github.com/gabime/spdlog) and Custom API)
- [x] Editor
- [ ] Hot Code Reloading

#### Other

- [x] Math Library ([GLM](https://github.com/g-truc/glm))
- [ ] Asset library
- [x] Asset files

## Support Me

<a href="https://www.buymeacoffee.com/TerraCrafterE3"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" width="150"/></a>

## Discord

<iframe src="https://discord.com/widget?id=1189152743995211857&theme=dark" width="350" height="500" allowtransparency="true" frameborder="0" sandbox="allow-popups allow-popups-to-escape-sandbox allow-same-origin allow-scripts"></iframe>

## Libraries

| Number         | Title                                                            | Usage                   |
| -------------- | ---------------------------------------------------------------- | ----------------------- |
| GLFW           | https://github.com/glfw/glfw                                     | Windowing               |
| OpenGL         | https://www.opengl.org/                                          | Rendering               |
| spdlog         | https://github.com/gabime/spdlog                                 | Logging                 |
| Vanadium ImGui | https://github.com/TerraCraftere3/vanadium-imgui                 | Debug UI                |
| Neon Editor    | [Integrated into Titan](https://github.com/TerraCraftere3/Titan) | Editor                  |
| Titan Backend  | [Integrated into Titan](https://github.com/TerraCraftere3/Titan) | Engine                  |
| glm            | https://github.com/g-truc/glm                                    | Math                    |
| Premake        | https://github.com/premake/premake-core                          | Solution Creation       |
| Entt           | https://github.com/skypjack/entt                                 | Entity Component System |

## [License](https://github.com/TerraCraftere3/Titan/blob/main/LICENSE)

Titan Engine uses the "Apache License", Version 2.0, January 2004. Learn more on http://www.apache.org/licenses/
All other Licenses for libraries, etc. can be found under `./LICENSES/`
