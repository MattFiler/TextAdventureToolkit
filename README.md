# Text Adventure Creation Tool

### This project allows for the creation of text adventures through a simple flowchart interface.

<img align="right" src="https://i.imgur.com/py2qBDt.png" width="30%">

You can output to...

* **Unreal Engine 4** - a 3D scene.
* **Unity** - a 2D scene.
* **OpenGL** - a 2D scene with the framework "ASGE".

... with no programming at all! 

Text adventures are created through a drag and drop flowchart system.

## Getting started

It's easy to get going...

1. [Download the latest release](https://github.com/MattFiler/TextAdventureToolkit/releases/download/v1.0/Text.Adventure.Creator.zip). This includes the tool itself, documentation, and all required assets.
2. Launch "Text Adventure Creator.exe".

You will see a number of default projects in the first dropdown to try out.

## Creating a new adventure

To create a new adventure, open the tools and...

1. Press "New".
2. Enter the name of your game, E.G. "My Awesome Adventure". This must be unique.
3. Enter your developer name, E.G. "Matt Filer".
4. Enter the game's response for an invalid input, E.G. "I don't understand this command!".
5. Enter the 'thinking' response to display while responding, E.G. "<< WAIT >>".

You now have your first project!

## Scripting your story

No code is needed for this, everything is scripted through a flowchart interface...

<img align="right" src="https://i.imgur.com/TC1bAcO.png" width="50%">

1. With your project selected in the dropdown, press "Edit Logic".
2. In the new window that opens, select "main" in the top left.
3. Create your story by dragging and dropping nodes from the top left groups into the editor window.

To learn what each node does in the flowchart editor, follow the documentation located in the "docs" folder.

## Localising your game

These tools are created with localisation in mind, so all responses you script in the flowchart editor must correspond to premade strings in the localisation tool (read the documentation in the "docs" folder for more information on this).

To create a new localised string...

1. Select your project in the main tool window dropdown, and press "Edit Localisation".
2. Press "Add New String".
3. Enter a unique ID for your new string.
4. Type out the string in the window that appears. You can switch languages here and enter language-specific responses. Alternatively, press "Apply Current To All" to apply the current language entry to all language definitions.
5. When done, press "Save and Close".

To edit an existing string, select one in the main localisation window and press "Edit Selected String". Similarly, to remove a string, select it in the editor and press "Remove Selected String".

The unique ID you give your string is what you will reference in the flowchart editor.

## Going further

<img align="right" src="https://i.imgur.com/MQa1UEL.png" width="50%">

Although this tool requires no coding knowledge, all project files for the Unity, Unreal 4, and OpenGL implementation are included. Also included are all project files for the tool itself and the flowchart editor / plugin.

This is included so that if you intend to expand the toolkit for your own projects, you are free to do so!

A few ideas for expansion...

* Custom splashscreens
* Custom audio imports
* Linking between localisation tool and flowchart editor

...the list goes on!

## Final mentions

* [Brainiac Designer](https://archive.codeplex.com/?p=brainiac) was originally created by Daniel Kollmann. 
* ASGE is used for the OpenGL implementation, created by [James Huxtable](https://github.com/HuxyUK).
* Thanks to [Jon McKellan](https://twitter.com/jon_NoCode) and [Andy Bray](https://www.linkedin.com/in/andy-bray-4121226/) for answering some questions for my report!
