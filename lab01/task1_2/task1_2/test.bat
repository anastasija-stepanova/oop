rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"

rem провер€ем переворот цифры 0 (копируем его во временную папку текущего пользовател€)
%PROGRAM% number_zero.txt %TEMP%\number_zero.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\number_zero.txt number_zero.txt
if ERRORLEVEL 1 goto err

rem провер€ем переворот цифры 1
%PROGRAM% number_one_input.txt %TEMP%\number_one.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\number_one.txt number_one_output.txt
if ERRORLEVEL 1 goto err

rem провер€ем переворот цифры 6
%PROGRAM% number_six_input.txt %TEMP%\number_six.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\number_six.txt number_six_output.txt
if ERRORLEVEL 1 goto err

rem провер€ем переворот числа 255
%PROGRAM% number_255.txt %TEMP%\number_255.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\number_255.txt number_255.txt
if ERRORLEVEL 1 goto err

rem ожидаем ненулевой код ошибки при перевороте числа не вход€щего в диапазон
%PROGRAM% not_in_range_input.txt %TEMP%\not_in_range_input.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\not_in_range_input.txt not_in_range_output.txt
if ERRORLEVEL 1 goto err

rem ожидаем ненулевой код ошибки при перевороте строки, котора€ не может быть числом
%PROGRAM% can_not_be_number_input.txt %TEMP%\can_not_be_number_input.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\can_not_be_number_input.txt can_not_be_number_output.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1