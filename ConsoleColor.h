/***************************************************************************************\
* Auth: Seth DeSantis
* Module Name: ColorizeConsole.h
* Date: 2/10/15
* Info: Change the text foreground color in the console. If there is desire to change the
*		background, run the TestAllColors() function to get a printout of all the possible
*		combinations (foreground & background)
*
\***************************************************************************************/
#pragma once
#include <Windows.h>
#include <iostream> 

// Change the colors of the system Console
#define T_DARK_BLACK	 0	// Dark Black
#define T_DARK_BLUE		 1	// Dark Blue
#define T_DARK_GREEN	 2	// Dark Green
#define T_DARK_CYAN		 3	// Dark Cyan
#define T_DARK_RED		 4	// Dark Red
#define T_DARK_PURPLE	 5	// Dark Purple
#define T_DARK_YELLOW	 6	// Dark Yellow
#define T_DARK_WHITE	 7	// Dark White
#define T_DARK_GRAY		 8	// Dark Gray
#define T_BRIGHT_BLUE	 9	// Bright Blue
#define T_BRIGHT_GREEN   10	// Bright Green
#define T_BRIGHT_RED	 12	// Bright Red
#define T_BRIGHT_CYAN	 11	// Bright Cyan
#define T_BRIGHT_MAGENTA 13	// Bright Magenta
#define T_BRIGHT_YELLOW  14	// Bright Yellow
#define T_BRIGHT_WHITE   15	// Bright White

// Usage:
//	Color.SetColor( T_BRIGHT_YELLOW );
//	std::cout << "Hello World" << std::endl;
//	Color.RestoreDefaultConsoleTextColor();
class ColorizeConsole {

public:
	ColorizeConsole( ) {
		GetDefaultConsoleColor( );
		SetDefaultConsoleColor( OriginalConsoleTextColor );
	}

	~ColorizeConsole( ) {
		RestoreDefaultConsoleTextColor( );
	}

	// Set the foreground text of the system console 
	inline void SetColor( int color ) {
		HANDLE  hConsole;
		hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
		SetConsoleTextAttribute( hConsole , color );
	}

	// Display our possible color combinations, TestAllColors changes the background and foreground of the text
	inline void TestAllColors( ) {
		HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
		for ( int i = 0; i < 255; ++i ) {
			SetConsoleTextAttribute( hConsole , i );
			std::cout << i << " Hello World." << std::endl;
		}
	}

	// Reset the console foreground text colors to default value before launching the program
	inline void RestoreDefaultConsoleTextColor( ) {
		HANDLE m_hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
		SetConsoleTextAttribute( m_hConsole , OriginalConsoleTextColor );
	}

private:

	// Get the default color upon execution of the program
	inline WORD GetDefaultConsoleColor( ) {
		HANDLE ConsoleHandle;
		CONSOLE_SCREEN_BUFFER_INFO ConsoleBufferInfo;

		//retrieve and save the current attributes
		ConsoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
		if ( GetConsoleScreenBufferInfo( ConsoleHandle , &ConsoleBufferInfo ) ) {
			SetDefaultConsoleColor( ConsoleBufferInfo.wAttributes );
		}
		return ConsoleBufferInfo.wAttributes;
	}

	// Set the default console color
	inline void SetDefaultConsoleColor( WORD DefaultColor ) {
		if ( DefaultColor >= ( WORD ) 0 && DefaultColor <= ( WORD ) 255 )
			OriginalConsoleTextColor = DefaultColor;
	}

	// 16 bit unsigned integer, that will hold the original color when the program is launched.
	WORD OriginalConsoleTextColor;
};
