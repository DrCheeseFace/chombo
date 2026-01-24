[Setup]
AppName=Chombo
AppVersion=1.1.0
AppPublisher=Tharun
DefaultDirName={autopf}\Chombo
DefaultGroupName=Chombo

Compression=lzma2/max
SolidCompression=yes
OutputDir=user_installer
OutputBaseFilename=ChomboSetup

ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64

[Files]
Source: "chombo.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "assets\*"; DestDir: "{app}\assets"; Flags: ignoreversion recursesubdirs

[Icons]
Name: "{group}\Chombo"; Filename: "{app}\chombo.exe"
Name: "{commondesktop}\Chombo"; Filename: "{app}\chombo.exe"; Tasks: desktopicon

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Run]
Filename: "{app}\chombo.exe"; Description: "{cm:LaunchProgram,Chombo}"; Flags: nowait postinstall skipifsilent
