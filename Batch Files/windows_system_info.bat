@ECHO OFF

:: This batch file will return Windows 10 system info

TITLE My Windows 10 Info
ECHO =====================
systeminfo | findstr /c:"OS Name"
systeminfo | findstr /c:"OS Version"
systeminfo | findstr /c:"System Type"

PAUSE