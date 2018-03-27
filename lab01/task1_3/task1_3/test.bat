rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ����������� ������ �������
%PROGRAM% matrix1.txt > %TEMP%\matrix1.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\matrix1.txt matrix1_output.txt
if ERRORLEVEL 1 goto err

rem ����������� ������ �������
%PROGRAM% matrix2.txt > %TEMP%\matrix2.txt 
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\matrix2.txt matrix2_output.txt
if ERRORLEVEL 1 goto err

rem ������� ��������� ��� ������ ��� �������������� �������, ������������ ������� ����� ����
%PROGRAM% matrix3.txt > %TEMP%\matrix3.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\matrix3.txt matrix3_output.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1