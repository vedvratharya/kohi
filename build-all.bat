@echo OFF
REM Build Everything

echo "Building everything..."

pushd engine
call build.bat
popd
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

pushd testbed
call build.bat
popd
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

echo "All assemblies built successfully."