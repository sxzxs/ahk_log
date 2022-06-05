# log4ahk

#### description
* print log to console
* print log to file
* print log to editor (vscode ...)
* support 6 level log

### install
* Drag lib from the V1 or V2 file directory to the interpreter directory (C:\Program Files\AutoHotkey)

#### v1 example
```
#include <log>
log.is_out_console := true
log.is_out_file := true
log.is_use_editor := true
log.level := log.level_debug
s1 := "100"
s2 := 100
s3 := "autohotkey"
s4 := {key : "nice"}
log.debug("debug")
log.trace("trace")
log.info(s1, s2, s3, s4) ;多个参数通过 "," 连接
log.warn(s1, s2, s3, s4)
log.err(s1, s2, s3, s4)
log.critical(s1, s2, s3, s4)
return


```

### v2 example

```
logger.is_out_file := true 
;logger.is_use_editor := false

logger.level := logger.level_trace
logger.debug("debug")
logger.trace("trace")

s1 := "100"
s2 := 100
s3 := "autohotkey"
s4 := map("key", "nice")
obj := {key : "value"}
logger.info(obj)
;info warn critical err
logger.info(s1, s2, s3, s4)
logger.warn(s1, s2, s3, s4)
logger.err(s1, s2, s3, s4)
logger.critical(s1, s2, s3, s4)
loop(100)
    logger.info(A_index)
logger.info(Log('10'))

#include <log>
```
## result
![log4ahk](/pic/log4ahk.PNG)