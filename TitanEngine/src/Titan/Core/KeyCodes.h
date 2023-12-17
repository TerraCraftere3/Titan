#pragma once

namespace Titan
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define TI_KEY_SPACE           ::Titan::Key::Space
#define TI_KEY_APOSTROPHE      ::Titan::Key::Apostrophe    /* ' */
#define TI_KEY_COMMA           ::Titan::Key::Comma         /* , */
#define TI_KEY_MINUS           ::Titan::Key::Minus         /* - */
#define TI_KEY_PERIOD          ::Titan::Key::Period        /* . */
#define TI_KEY_SLASH           ::Titan::Key::Slash         /* / */
#define TI_KEY_0               ::Titan::Key::D0
#define TI_KEY_1               ::Titan::Key::D1
#define TI_KEY_2               ::Titan::Key::D2
#define TI_KEY_3               ::Titan::Key::D3
#define TI_KEY_4               ::Titan::Key::D4
#define TI_KEY_5               ::Titan::Key::D5
#define TI_KEY_6               ::Titan::Key::D6
#define TI_KEY_7               ::Titan::Key::D7
#define TI_KEY_8               ::Titan::Key::D8
#define TI_KEY_9               ::Titan::Key::D9
#define TI_KEY_SEMICOLON       ::Titan::Key::Semicolon     /* ; */
#define TI_KEY_EQUAL           ::Titan::Key::Equal         /* = */
#define TI_KEY_A               ::Titan::Key::A
#define TI_KEY_B               ::Titan::Key::B
#define TI_KEY_C               ::Titan::Key::C
#define TI_KEY_D               ::Titan::Key::D
#define TI_KEY_E               ::Titan::Key::E
#define TI_KEY_F               ::Titan::Key::F
#define TI_KEY_G               ::Titan::Key::G
#define TI_KEY_H               ::Titan::Key::H
#define TI_KEY_I               ::Titan::Key::I
#define TI_KEY_J               ::Titan::Key::J
#define TI_KEY_K               ::Titan::Key::K
#define TI_KEY_L               ::Titan::Key::L
#define TI_KEY_M               ::Titan::Key::M
#define TI_KEY_N               ::Titan::Key::N
#define TI_KEY_O               ::Titan::Key::O
#define TI_KEY_P               ::Titan::Key::P
#define TI_KEY_Q               ::Titan::Key::Q
#define TI_KEY_R               ::Titan::Key::R
#define TI_KEY_S               ::Titan::Key::S
#define TI_KEY_T               ::Titan::Key::T
#define TI_KEY_U               ::Titan::Key::U
#define TI_KEY_V               ::Titan::Key::V
#define TI_KEY_W               ::Titan::Key::W
#define TI_KEY_X               ::Titan::Key::X
#define TI_KEY_Y               ::Titan::Key::Y
#define TI_KEY_Z               ::Titan::Key::Z
#define TI_KEY_LEFT_BRACKET    ::Titan::Key::LeftBracket   /* [ */
#define TI_KEY_BACKSLASH       ::Titan::Key::Backslash     /* \ */
#define TI_KEY_RIGHT_BRACKET   ::Titan::Key::RightBracket  /* ] */
#define TI_KEY_GRAVE_ACCENT    ::Titan::Key::GraveAccent   /* ` */
#define TI_KEY_WORLD_1         ::Titan::Key::World1        /* non-US #1 */
#define TI_KEY_WORLD_2         ::Titan::Key::World2        /* non-US #2 */

