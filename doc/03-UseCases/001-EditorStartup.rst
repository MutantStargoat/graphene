Use case: Editor Startup
========================

Basic flow
----------
- User starts the Editor executable
- Editor persistence is loaded.
- Editor windows/panels etc are placed/resized to match the last active layout (saved in persistence).
- The last active project is found in editor persistence and loaded.
- The AssetLibrary_ is refreshed. This normalizes any file changes the user may have done to the assets files.
- The last active scene of the project is loaded.
- SceneHirerarchyPanel_ is populated with the loaded scene's objects.
- Control is passed to the user.

.. _AssetLibrary: ../02-NFRequirements/Editor.html
.. _SceneHirerarchyPanel: ../01-Requirements/GUI-Pre-analysis.html

Alternative flow 1: No persistence, broken persistence, first time use.
-----------------------------------------------------------------------
- The user is prompted with a dialog box, to create a new project.
- User specifies project name and project directory.
- A new project template is generated/copied to the destination directory.
- Last active project and editor layout are saved to persistence.
- Control is passed to the user.



