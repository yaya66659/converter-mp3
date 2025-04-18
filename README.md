# 🎵 Converter MP3

> Une commande console simple et rapide pour convertir des fichiers audio/vidéo en MP3, ou compresser des vidéos, grâce à `ffmpeg` — codée en C pour Windows.
> Ce projet utilise ffmpeg comme outil externe. ffmpeg est un projet open-source sous licence LGPL/GPL. Pour plus d’informations, visitez : https://ffmpeg.org



---

## [>]  Telechargement :

[CMDmp3](https://drive.google.com/file/d/1RCoZLyLohY17O72PsQJ1hkWmipZXt_LQ/view?usp=sharing)

## 📦 Description

**Converter MP3** est une commande personnalisée nommée `mp3`, pensée pour simplifier l’usage de `ffmpeg` via le terminal Windows. Elle permet de :

- 🎧 Convertir un **fichier audio** en `.mp3`
- 🎥 Extraire l’audio d’un **fichier vidéo** en `.mp3`
- 🗜️ Compresser une **vidéo** avec une nouvelle version suffixée `_Compressee.mp4`
- 🐞 Activer un **mode debug** pour afficher les détails internes
- 📘 Consulter un **manuel d’utilisation** intégré
- 🛠️ Installer automatiquement `mp3` dans le **PATH système** via `mp3Setup.bat`

---

## 🛠️ Technologies utilisées

- Langage **C**
- Bibliothèque externe : [`ffmpeg`](https://ffmpeg.org/)
- CMD / terminal Windows
- Script batch : `mp3Setup.bat`

---

## 🚀 Installation

1. Exécutez le script d'installation :
   ```bash
   mp3Setup.bat
   ```
   (clic droit → *Exécuter en tant qu’administrateur*)
=======
## 🚀 
- Exécutez le script `mp3Setup.bat` (clic droit → Exécuter en tant qu’administrateur).
>>>>>>> ac1d3f8044b42c7d60afa115571f20c6f943c853

📌 Ce script ajoute `mp3.exe` automatiquement au `PATH` système pour permettre l'exécution depuis n’importe quel dossier.

2. Assurez-vous que `ffmpeg` est installé et accessible depuis votre terminal :
   ```bash
   ffmpeg -version
   ```

📌**'mp3Setup.bat'** installe et ajoute `ffmpeg` automatiquement au `PATH` système pour permettre l'exécution depuis n’importe quel dossier.
---

## 🧪 Utilisation

### ▶️ Conversion audio ou extraction audio :

```bash
mp3 chemin/vers/fichier.ext
```

- Si le fichier est audio → converti en `.mp3`
- Si le fichier est vidéo → extrait l’audio en `.mp3`

### 🔧 Compression vidéo :

```bash
mp3 chemin/vers/video.ext -c
```

- Produit un nouveau fichier compressé nommé `video_Compressee.mp4`

### 🐞 Mode debug :

```bash
mp3 chemin/vers/fichier.ext -debug
```

- Affiche l’extension, le nom sans extension, le type (audio/vidéo), etc.

### 🔀 Combinaison compression + debug :

```bash
mp3 chemin/vers/video.ext -c -debug
```

---

## 📘 Manuel intégré

En lançant la commande sans arguments, ou avec un argument erroné, le **manuel s’affiche automatiquement**.

```bash
mp3
```

---

## 📂 Arborescence type

```
Converter_MP3/
├── bin/
├── headers/
│   └── fct.h
├── obj/
├── src/
│   ├── fct.c
│   └── main.c
├── mp3Setup.bat
├── README.md
└── Makefile (optionnel)
```

---

## 📸 Exemples

```bash
mp3 ma_musique.wav
# => Convertit ma_musique.wav en ma_musique.mp3

mp3 mon_film.mp4
# => Extrait le son de mon_film.mp4 en mon_film.mp3

mp3 mon_film.mp4 -c
# => Crée une version compressée : mon_film_Compressee.mp4

mp3 ma_musique.wav -debug
# => Affiche les détails techniques

mp3 mon_film.mp4 -c -debug
# => Affiche les détails techniques
```

---

## 👤 Auteur

Développé par **Yann Pichat**  
📧 Contact : yann55446@gmail.com

---

## 📝 Licence

Ce projet est **open-source**, mais il est **interdit de l’utiliser à des fins commerciales**.

Vous êtes libre de :
- l’utiliser,
- le modifier,
- le partager,
- l’étudier,

**Tant que cela reste dans un cadre personnel, éducatif ou non commercial.**

➡️ Pour toute utilisation commerciale, une **autorisation écrite** de l’auteur est requise.

© Yann Pichat – 2025
