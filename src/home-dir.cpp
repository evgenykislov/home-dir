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

// Detect platform
#if defined(linux) || defined(__linux) || defined(__linux__)
#define LINUX_PLATFORM
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define WINDOWS_PLATFORM
#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#define MACOS_PLATFORM
#else
#error Unknown platform
#endif

#include "home-dir.h"

// --------------------------
// Linux implementation
// --------------------------

#ifdef LINUX_PLATFORM

#include <string>

#include <pwd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

const char kHomeEnvVar[] = "HOME";

std::string HomeDirLibrary::GetHomeDirectory() {
  try {
    auto ev = getenv(kHomeEnvVar);
    if (ev) {
      return std::string(ev);
    }
    auto pw = getpwuid(getuid());
    if (pw) {
      return std::string(pw->pw_dir);
    }
  } catch (std::exception) {
  }

  return std::string();
}

#endif


// --------------------------
// Windows implementation
// --------------------------

#ifdef WINDOWS_PLATFORM

#include <windows.h>
#include <shlobj.h>

std::string HomeDirLibrary::GetHomeDirectory() {
  try {
    CHAR profile[MAX_PATH];
    if (SHGetFolderPathA(nullptr, CSIDL_PROFILE, nullptr, 0, profile)!= S_OK) {
      // Error occured
      return std::string();
    }
    return std::string(profile);
  } catch (std::exception) {
  }
  return std::string();
}


std::wstring HomeDirLibrary::GetHomeDirectoryW() {
  try {
    WCHAR profile[MAX_PATH];
    if (SHGetFolderPathW(nullptr, CSIDL_PROFILE, nullptr, 0, profile)!= S_OK) {
      // Error occured
      return std::wstring();
    }
    return std::wstring(profile);
  } catch (std::exception) {
  }
  return std::wstring();
}

#endif
