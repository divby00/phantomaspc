#!/usr/bin/env sh
xgettext -k_ -kN_ -kt_ -ktranslate src/*.c data/scripts/*.lua -o data/locale/phantomaspc.pot
msgmerge -o data/locale/es/LC_MESSAGES/phantomaspc.po data/locale/es/LC_MESSAGES/phantomaspc.po data/locale/phantomaspc.pot
msgfmt data/locale/es/LC_MESSAGES/phantomaspc.po -o data/locale/es/LC_MESSAGES/phantomaspc.mo
