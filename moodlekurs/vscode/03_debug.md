Nachdem wir jetzt per Tastendruck ein Programm bauen können, möchten wir es natürlich auch einfach per Tastendruck laufen lassen können. Dazu können Sie in Visual Studio Code einfach die Taste `F5` drücken. Dazu müssen vorher ein paar Schritte erledigt werden.

## 1. launch.json Datei erstellen

Es erscheint nun ein Auswahlmenü. Dort Wählen Sie die Option mit `GDB/LLDB`. `GDB` ist unser Debugger. Dies ist, wie der Compiler auch, ein eigenständiges Programm auf der Festplatte.

Danach möchte Visual Studio Code eine Konfiguration. Wählen Sie hier `gcc.exe - Aktive Datei erstellen und debuggen`. Dies erstellt nun eine Vorlage im `JSON` format. `JSON` steht für *Java Script Object Notation* und ist ein beliebtes Format, um Daten zu strukturieren.

![Start Debug First Time](https://raw.githubusercontent.com/apazureck/Info1Praktikum/master/moodlekurs/vscode/start_debug_first_time.gif)

Die Datei sollte in etwa so aussehen:

```jsonc
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc.exe - Aktive Datei erstellen und debuggen",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\ProgramData\\chocolatey\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Automatische Strukturierung und Einrückung für \"gdb\" aktivieren",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "gcc.exe build active file"
        }
    ]
}
```

In dieser Datei gibt es zwei wichtige Einträge:

1. `"program": "${fileDirname}\\${fileBasenameNoExtension}.exe"` - Hier sagen Sie Visual Studio Code, welches Programm unser Debuger (`gdb`) ausführen soll. Nämlich unsere erstellte `.exe` Datei. Um immer die aktuelle Datei zu starten kann man in Visual Studio Code sogenannte Variablen übergeben. In diesem Fall der Ordnername `${fileDirname}` und der Dateiname `${fileBasenameNoExtension}` ohne die Endung `.c`, denn Sie wollen ja die `.exe` starten und nicht ihre Quelldatei.
2. `"preLaunchTask": "gcc.exe build active file"` - Hier können Sie einen Task angeben, der ausgeführt werden soll, bevor der Debugger startet. Dieser soll dann das Programm jedes mal neu kompilieren, damit Sie auch immer die passende Executable zu Ihrem Quelltext in der `.c` Datei bekommen.

Wählen Sie nun ihre `main.c` Datei im Editor aus und drücken Sie erneut `F5`. Nun sollte eine Fehlermeldung erscheinen.

![Start Debug Fails](https://raw.githubusercontent.com/apazureck/Info1Praktikum/master/moodlekurs/vscode/start_debug_fails.gif)

## 2. tasks.json erstellen

Dieser Fehler kommt daher, dass es noch keine `task.json` mit einem Task gibt, der den Namen des Prelaunch Tasks `"gcc.exe build active file"` hat. Diesen können Sie erstellen, indem Sie auf *Configure Task* klicken. Danach können Sie auch hier eine Vorlage auswählen. In diesem Fall `C / C++: gcc.exe build active file`.

![Create Task](https://raw.githubusercontent.com/apazureck/Info1Praktikum/master/moodlekurs/vscode/create_task.json.gif)

> **Hinweis**: Wenn Sie eine leere `tasks.json` Datei erhalten, dann löschen Sie diese und erstellen sie neu.

Nun erhalten Sie folgende Vorlage:

```jsonc
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "shell",
			"label": "C/C++: gcc.exe build active file",
			"command": "C:\\ProgramData\\chocolatey\\bin\\gcc.exe",
			"args": [
				"-g",
				"${file}",
				"-o",
				"${fileDirname}\\${fileBasenameNoExtension}.exe"
			],
			"options": {
				"cwd": "C:\\ProgramData\\chocolatey\\bin"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build"
		}
	]
}
```

Wenn Sie nun noch einmal `F5` drücken, so werden Sie noch einmal eine Fehlermeldung erhalten, dass der Task `"gcc.exe build active file"` nicht gefunden wurde. Dies liegt daran, dass Visual Studio Code in der `tasks.json` nach einem Task mit dem entsprechenden `label` Eintrag sucht. Wenn Sie die `tasks.json` Datei öffnen und nach dem `label` des Tasks schauen, werden Sie feststellen, dass dieses mit `C/C++: ` beginnt. Löschen Sie einfach das `C/C++`, speichern Sie die Datei mit `STRG + S` und Ihr Programm kann mit `F5` gestartet werden.

![Run OK](https://raw.githubusercontent.com/apazureck/Info1Praktikum/master/moodlekurs/vscode/run_ok.gif)

Nun sollte auf Ihrer Konsole die `printf` Funktion `Hello World` ausgeben.