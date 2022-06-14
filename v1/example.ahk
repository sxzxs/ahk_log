#include <log>
log.is_out_console := true
log.is_out_file := true
log.is_use_editor := false
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

log.set_pattern("[%=8l] %^%v%$   (%ius)")
loop,% 100
{
    log.info("ok")
}


return

;一些配置
;log.is_out_file := true  ;打开输出到文件
;log.is_out_console := false  ;关闭输出到终端
;log.file := true ;打印文件名字