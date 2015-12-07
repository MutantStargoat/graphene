Graphene game engine
====================

About
-----

Graphene is (going to be) a component-based OpenGL game engine.

Directory Structure
-------------------

 - *engine* contains the set of C/C++ libraries which are the reusable code
   of the graphene engine. Some of its constituent libraries can be used
   standalone, or they can be combined with the higher-level tools to get a
   complete engine, tools, and content pipeline for your game.
 - *editor* contains the main graphical tool which combines all the
   functionality of the engine with its full content pipeline, allowing you to
   easily combine data files, scripts, and plugins, with the graphene engine, in
   order to make your game.
 - *player* contains the game program. It uses the engine libraries, and the
   data produced by the editor, to actually run the game.
 - *doc* houses all the documentation of this project. It includes (or will
   eventually) design documents, file format specifications, and user manuals.
