;打开输出到文件
logger.is_out_file := true 
;关闭输出到终端
;logger.is_out_console := false 
;打印文件名字
;logger.file := true

;需要输出到编辑器终端时 is_use_editor := true
logger.is_use_editor := false
logger.level := logger.level_trace

logger.debug("debug")
logger.set_pattern(logger.default_patter)
logger.trace("trace")
logger.set_pattern("[%Y-%m-%d %H:%M:%S.%F] [thread %=7t] [%=8l] %^%v%$   (%ius)")
logger.info("patter test")
logger.set_pattern("[%=8l] %^%v%$   (%ius)")
logger.info("patter test")
logger.set_pattern("%^%v%$   (%ius)")
logger.info("patter test")

s1 := "100"
s2 := 100
s3 := "autohotkey"
s4 := map("key", "nice")
obj := {key : "value"}
logger.info(obj)
;多个参数通过 "," 连接
;info warn critical err
logger.info(s1, s2, s3, s4)
logger.warn(s1, s2, s3, s4)
logger.err(s1, s2, s3, s4)
logger.critical(s1, s2, s3, s4)
loop(100)
    logger.info(A_index)
logger.info(Log('10'))
logger.Print("test")

logger.puts("Hello World!")
logger.puts("Hello World!")
name := 0
logger.putsf("`nWelcome %s!", (logger.gets(&Name)=="") ? "User" : Name)
logger.print("jjj")
logger.print("jjj")
#include <log>