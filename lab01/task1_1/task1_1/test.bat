rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"

rem провер€ем копирование пустого файла (копируем его во временную папку текущего пользовател€)
%PROGRAM% empty.txt %TEMP%\empty.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty.txt empty.txt
if ERRORLEVEL 1 goto err

rem провер€ем копирование файла из одной строки
%PROGRAM% one_line.txt %TEMP%\one_line.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\one_line.txt one_line.txt
if ERRORLEVEL 1 goto err

rem провер€ем копирование файла из нескольких строк
%PROGRAM% lines.txt %TEMP%\lines.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\lines.txt lines.txt
if ERRORLEVEL 1 goto err

rem ожидаем ненулевой код ошибки при копировании несуществующего файла
%PROGRAM% non_existing_file_name.txt %TEMP%\non_existing_file_name.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" expected_output_when_input_file_is_missing.txt
if ERRORLEVEL 1 goto err

rem ожидаем ненулевой код ошибки при невозможности записи в выходной файл (в исполн€емый файл программы)
%PROGRAM% lines.txt %PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1