# QT_AGILE_DEVELOPMENT

Если возникнет желание собрать проект, не забудьте прописать в additional include directories папку include

## Добавление компилятора

Инструменты-параметры-инструментарий: 
![QT_STATIC_DESCRIPTOR_COMPILER_PREFERENCES](QT_COMPILER_PREFERENCES.PNG)
Желтым выделен путь до [желаемого компилятора](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/6.3.0/)

Вкладка проекты слева:
![QT_STATIC_DESCRIPTOR_PROJECT_SETTINGS](QT_PROJECT_SETTINGS.PNG)
Желтым выделено имя, под которым компилер зарегистрирован в метаметаметакомпилере QT (см. пред.)

## Добавление версии qt

[QT 4.8.6](https://download.qt.io/archive/qt/4.8/4.8.6/qt-opensource-windows-x86-mingw482-4.8.6-1.exe)
![QT_STATIC_DESCRIPTOR][QT_VERSION_SETTINGS.PNG]

В настройках проекта ее и выбираем с теми же настройками компилера, что в предыдущем пункте

