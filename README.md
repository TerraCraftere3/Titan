# Titan ![MSBuild](https://github.com/TerraCraftere3/Titan/actions/workflows/msbuild.yml/badge.svg)

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

## Libraries

| Number         | Title                                            | Usage             |
| -------------- | ------------------------------------------------ | ----------------- |
| GLFW           | https://github.com/glfw/glfw                     | Windowing         |
| OpenGL         | https://www.opengl.org/                          | Rendering         |
| spdlog         | https://github.com/gabime/spdlog                 | Logging           |
| Vanadium ImGui | https://github.com/TerraCraftere3/vanadium-imgui | Debug UI          |
| Neon Editor    | Integrated into Titan                            | Editor            |
| Titan Backend  | Integrated into Titan                            | Engine            |
| glm            | https://github.com/g-truc/glm                    | Math              |
| Premake        | https://github.com/premake/premake-core          | Solution Creation |

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

## Build Status

| Title   | Status                                                                                      |
| ------- | ------------------------------------------------------------------------------------------- |
| MSBuild | ![MSBuild](https://github.com/TerraCraftere3/Titan/actions/workflows/msbuild.yml/badge.svg) |

## [License](https://github.com/TerraCraftere3/Titan/blob/main/LICENSE)

Titan Engine uses the "Apache License", Version 2.0, January 2004. Learn more on http://www.apache.org/licenses/
