# 🎵 Converter MP3

> Une commande console pour convertir rapidement des fichiers audio/vidéo en MP3 à l’aide de `ffmpeg`, codée en C pour Windows.

---

## [>]  Telechargement :

[CMDmp3](https://drive.google.com/file/d/1RCoZLyLohY17O72PsQJ1hkWmipZXt_LQ/view?usp=sharing)

## 📦 Description

**Converter MP3** est une commande personnalisée appelée `mp3`, qui permet de :

- 🎧 Convertir un fichier audio en `.mp3`
- 🎥 Extraire l’audio d’un fichier vidéo vers `.mp3`
- 🐞 Activer un mode `debug` pour afficher des infos techniques
- 📘 Afficher un manuel d’utilisation

---

## 🛠️ Technologies utilisées

- Langage C (standard C89/C99)
- ffmpeg (outil externe indispensable)
- Windows CMD
- Script d'installation `.bat`

---

## 🚀 
- Exécutez le script `mp3Setup.bat` (clic droit → Exécuter en tant qu’administrateur).

💾 Un installateur `mp3Setup.bat` est inclus pour ajouter automatiquement la commande `mp3` au **PATH système Windows**, facilitant son utilisation depuis n’importe quel terminal.

---

## 🧪 Utilisation

```bash
mp3 chemin/vers/fichier.ext
```

Mode debug :

```bash
mp3 chemin/vers/fichier.ext -debug
```

---

## 🖼️ Exemple

```bash
mp3 musique.wav
# => Convertit musique.wav en musique.mp3

mp3 film.mp4
# => Extrait l’audio du film.mp4 vers film.mp3
```

---

## 📂 Arborescence

```
Converter_MP3/
├── bin/
├── headers/
│   └── fct.h
├── obj/
├── src/
│   ├── fct.c
│   └── main.c
├── Makefile
└── mp3Setup.bat
```

---

## 👤 Auteur

Développé par **Yann Pichat**  
Contact : *à personnaliser*

---

## 📝 Licence

Ce projet est **open-source**, mais il est **interdit de l’utiliser à des fins commerciales**.

Vous êtes libre de :
- l’utiliser,
- le modifier,
- le partager,
- l’étudier,

**tant que cela reste dans un cadre personnel, éducatif ou non commercial.**

➡️ Pour toute utilisation commerciale, une autorisation écrite de l’auteur est requise.

© Yann Pichat – 2025
