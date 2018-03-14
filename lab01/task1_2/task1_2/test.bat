rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��������� ��������� ����� 0 (�������� ��� �� ��������� ����� �������� ������������)
%PROGRAM% number_zero.txt %TEMP%\number_zero.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\number_zero.txt number_zero.txt
if ERRORLEVEL 1 goto err

rem ��������� ��������� ����� 1
%PROGRAM% number_one_input.txt %TEMP%\number_one.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\number_one.txt number_one_output.txt
if ERRORLEVEL 1 goto err

rem ��������� ��������� ����� 6
%PROGRAM% number_six_input.txt %TEMP%\number_six.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\number_six.txt number_six_output.txt
if ERRORLEVEL 1 goto err

rem ��������� ��������� ����� 255
%PROGRAM% number_255.txt %TEMP%\number_255.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\number_255.txt number_255.txt
if ERRORLEVEL 1 goto err

rem ������� ��������� ��� ������ ��� ���������� ����� �� ��������� � ��������
%PROGRAM% not_in_range_input.txt %TEMP%\not_in_range_input.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\not_in_range_input.txt not_in_range_output.txt
if ERRORLEVEL 1 goto err

rem ������� ��������� ��� ������ ��� ���������� ������, ������� �� ����� ���� ������
%PROGRAM% can_not_be_number_input.txt %TEMP%\can_not_be_number_input.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\can_not_be_number_input.txt can_not_be_number_output.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1