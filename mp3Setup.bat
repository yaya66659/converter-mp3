@echo off

REM active l'expention defferée des variable 

setlocal enabledelayedexpansion

echo Verifiquation de python...


where python >nul 2>&1
if %errorlevel%==0 (
    echo Python est installe. [python]
    python --version
    goto :end
)

where py >nul 2>&1
if %errorlevel%==0 (
    echo Python est installe. [py]
    py --version
    goto :end
)

echo Python n'est PAS installe sur ce systeme.
echo Telechargez-le depuis : https://www.python.org/downloads/

:end
pause

REM verifie si ffmpeg est dans PATH
where ffmpeg >nul 2>&1

IF %ERRORLEVEL% NEQ 0 (
    echo .
    echo ffmpegf est n'essentiel au fonctionement de la comande :
    echo   > mp3 
    echo Souhaitez-vous le téeecharger et l'installer maintenant ? [O/N]
    set /p choix="> "
    set "choix=%choix: =%"

    if /I "%choix%"=="O" (
        echo.
        echo Téléchargement de FFMPEG...
        powershell -Command "Invoke-WebRequest https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.zip -OutFile ffmpeg.zip"
         echo Extraction de FFMPEG...
        powershell -Command "Expand-Archive -Path ffmpeg.zip -DestinationPath . -Force"

        for /d %%i in (ffmpeg-*) do set "ffmpegDir=%%i"
        set "ffmpegPath=%cd%\!ffmpegDir!\bin"    
         
        echo Ajout temporaire de FFMPEG au PATH pour cette session...
        setx "PATH=!ffmpegPath!;!PATH!"

        echo FFMPEG installé localement avec succès.
    ) else (
        echo L'installation est annulée. FFMPEG est requis pour continuer.
        pause
        exit /b
    ) 
)


REM change le titre de la fenetre de commandfe
title Configuration de l'environement audio

REM definir le dossier ouis se trouve le .bat
set "SCRIPT_DIR=%~dp0"

REM 1. definire le chemin cible
set "TARGET_DIR=C:\CMDmp3"

REM 2. crée le dossier ci il existe pas

if not exist "%TARGET_DIR%" (

        mkdir "%TARGET_DIR%"
)

REM 3. copier l'executable
copy "%SCRIPT_DIR%\bin\mp3.exe" "%TARGET_DIR%"

REM  4. verifier si le dossier est daja dans PATH

echo %PATH% | find /I "%TARGET_DIR%" >nul
if errorlevel 1 (
   REM Récupère la variable d'environnement existante
    for /f "tokens=2* delims=    " %%A in ('reg query "HKCU\Environment" /v PATH 2^>nul') do set "UserPath=%%B"
    
    if not defined UserPath (
        set "UserPath=%TARGET_DIR%"
    ) else (
        set "UserPath=%UserPath%;%TARGET_DIR%"
    )

    REM Applique le nouveau PATH
    setx PATH "!UserPath!"
    echo.
    echo ✅ Le chemin "%TARGET_DIR%" a été ajouté au PATH.
    echo 🔁 Veuillez ouvrir un nouveau terminal pour que le ch  angement prenne effet.

    
)
echo.

echo "installation terminée  !"

pause

