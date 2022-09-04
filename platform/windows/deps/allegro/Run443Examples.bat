
set SCRIPT_HOME=%~dp0

set path=%SCRIPT_HOME%\bin\dlls;%PATH%

cd /d %SCRIPT_HOME%\bin\examples

title Allegro 4.4.3 Examples Environment

color 0a

doskey showhelp=%SCRIPT_HOME%\ShowHelp.bat

doskey home=cd /d %SCRIPT_HOME%

doskey examples=cd /d %SCRIPT_HOME%\bin\examples

doskey htmldocs=start %SCRIPT_HOME%\docs\allegro\html\index.html

doskey chmdocs=start %SCRIPT_HOME%\docs\allegro\chm\Allegro4_4_3_Manual.chm

cls

call %SCRIPT_HOME%\ShowHelp.bat

cmd.exe

goto :eof
