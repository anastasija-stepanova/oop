rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"

rem инвертируем первую матрицу
%PROGRAM% matrix1.txt > %TEMP%\matrix1.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\matrix1.txt matrix1_output.txt
if ERRORLEVEL 1 goto err

rem инвертируем вторую матрицу
%PROGRAM% matrix2.txt > %TEMP%\matrix2.txt 
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\matrix2.txt matrix2_output.txt
if ERRORLEVEL 1 goto err

rem ожидаем ненулевой код ошибки при инвертировании матрицы, определитель которой равен нулю
%PROGRAM% matrix3.txt > %TEMP%\matrix3.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\matrix3.txt matrix3_output.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1