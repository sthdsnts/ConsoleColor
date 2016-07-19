# ConsoleColor

Easy to use class for changing the foreground text color of windows console output.

Tested with MSVC 2013 & 2015 for C++.

Usage:

  ColorizeConsole Color;

  Color.SetColor( T_BRIGHT_YELLOW );
  
  std::cout << "Hello World" << std::endl;
  
  Color.RestoreDefaultConsoleTextColor();
