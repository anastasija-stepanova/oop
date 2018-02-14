rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��������� ����������� ������� ����� (�������� ��� �� ��������� ����� �������� ������������)
%PROGRAM% empty.txt %TEMP%\empty.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty.txt empty.txt
if ERRORLEVEL 1 goto err

rem ��������� ����������� ����� �� ����� ������
%PROGRAM% one_line.txt %TEMP%\one_line.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\one_line.txt one_line.txt
if ERRORLEVEL 1 goto err

rem ��������� ����������� ����� �� ���������� �����
%PROGRAM% lines.txt %TEMP%\lines.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\lines.txt lines.txt
if ERRORLEVEL 1 goto err

rem ������� ��������� ��� ������ ��� ����������� ��������������� �����
%PROGRAM% non_existing_file_name.txt %TEMP%\non_existing_file_name.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" expected_output_when_input_file_is_missing.txt
if ERRORLEVEL 1 goto err

rem ������� ��������� ��� ������ ��� ������������� ������ � �������� ���� (� ����������� ���� ���������)
%PROGRAM% lines.txt %PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1