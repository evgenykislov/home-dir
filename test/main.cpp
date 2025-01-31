/*
MIT License

Copyright (c) 2024 Evgeny Kislov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>

#include "home-dir.h"


int main()
{
  std::cout << "Home directory: '" << HomeDirLibrary::GetHomeDir() << "'" << std::endl;
  std::cout << "Local application data directory: '" << HomeDirLibrary::GetDataDir() << "'" << std::endl;

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
  std::wcout << "Windows wide paths:" << std::endl;
  std::wcout << "Wide Home directory: '" << HomeDirLibrary::GetHomeDirW() << "'" << std::endl;
  std::wcout << "Wide Local application data directory: '" << HomeDirLibrary::GetDataDirW() << "'" << std::endl;
#endif

  return 0;
}
