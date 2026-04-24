# CENG302 IPC Project Repository

Bu repo CENG302 kapsaminda IPC (Inter-Process Communication) odakli ekip calismasi icin hazirlandi.

## Ekip ve Branch Dagilimi

- `feature/pipe` -> 1. kisi (Named Pipe / FIFO tarafi)
- `feature/shm` -> 2. kisi (POSIX Shared Memory + Semaphore tarafi)
- `feature/test-report` -> 3. kisi (test otomasyonu, raporlama, test ciktisi)

## Kisiye Gore Gorev Plani

1. 1. kisi
	Pipe/FIFO tarafindaki implementasyonu kendi branch'inde gelistirir.
	Calisacagi branch: `feature/pipe`
2. 2. kisi
	Shared Memory + Semaphore tarafindaki implementasyonu kendi branch'inde gelistirir.
	Calisacagi branch: `feature/shm`
3. 3. kisi
	Test scripti calistirma, test ciktilarini toplama ve raporlama islerini yurutur.
	Calisacagi branch: `feature/test-report`

Kural: Herkes sadece kendi branch'inde calisir, dogrudan `main` branch'ine kod yazmaz.

## Dizin Yapisi

```
CENG302/
|- test/
|  |- data/
|  `- test-report/
|- scripts/
|- docs/
|- README.md
`- .gitignore
```

## Gelistirme Akisi

1. `main` branch'inden guncel alin.
2. Kendi feature branch'inizde gelistirme yapin.
3. Kucuk ve anlamli commit'ler atin.
4. Testlerinizi calistirin.
5. Pull Request ile `main` branch'ine birlestirin.

## Branch'lerde Calisma Rehberi

### 1) Branch'e gecme

Asagidaki komutlarla kendi branch'inize gecin:

- `git checkout feature/pipe`
- `git checkout feature/shm`
- `git checkout feature/test-report`

### 2) Main'den guncel alma

Kendi branch'inizdeyken:

1. `git fetch origin`
2. `git merge origin/main`

Not: Catisma olursa dosyalari duzeltip yeniden commit atiniz.

### 3) Gunluk calisma dongusu

1. Degisiklik yap
2. `git add .`
3. `git commit -m "anlamli mesaj"`
4. `git push -u origin <kendi-branchin>`

Ornek push komutlari:

- `git push -u origin feature/pipe`
- `git push -u origin feature/shm`
- `git push -u origin feature/test-report`

## Pull Request (PR) Nasil Acilir?

### GitHub uzerinden adim adim

1. Kendi branch'inizi remote'a push edin.
2. GitHub repo sayfasina girin.
3. `Compare & pull request` butonuna basin.
4. Base branch: `main`, compare branch: kendi feature branch'iniz secili olsun.
5. PR basligini ve aciklamasini net yazin.
6. `Create pull request` ile PR'i acin.

### PR baslik ornekleri

- `feature/pipe: fifo veri akis implementasyonu`
- `feature/shm: shared memory + semaphore implementasyonu`
- `feature/test-report: test raporu ve script ciktisi eklendi`

### PR aciklama sablonu (onerilen)

1. Yapilan degisiklikler
2. Neden gerekliydi
3. Test adimlari
4. Beklenen cikti
5. Varsa bilinen kisitlar

### PR birlestirme kurali

- Dogrudan push yok, sadece PR ile merge.
- En az 1 kisi tarafindan gozden gecirme yapilsin.
- Mergedikten sonra herkes kendi branch'ine tekrar `main` guncelini alsin.

## CI/CD Otomasyonu

Bu repoda PR ve merge surecini otomatiklestiren GitHub Actions tanimlari vardir:

- `.github/workflows/pr-ci.yml`
	- PR acildiginda branch adini dogrular
	- Zorunlu dosyalarin varligini kontrol eder
	- Placeholder kaynak dosya varsa derleme/test adimini skip eder
	- Gercek implementasyon varsa `scripts/test_script.sh` calistirir

- `.github/workflows/main-ci.yml`
	- `main` branch'e push sonrasi sozlesme kontrolu yapar
	- Kaynaklar placeholder degilse test scriptini calistirir

- `.github/workflows/pr-labeler.yml` + `.github/labeler.yml`
	- Degisen dosyalara gore PR'e otomatik label ekler (`pipe`, `shm`, `test-report`, `documentation`)

- `.github/pull_request_template.md`
	- Her PR icin standart aciklama/checklist sunar

## Beklenen Kaynak Dosyalari

Asagidaki dosyalar proje tesliminde beklenmektedir:

- `myData_pipe.c`
- `myMore_pipe.c`
- `myData_shm.c`
- `myMore_shm.c`

Not: Test scripti bu dosya adlarini birebir arar. Dosya adlarini degistirmeyin.
Bu dosyalar su an placeholder olarak acilmistir; icerik implementasyonu ekip tarafindan yazilacaktir.

## Script Sozlesmesi (Degistirilmeyecek)

`scripts/test_script.sh` sabit kabul edilir. Dolayisiyla proje scriptin bekledigi dosya yerlesimine uymak zorundadir.

Script root dizinde su dosyalari arar:

- `myData_pipe.c`
- `myMore_pipe.c`
- `myData_shm.c`
- `myMore_shm.c`
- `web_server_logs.txt`
- `db_server_logs.txt`

Detayli protokol: `docs/test-protocol.md`

## Test Varliklari

- Otomasyon scripti: `scripts/test_script.sh`
- Log fixture dosyalari:
	- `test/data/web_server_logs.txt`
	- `test/data/db_server_logs.txt`
- Script uyumlulugu icin root kopyalari:
	- `web_server_logs.txt`
	- `db_server_logs.txt`
- Rapor klasoru: `test/test-report/`

## Hizli Baslangic

1. Branch'iniza gecin:
	 - `git checkout feature/pipe`
	 - `git checkout feature/shm`
	 - `git checkout feature/test-report`
2. `git fetch origin` ile uzak degisiklikleri alin.
3. `git merge origin/main` ile branch'inizi guncelleyin.
4. Kodunuzu tamamlayin.
5. Test scriptini calistirin (detay: `scripts/README.md`).
6. Sonuclari `test/test-report/` altina koyun.
7. Commit + push yapin.
8. GitHub uzerinden PR acin.

## Dikkat Edilecek Noktalar

- Kod standartlari ve dokumantasyon notlari icin `docs/` klasorunu kullanin.
- Test raporlarinda kullanilan komutlari, tarih/saat bilgisini ve basari/basarisizlik durumunu acik yazin.
- Gereksiz binary dosyalari repoya eklemeyin.
