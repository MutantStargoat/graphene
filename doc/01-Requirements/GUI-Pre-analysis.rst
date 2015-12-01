GUI Requirements
================

.. image:: GUI-Pre-analysis.svg

- All components of the GUI are dockable and scalable.
- Tool bar contains commonly used tools. The tool buttons behave as toggles. When one is pressed, the editor goes in the respective mode. Ex: When "polygon tool" is pressed, the editor goes in polygon editing mode.
- Asset hierarchy reflects the contents of the <a href="../02-NFRequirements/Editor.html"> assets directory</a> in the filesystem.
- Scene hierarchy reflects the contents of the active scene (game object hierarchy).
- Editor area shows rendering of the current scene. It supports viewing modes (orthographic/perspective) and responds to user input. Ex: right-click+drag = camera is panned.
- Inspector: displays/exposes the components of the currently active game object.
