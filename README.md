# log4ahk

#### description
* print log to console
* print log to file
* print log to editor (vscode ...)

### install
* Drag lib from the V1 or V2 file directory to the interpreter directory (C:\Program Files\AutoHotkey)

#### example
```
#include <log4ahk>

s1 := "100"
s2 := 100
s3 := "autohotkey"
s4 := {key : "nice"}
;info warn critical err
log.info(s1, s2, s3, s4)
log.warn(s1, s2, s3, s4)
log.err(s1, s2, s3, s4)
log.critical(s1, s2, s3, s4)

;v1
;hotkey,#c, log4ahk_switch_console
;v2
;hotkey("#c", log4ahk_switch_console)
```
## result
![log4ahk](/pic/log4ahk.PNG)

## settings
* 如果要输出到vscode 的终端
  log.is_use_editor := true
* 如果要输出到文件
  log.is_out_file := true
* 如果关闭终端输出
  log.is_out_console := false