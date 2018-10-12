////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009, Daniel Kollmann
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice, this list of conditions
//   and the following disclaimer.
//
// - Redistributions in binary form must reproduce the above copyright notice, this list of
//   conditions and the following disclaimer in the documentation and/or other materials provided
//   with the distribution.
//
// - Neither the name of Daniel Kollmann nor the names of its contributors may be used to endorse
//   or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
// FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
// WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
////////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Text;
using Brainiac.Design;
using TextAdventure.Properties;

namespace TextAdventure
{
	/// <summary>
	/// Text Adventure plugin for visual scripting of the text adventure game.
	/// </summary>
	public class TextAdventure : Plugin
	{
		public TextAdventure()
		{
			// register resource manager
			AddResourceManager(Resources.ResourceManager);

			NodeGroup TextAdventureGroup = new NodeGroup("Main Nodes", NodeIcon.Condition, null);
			_nodeGroups.Add(TextAdventureGroup);

            NodeGroup TextAdventureGroup2 = new NodeGroup("Secondary Nodes", NodeIcon.Condition, null);
            _nodeGroups.Add(TextAdventureGroup2);

            NodeGroup TextAdventureGroup3 = new NodeGroup("Setup Node", NodeIcon.Condition, null);
            _nodeGroups.Add(TextAdventureGroup3);

            TextAdventureGroup.Items.Add(typeof(Nodes.UserInputLocation));
            TextAdventureGroup.Items.Add(typeof(Nodes.ZoneDefinition));
            TextAdventureGroup.Items.Add(typeof(Nodes.ZoneState));

            TextAdventureGroup2.Items.Add(typeof(Nodes.HasItem));
            TextAdventureGroup2.Items.Add(typeof(Nodes.ItemEvent));
            TextAdventureGroup2.Items.Add(typeof(Nodes.Item));
            TextAdventureGroup2.Items.Add(typeof(Nodes.MovePlayer));
            TextAdventureGroup2.Items.Add(typeof(Nodes.ZoneIntro));
            TextAdventureGroup2.Items.Add(typeof(Nodes.TextOutput));

            TextAdventureGroup3.Items.Add(typeof(Nodes.LevelContainer));

            // register all the file managers
            _fileManagers.Add( new FileManagerInfo(typeof(Brainiac.Design.FileManagers.FileManagerXML), "Behaviour XML (*.xml)|*.xml", ".xml") );

			// register all the exporters
			_exporters.Add( new ExporterInfo(typeof(Brainiac.Design.Exporters.ExporterCs), "C# Behavior Exporter (Assign Properties)", true, "C#Properties") );
			_exporters.Add( new ExporterInfo(typeof(Brainiac.Design.Exporters.ExporterCsUseParameters), "C# Behavior Exporter (Use Parameters)", true, "C#Parameters") );
		}
	}
}
