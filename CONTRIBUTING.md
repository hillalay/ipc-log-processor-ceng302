# Contributing Guide

Bu dosya ekip ici calisma kurallarini standartlastirmak icin hazirlanmistir.

## Branch ve Sorumluluk

- 1. kisi: `feature/pipe`
- 2. kisi: `feature/shm`
- 3. kisi: `feature/test-report`

Kural: Herkes yalnizca kendi feature branch'inde calisir.

## Temel Akis

1. Branch'inize gecin.
2. `main` guncelini alin.
3. Degisiklikleri yapin.
4. Testleri calistirin.
5. Commit ve push yapin.
6. PR acin.

## Komut Akisi

1. `git checkout <feature-branch>`
2. `git fetch origin`
3. `git merge origin/main`
4. `git add .`
5. `git commit -m "kisa ve anlamli mesaj"`
6. `git push -u origin <feature-branch>`

## Pull Request Kurallari

- Base branch daima `main` olmalidir.
- PR basligi degisikligi net anlatmalidir.
- PR aciklamasinda test adimlari yazilmalidir.
- Dogrudan `main` branch'ine push yapilmaz.

## CI/CD Kurallari

- PR acildiginda otomatik kontrol calisir (`.github/workflows/pr-ci.yml`).
- Branch adi yalnizca su formatlarda olmali:
	- `feature/pipe`
	- `feature/shm`
	- `feature/test-report`
- Zorunlu dosyalardan biri eksikse PR kontrolu fail olur.
- Kaynak dosyalar placeholder ise derleme/test adimi skip edilir.
- Implementasyon tamamlandiginda ayni CI akisi otomatik derleme/test yapar.
- `main` branch'e merge sonrasi `main-ci` yeniden dogrulama yapar.

## Script Uyumlulugu

`scripts/test_script.sh` degistirilmez.
Proje, scriptin bekledigi dosya adlari ve konumlarina uyumlu olmalidir.

Scriptin root'ta bekledigi dosyalar:

- `myData_pipe.c`
- `myMore_pipe.c`
- `myData_shm.c`
- `myMore_shm.c`
- `web_server_logs.txt`
- `db_server_logs.txt`

## Test ve Raporlama

- Test scripti: `scripts/test_script.sh`
- Log verileri: `test/data/`
- Rapor klasoru: `test/test-report/`

Test sonucu raporlarinda su bilgiler yer almali:

- tarih/saat
- calistirilan komutlar
- sonuc (basarili/basarisiz)
- varsa hata ve cozum notu
