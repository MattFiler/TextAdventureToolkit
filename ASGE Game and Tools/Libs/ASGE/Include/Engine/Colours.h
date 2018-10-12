#pragma once
namespace ASGE {

	/**
	* RGB Colour Helper. 
	* Used to represent the RGB values of a colour.
	*/
	struct Colour
	{
		float r = 1; /**< the red component.   */
		float g = 1; /**< the green component. */
		float b = 1; /**< the blue component.  */

		/**
		* Default constructor.
		* The constructor takes an array of 3 floats. These
		* are then mapped on the RGB values inside the struct.
		*/
		Colour(const float rgb[3]) noexcept
		{
			r = rgb[0];
			g = rgb[1];
			b = rgb[2];
		}
	};

	/**
	* COLOURS namespace.
	* Helper compile-time arrays representing common colours.
	*/
	namespace COLOURS {
		constexpr float ALICEBLUE[3] = { 0.941F, 0.973F, 1.000F };
		constexpr float ANTIQUEWHITE[] = { 0.980F, 0.922F, 0.843F };
		constexpr float AQUA[] = { 0.000F, 1.000F, 1.000F };
		constexpr float AQUAMARINE[] = { 0.498F, 1.000F, 0.831F };
		constexpr float AZURE[] = { 0.941F, 1.000F, 1.000F };
		constexpr float BEIGE[] = { 0.961F, 0.961F, 0.863F };
		constexpr float BISQUE[] = { 1.000F, 0.894F, 0.769F };
		constexpr float BLACK[] = { 0.000F, 0.000F, 0.000F };
		constexpr float BLANCHEDALMOND[] = { 1.000F, 0.922F, 0.804F };
		constexpr float BLUE[] = { 0.000F, 0.000F, 1.000F };
		constexpr float BLUEVIOLET[] = { 0.541F, 0.169F, 0.886F };
		constexpr float BROWN[] = { 0.647F, 0.165F, 0.165F };
		constexpr float BURLYWOOD[] = { 0.871F, 0.722F, 0.529F };
		constexpr float CADETBLUE[] = { 0.373F, 0.620F, 0.627F };
		constexpr float CHARTREUSE[] = { 0.498F, 1.000F, 0.000F };
		constexpr float CHOCOLATE[] = { 0.824F, 0.412F, 0.118F };
		constexpr float CORAL[] = { 1.000F, 0.498F, 0.314F };
		constexpr float CORNFLOWERBLUE[] = { 0.392F, 0.584F, 0.929F };
		constexpr float CORNSILK[] = { 1.000F, 0.973F, 0.863F };
		constexpr float CRIMSON[] = { 0.863F, 0.078F, 0.235F };
		constexpr float CYAN[] = { 0.000F, 1.000F, 1.000F };
		constexpr float DARKBLUE[] = { 0.000F, 0.000F, 0.545F };
		constexpr float DARKCYAN[] = { 0.000F, 0.545F, 0.545F };
		constexpr float DARKGOLDENROD[] = { 0.722F, 0.525F, 0.043F };
		constexpr float DARKGRAY[] = { 0.663F, 0.663F, 0.663F };
		constexpr float DARKGREEN[] = { 0.000F, 0.392F, 0.000F };
		constexpr float DARKGREY[] = { 0.663F, 0.663F, 0.663F };
		constexpr float DARKKHAKI[] = { 0.741F, 0.718F, 0.420F };
		constexpr float DARKMAGENTA[] = { 0.545F, 0.000F, 0.545F };
		constexpr float DARKOLIVEGREEN[] = { 0.333F, 0.420F, 0.184F };
		constexpr float DARKORANGE[] = { 1.000F, 0.549F, 0.000F };
		constexpr float DARKORCHID[] = { 0.600F, 0.196F, 0.800F };
		constexpr float DARKRED[] = { 0.545F, 0.000F, 0.000F };
		constexpr float DARKSALMON[] = { 0.914F, 0.588F, 0.478F };
		constexpr float DARKSEAGREEN[] = { 0.561F, 0.737F, 0.561F };
		constexpr float DARKSLATEBLUE[] = { 0.282F, 0.239F, 0.545F };
		constexpr float DARKSLATEGRAY[] = { 0.184F, 0.310F, 0.310F };
		constexpr float DARKSLATEGREY[] = { 0.184F, 0.310F, 0.310F };
		constexpr float DARKTURQUOISE[] = { 0.000F, 0.808F, 0.820F };
		constexpr float DARKVIOLET[] = { 0.580F, 0.000F, 0.827F };
		constexpr float DEEPPINK[] = { 1.000F, 0.078F, 0.576F };
		constexpr float DEEPSKYBLUE[] = { 0.000F, 0.749F, 1.000F };
		constexpr float DIMGRAY[] = { 0.412F, 0.412F, 0.412F };
		constexpr float DIMGREY[] = { 0.412F, 0.412F, 0.412F };
		constexpr float DODGERBLUE[] = { 0.118F, 0.565F, 1.000F };
		constexpr float FIREBRICK[] = { 0.698F, 0.133F, 0.133F };
		constexpr float FLORALWHITE[] = { 1.000F, 0.980F, 0.941F };
		constexpr float FORESTGREEN[] = { 0.133F, 0.545F, 0.133F };
		constexpr float FUCHSIA[] = { 1.000F, 0.000F, 1.000F };
		constexpr float GAINSBORO[] = { 0.863F, 0.863F, 0.863F };
		constexpr float GHOSTWHITE[] = { 0.973F, 0.973F, 1.000F };
		constexpr float GOLD[] = { 1.000F, 0.843F, 0.000F };
		constexpr float GOLDENROD[] = { 0.855F, 0.647F, 0.125F };
		constexpr float GRAY[] = { 0.502F, 0.502F, 0.502F };
		constexpr float GREEN[] = { 0.000F, 0.502F, 0.000F };
		constexpr float GREENYELLOW[] = { 0.678F, 1.000F, 0.184F };
		constexpr float GREY[] = { 0.502F, 0.502F, 0.502F };
		constexpr float HONEYDEW[] = { 0.941F, 1.000F, 0.941F };
		constexpr float HOTPINK[] = { 1.000F, 0.412F, 0.706F };
		constexpr float INDIANRED[] = { 0.804F, 0.361F, 0.361F };
		constexpr float INDIGO[] = { 0.294F, 0.000F, 0.510F };
		constexpr float IVORY[] = { 1.000F, 1.000F, 0.941F };
		constexpr float KHAKI[] = { 0.941F, 0.902F, 0.549F };
		constexpr float LAVENDER[] = { 0.902F, 0.902F, 0.980F };
		constexpr float LAVENDERBLUSH[] = { 1.000F, 0.941F, 0.961F };
		constexpr float LAWNGREEN[] = { 0.486F, 0.988F, 0.000F };
		constexpr float LEMONCHIFFON[] = { 1.000F, 0.980F, 0.804F };
		constexpr float LIGHTBLUE[] = { 0.678F, 0.847F, 0.902F };
		constexpr float LIGHTCORAL[] = { 0.941F, 0.502F, 0.502F };
		constexpr float LIGHTCYAN[] = { 0.878F, 1.000F, 1.000F };
		constexpr float LIGHTGOLDENRODYELLOW[] = { 0.980F, 0.980F, 0.824F };
		constexpr float LIGHTGRAY[] = { 0.827F, 0.827F, 0.827F };
		constexpr float LIGHTGREEN[] = { 0.565F, 0.933F, 0.565F };
		constexpr float LIGHTGREY[] = { 0.827F, 0.827F, 0.827F };
		constexpr float LIGHTPINK[] = { 1.000F, 0.714F, 0.757F };
		constexpr float LIGHTSALMON[] = { 1.000F, 0.627F, 0.478F };
		constexpr float LIGHTSEAGREEN[] = { 0.125F, 0.698F, 0.667F };
		constexpr float LIGHTSKYBLUE[] = { 0.529F, 0.808F, 0.980F };
		constexpr float LIGHTSLATEGRAY[] = { 0.467F, 0.533F, 0.600F };
		constexpr float LIGHTSLATEGREY[] = { 0.467F, 0.533F, 0.600F };
		constexpr float LIGHTSTEELBLUE[] = { 0.690F, 0.769F, 0.871F };
		constexpr float LIGHTYELLOW[] = { 1.000F, 1.000F, 0.878F };
		constexpr float LIME[] = { 0.000F, 1.000F, 0.000F };
		constexpr float LIMEGREEN[] = { 0.196F, 0.804F, 0.196F };
		constexpr float LINEN[] = { 0.980F, 0.941F, 0.902F };
		constexpr float MAGENTA[] = { 1.000F, 0.000F, 1.000F };
		constexpr float MAROON[] = { 0.502F, 0.000F, 0.000F };
		constexpr float MEDIUMAQUAMARINE[] = { 0.400F, 0.804F, 0.667F };
		constexpr float MEDIUMBLUE[] = { 0.000F, 0.000F, 0.804F };
		constexpr float MEDIUMORCHID[] = { 0.729F, 0.333F, 0.827F };
		constexpr float MEDIUMPURPLE[] = { 0.576F, 0.439F, 0.859F };
		constexpr float MEDIUMSEAGREEN[] = { 0.235F, 0.702F, 0.443F };
		constexpr float MEDIUMSLATEBLUE[] = { 0.482F, 0.408F, 0.933F };
		constexpr float MEDIUMSPRINGGREEN[] = { 0.000F, 0.980F, 0.604F };
		constexpr float MEDIUMTURQUOISE[] = { 0.282F, 0.820F, 0.800F };
		constexpr float MEDIUMVIOLETRED[] = { 0.780F, 0.082F, 0.522F };
		constexpr float MIDNIGHTBLUE[] = { 0.098F, 0.098F, 0.439F };
		constexpr float MINTCREAM[] = { 0.961F, 1.000F, 0.980F };
		constexpr float MISTYROSE[] = { 1.000F, 0.894F, 0.882F };
		constexpr float MOCCASIN[] = { 1.000F, 0.894F, 0.710F };
		constexpr float NAVAJOWHITE[] = { 1.000F, 0.871F, 0.678F };
		constexpr float NAVY[] = { 0.000F, 0.000F, 0.502F };
		constexpr float OLDLACE[] = { 0.992F, 0.961F, 0.902F };
		constexpr float OLIVE[] = { 0.502F, 0.502F, 0.000F };
		constexpr float OLIVEDRAB[] = { 0.420F, 0.557F, 0.137F };
		constexpr float ORANGE[] = { 1.000F, 0.647F, 0.000F };
		constexpr float ORANGERED[] = { 1.000F, 0.271F, 0.000F };
		constexpr float ORCHID[] = { 0.855F, 0.439F, 0.839F };
		constexpr float PALEGOLDENROD[] = { 0.933F, 0.910F, 0.667F };
		constexpr float PALEGREEN[] = { 0.596F, 0.984F, 0.596F };
		constexpr float PALETURQUOISE[] = { 0.686F, 0.933F, 0.933F };
		constexpr float PALEVIOLETRED[] = { 0.859F, 0.439F, 0.576F };
		constexpr float PAPAYAWHIP[] = { 1.000F, 0.937F, 0.835F };
		constexpr float PEACHPUFF[] = { 1.000F, 0.855F, 0.725F };
		constexpr float PERU[] = { 0.804F, 0.522F, 0.247F };
		constexpr float PINK[] = { 1.000F, 0.753F, 0.796F };
		constexpr float PLUM[] = { 0.867F, 0.627F, 0.867F };
		constexpr float POWDERBLUE[] = { 0.690F, 0.878F, 0.902F };
		constexpr float PURPLE[] = { 0.502F, 0.000F, 0.502F };
		constexpr float RED[] = { 1.000F, 0.000F, 0.000F };
		constexpr float ROSYBROWN[] = { 0.737F, 0.561F, 0.561F };
		constexpr float ROYALBLUE[] = { 0.255F, 0.412F, 0.882F };
		constexpr float SADDLEBROWN[] = { 0.545F, 0.271F, 0.075F };
		constexpr float SALMON[] = { 0.980F, 0.502F, 0.447F };
		constexpr float SANDYBROWN[] = { 0.957F, 0.643F, 0.376F };
		constexpr float SEAGREEN[] = { 0.180F, 0.545F, 0.341F };
		constexpr float SEASHELL[] = { 1.000F, 0.961F, 0.933F };
		constexpr float SIENNA[] = { 0.627F, 0.322F, 0.176F };
		constexpr float SILVER[] = { 0.753F, 0.753F, 0.753F };
		constexpr float SKYBLUE[] = { 0.529F, 0.808F, 0.922F };
		constexpr float SLATEBLUE[] = { 0.416F, 0.353F, 0.804F };
		constexpr float SLATEGRAY[] = { 0.439F, 0.502F, 0.565F };
		constexpr float SLATEGREY[] = { 0.439F, 0.502F, 0.565F };
		constexpr float SNOW[] = { 1.000F, 0.980F, 0.980F };
		constexpr float SPRINGGREEN[] = { 0.000F, 1.000F, 0.498F };
		constexpr float STEELBLUE[] = { 0.275F, 0.510F, 0.706F };
		constexpr float TAN[] = { 0.824F, 0.706F, 0.549F };
		constexpr float TEAL[] = { 0.000F, 0.502F, 0.502F };
		constexpr float THISTLE[] = { 0.847F, 0.749F, 0.847F };
		constexpr float TOMATO[] = { 1.000F, 0.388F, 0.278F };
		constexpr float TURQUOISE[] = { 0.251F, 0.878F, 0.816F };
		constexpr float VIOLET[] = { 0.933F, 0.510F, 0.933F };
		constexpr float WHEAT[] = { 0.961F, 0.871F, 0.702F };
		constexpr float WHITE[] = { 1.000F, 1.000F, 1.000F };
		constexpr float WHITESMOKE[] = { 0.961F, 0.961F, 0.961F };
		constexpr float YELLOW[] = { 1.000F, 1.000F, 0.000F };
		constexpr float YELLOWGREEN[] = { 0.604F, 0.804F, 0.196F };
	}
}