/* Function keys */
#define TI_KEY_ESCAPE          ::Titan::Key::Escape
#define TI_KEY_ENTER           ::Titan::Key::Enter
#define TI_KEY_TAB             ::Titan::Key::Tab
#define TI_KEY_BACKSPACE       ::Titan::Key::Backspace
#define TI_KEY_INSERT          ::Titan::Key::Insert
#define TI_KEY_DELETE          ::Titan::Key::Delete
#define TI_KEY_RIGHT           ::Titan::Key::Right
#define TI_KEY_LEFT            ::Titan::Key::Left
#define TI_KEY_DOWN            ::Titan::Key::Down
#define TI_KEY_UP              ::Titan::Key::Up
#define TI_KEY_PAGE_UP         ::Titan::Key::PageUp
#define TI_KEY_PAGE_DOWN       ::Titan::Key::PageDown
#define TI_KEY_HOME            ::Titan::Key::Home
#define TI_KEY_END             ::Titan::Key::End
#define TI_KEY_CAPS_LOCK       ::Titan::Key::CapsLock
#define TI_KEY_SCROLL_LOCK     ::Titan::Key::ScrollLock
#define TI_KEY_NUM_LOCK        ::Titan::Key::NumLock
#define TI_KEY_PRINT_SCREEN    ::Titan::Key::PrintScreen
#define TI_KEY_PAUSE           ::Titan::Key::Pause
#define TI_KEY_F1              ::Titan::Key::F1
#define TI_KEY_F2              ::Titan::Key::F2
#define TI_KEY_F3              ::Titan::Key::F3
#define TI_KEY_F4              ::Titan::Key::F4
#define TI_KEY_F5              ::Titan::Key::F5
#define TI_KEY_F6              ::Titan::Key::F6
#define TI_KEY_F7              ::Titan::Key::F7
#define TI_KEY_F8              ::Titan::Key::F8
#define TI_KEY_F9              ::Titan::Key::F9
#define TI_KEY_F10             ::Titan::Key::F10
#define TI_KEY_F11             ::Titan::Key::F11
#define TI_KEY_F12             ::Titan::Key::F12
#define TI_KEY_F13             ::Titan::Key::F13
#define TI_KEY_F14             ::Titan::Key::F14
#define TI_KEY_F15             ::Titan::Key::F15
#define TI_KEY_F16             ::Titan::Key::F16
#define TI_KEY_F17             ::Titan::Key::F17
#define TI_KEY_F18             ::Titan::Key::F18
#define TI_KEY_F19             ::Titan::Key::F19
#define TI_KEY_F20             ::Titan::Key::F20
#define TI_KEY_F21             ::Titan::Key::F21
#define TI_KEY_F22             ::Titan::Key::F22
#define TI_KEY_F23             ::Titan::Key::F23
#define TI_KEY_F24             ::Titan::Key::F24
#define TI_KEY_F25             ::Titan::Key::F25

/* Keypad */
#define TI_KEY_KP_0            ::Titan::Key::KP0
#define TI_KEY_KP_1            ::Titan::Key::KP1
#define TI_KEY_KP_2            ::Titan::Key::KP2
#define TI_KEY_KP_3            ::Titan::Key::KP3
#define TI_KEY_KP_4            ::Titan::Key::KP4
#define TI_KEY_KP_5            ::Titan::Key::KP5
#define TI_KEY_KP_6            ::Titan::Key::KP6
#define TI_KEY_KP_7            ::Titan::Key::KP7
#define TI_KEY_KP_8            ::Titan::Key::KP8
#define TI_KEY_KP_9            ::Titan::Key::KP9
#define TI_KEY_KP_DECIMAL      ::Titan::Key::KPDecimal
#define TI_KEY_KP_DIVIDE       ::Titan::Key::KPDivide
#define TI_KEY_KP_MULTIPLY     ::Titan::Key::KPMultiply
#define TI_KEY_KP_SUBTRACT     ::Titan::Key::KPSubtract
#define TI_KEY_KP_ADD          ::Titan::Key::KPAdd
#define TI_KEY_KP_ENTER        ::Titan::Key::KPEnter
#define TI_KEY_KP_EQUAL        ::Titan::Key::KPEqual

#define TI_KEY_LEFT_SHIFT      ::Titan::Key::LeftShift
#define TI_KEY_LEFT_CONTROL    ::Titan::Key::LeftControl
#define TI_KEY_LEFT_ALT        ::Titan::Key::LeftAlt
#define TI_KEY_LEFT_SUPER      ::Titan::Key::LeftSuper
#define TI_KEY_RIGHT_SHIFT     ::Titan::Key::RightShift
#define TI_KEY_RIGHT_CONTROL   ::Titan::Key::RightControl
#define TI_KEY_RIGHT_ALT       ::Titan::Key::RightAlt
#define TI_KEY_RIGHT_SUPER     ::Titan::Key::RightSuper
#define TI_KEY_MENU            ::Titan::Key::Menu