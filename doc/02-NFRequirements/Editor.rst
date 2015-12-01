Editor Non-Functional Requirements
==================================

- The editor GUI is implemented in Qt/C++.
- Data about the project and "asset seasoning" are serialized in XML.
- The project directory contains a "ProjectName.gp" file that holds project settings.
- The project directory contains an "assets" subdirectory. Asset files are placed there. For each known asset file there will be another file with the same filename and extension "asset".
- The project directory contains a "library" subdirectory. This will contain converted/preprocessed assets that are ready to be loaded by the Player.

