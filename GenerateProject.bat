@ECHO OFF
SET PROJDIR=~dp

CALL UnrealBuildTool -projectfiles -project="%~dp0MyRogue.uproject" -game