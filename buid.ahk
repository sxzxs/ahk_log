#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
#include <log4ahk>
#include <my_lib>
run_as_admin()

log.info(A_ScriptDir)
FileCopyDir, C:\Program Files\AutoHotkey\lib\cmder, %A_ScriptDir%\v1\lib\cmder ,1
FileCopy,C:\Program Files\AutoHotkey\lib\log4ahk.ahk , %A_ScriptDir%\v1\lib , 1
FileCreateDir, %A_ScriptDir%\v1\lib\dll_64
FileCreateDir, %A_ScriptDir%\v1\lib\dll_32
FileCopy,C:\Program Files\AutoHotkey\lib\dll_64\cpp2ahk.dll , %A_ScriptDir%\v1\lib\dll_64 , 1
FileCopy,C:\Program Files\AutoHotkey\lib\dll_32\cpp2ahk.dll , %A_ScriptDir%\v1\lib\dll_32 , 1

FileCreateDir, %A_ScriptDir%\v2\lib\dll_64
FileCreateDir, %A_ScriptDir%\v2\lib\dll_32
FileCopyDir, C:\Program Files\AutoHotkey\lib\cmder, %A_ScriptDir%\v2\lib\cmder ,1
FileCopy,C:\Program Files\AutoHotkey_V2\lib\log4ahk.ahk , %A_ScriptDir%\v2\lib , 1
FileCopy,C:\Program Files\AutoHotkey\lib\dll_64\cpp2ahk.dll , %A_ScriptDir%\v2\lib\dll_64 , 1
FileCopy,C:\Program Files\AutoHotkey\lib\dll_32\cpp2ahk.dll , %A_ScriptDir%\v2\lib\dll_32 , 1

log.info("end")