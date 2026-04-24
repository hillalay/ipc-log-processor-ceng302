# scripts

Bu klasor yardimci otomasyon scriptleri icindir.

## Mevcut Script

- `test_script.sh`: Pipe ve SHM uygulamalarini derler, zorunlu anahtar kelime kontrollerini yapar ve temel calisma senaryosunu test eder.

Bu script referans test olarak sabit kabul edilir; script degistirmek yerine proje yerlesimi ve kod script beklentilerine uydurulmalidir.

## Script'in Kontrol Ettigi Fonksiyonlar

- Thread: `pthread_create`
- Pipe: `mkfifo`, `pthread_mutex_lock`
- SHM: `shm_open`, `mmap`, `sem_wait`

## Onemli Varsayimlar

`test_script.sh` su varsayimlarla yazilmistir:

1. C kaynak dosyalari script ile ayni calisma dizininde bulunur.
2. Dosya adlari su sekilde birebir olmalidir:
	- `myData_pipe.c`
	- `myMore_pipe.c`
	- `myData_shm.c`
	- `myMore_shm.c`
3. Log dosyalari calisma dizininde su adlarla bulunur:
	- `web_server_logs.txt`
	- `db_server_logs.txt`

## Kullanim Onerisi

- Scripti calistirmadan once kaynak kod ve log dosyalarinin ayni dizinde oldugundan emin olun.
- Sonuclari `test/test-report/` altinda raporlayin.

## Not

Windows ortaminda `.sh` scriptlerini calistirmak icin Git Bash, WSL veya benzeri bir Bash ortami gerekebilir.

Ek olarak bu proje POSIX API'lerine (`pthread.h`, `semaphore.h`, `shm_open`) dayandigi icin Linux/WSL ortami tavsiye edilir.
Standart MinGW kurulumlarinda bu basliklar veya baglama kutuphaneleri eksik olabilir.
