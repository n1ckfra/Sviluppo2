#!/usr/bin/env bash
rm -rf ImmaginiJPG
rm -rf ImmaginiPNG
rm -rf AltriFile
touch alpha.jpg beta.jpg gamma.PNG pinco.png PALLINO.jPG delta.JPG cane.Jpg Gatto.pnG testo.txt prova.doc ciao.sh
read
for f in *.*; do
      case $f in
      $(basename $0))
            ;;
      *.[Jj][Pp][Gg])
            mkdir ImmaginiJPG 2>/dev/null
            mv $f ImmaginiJPG
            ;;
      *.[Pp][Nn][Gg])
            mkdir ImmaginiPNG 2>/dev/null
            mv $f ImmaginiPNG
            ;;
      *)
            mkdir AltriFile 2>/dev/null
            mv $f AltriFile
            ;;
    esac
done