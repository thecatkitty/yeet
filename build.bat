@echo off

:compile
if not exist out goto nooutdir
if not exist obj goto noobjdir
cl /nologo /Iinc /Foobj\ src/*.c /Feout\yeet.exe
goto end

:nooutdir
mkdir out
goto compile

:noobjdir
mkdir obj
goto compile

:end
